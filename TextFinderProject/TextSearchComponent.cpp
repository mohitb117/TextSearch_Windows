/////////////////////////////////////////////////////////////////////
// TextSearchComponent.cpp						                   //
//                                                                 //

/*
		The implementation of the ITextSearchComponent
		which defines the interface for a Typical 
		TextSearch Component within a filesystem.

*/

// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
/////////////////////////////////////////////////////////////////////

# pragma once

# include "TextSearchFactory.h"
# include "FileAnalyzer.h"
# include "InputArgumentParser.h"

# include <future>
# include <map>
#include <ctime>
#include <ratio>
#include <chrono>

using TextComp = AbstractTextSearchComponentReferenceCounted;
using namespace FileSystem;
using FileName = std::string;
using namespace std;
using namespace std::chrono;
std::mutex m_lock;

std::map<std::string, double > fileScannerDurations;

void title1(const std::string& title, char ch = '=')
{
	std::cout << "\n  " << title;
	std::cout << "\n " << std::string(title.size() + 2, ch);
}

double calculateTotalTimeFileAnalysis(Result files)
{
	double total_time_file_analysis_all_threads = 0;

	for (std::string file : files)
	{
		total_time_file_analysis_all_threads += fileScannerDurations[file];
	}
	return total_time_file_analysis_all_threads;
}

void displayFilesInfo(Result files)
{
	if (files.size() > 0)
	{
		std::cout << "\n Files that Match All Pattern Restrictions :-" << endl;

		for (std::string file : files)
		{
			std::cout << file.substr(file.find_last_of(slash) + 1) << " || ";

			if (fileScannerDurations.find(file) != fileScannerDurations.end())
				std::cout << "Time taken to analyze File " << fileScannerDurations[file] << endl;
		}

		calculateTotalTimeFileAnalysis(files);
	}

	else
	{
		std::cout << "\n No Files Match Passed Text Pattern Restrictions!" << endl;
	}
}

Result mergeVectors(Result x, Result y)
{
	Result merged;

	merged.reserve(x.size() + y.size());

	merged.insert(merged.end(), x.begin(), x.end());

	merged.insert(merged.end(), y.begin(), y.end());

	return merged;
}



void appendRootDirectory(Result &x, const DirectoryPath root)
{
	Result newRes;

	for (std::string inst : x)
	{
		newRes.push_back(root + slash + inst);
	}

	x = newRes;

}

void removeCurrentAndPrevDirectory(Result & res)
{

	Result newRes;

	for (std::string inst : res)
	{
		if (inst != "." && inst != ".." && inst.length()>0)
			newRes.push_back(inst);
	}

	res = newRes;
}

Result getAllDirectoriesRecursive(DirectoryPath  dir)
{
	Result tempDirectories;

	if (dir.length() == 0)
		return tempDirectories;

	Result directoriesListRoot = Directory::getDirectories(dir);

	removeCurrentAndPrevDirectory(directoriesListRoot);

	appendRootDirectory(directoriesListRoot, dir);

	tempDirectories = directoriesListRoot;

	for (std::string directory : directoriesListRoot)
	{
		if (directory != "." && directory != "..")
			tempDirectories = mergeVectors(tempDirectories, getAllDirectoriesRecursive(directory));
	}
	return tempDirectories;
}


Patterns generatePatterns()
{
	Patterns dummy;
	dummy.push_back("std::cout");
	dummy.push_back("<iostream>");
	dummy.push_back("<conio>");
	dummy.push_back("std::string");

	return dummy;
}

bool runFileAnalyzer(FileName currFile, Patterns stringsToFind, bool fileShouldContainAllPatterns)
{
	auto t1 = std::chrono::high_resolution_clock::now();

	FileAnalyzer inst;
	
	bool res = inst.analyzeFile(currFile, stringsToFind, fileShouldContainAllPatterns);
	
	auto t2 = std::chrono::high_resolution_clock::now();
	
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

	fileScannerDurations[std::string(currFile)]= time_span.count();

	return res;
}

Result filterFiles(Patterns stringsToFind, Result listOfFiles, bool fileShouldContainAllPatterns)
{
	Result passedFiles;
	using fileResult = std::future<bool>;
	auto t1 = std::chrono::high_resolution_clock::now();
	//Important Result.... You cant provide move semantics for any Threaded Construct ...
	//You have to maintain a vector of pointers instead of conventional vector of objects
	std::vector<fileResult> futureFiles(listOfFiles.size());

	for (size_t i = 0; i < listOfFiles.size(); i++)
	{
		/**
		Analyze each file in List Of Files on their own Thread
		*/

		futureFiles[i] = std::async(launch::async, runFileAnalyzer, listOfFiles[i], stringsToFind, fileShouldContainAllPatterns);

	}
	for (size_t i = 0; i < listOfFiles.size(); i++)
	{

		try
		{
			if (futureFiles[i].get())
				passedFiles.push_back(listOfFiles[i]);
		}
		catch (exception ex)
		{
			std::cout << "Exception encountered :: " << ex.what() << endl;
		}

	}

	auto t2= std::chrono::high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	
	std::cout << "Total Files Scanned in Duration ==>" << time_span.count() << endl;
	
	double total_time_file_analysis_all_threads= calculateTotalTimeFileAnalysis(listOfFiles);

	std::cout << "Time Slice Summation for File Analyzer ==>" << total_time_file_analysis_all_threads << endl;

	std::cout << "Factor of Paralellism achieved ==>" << total_time_file_analysis_all_threads / time_span.count() << endl;

	return passedFiles;
}




/**
The Algorithm :-
1. Read Each File line by line and Find the Files which pass the criteria of
Given Search Strings
*/

Result TextSearchComponent::search(const DirectoryPath & path, const Patterns & filePatterns, const Patterns &textPatterns)
{
	Result tempFiles, tempDirectories;
	
	if (findFilesRecursive)
	{
		Result directories = getAllDirectoriesRecursive(path);
		
		Result temp;

		for (std::string pattern : filePatterns)
		{
			temp = Directory::getFiles(path, pattern);

			appendRootDirectory(temp, path);

			tempFiles = mergeVectors(tempFiles, temp);
		}

		for (std::string directory : directories)
		{
			for (std::string pattern : filePatterns)
			{
				temp = Directory::getFiles(directory, pattern);

				appendRootDirectory(temp, directory);

				tempFiles = mergeVectors(tempFiles, temp);			
			}
		}

	}

	else if (!findFilesRecursive)
	{
		for (std::string pattern : filePatterns)
		{
			Result temp = Directory::getFiles(path, pattern);
			
			appendRootDirectory(temp, path);

			tempFiles = mergeVectors(tempFiles, temp);
		}
	}

	return  filterFiles(textPatterns, tempFiles, getTextPatternSearchCondition());
}

//# define TEST_TEXT_SEARCH

# ifdef TEST_TEXT_SEARCH

int main(int argc, char **argv)
{

	std::cout << "\n  Demonstrating Text Search Component  Simulation";
	std::cout << "\n =========================================================\n";

	TextComp *comp = TextSearchFactory::createTextSearchComponent();
	
	comp->verbose();

	InputArgumentParser parser;

	if (parser.parseCommandLineArgs2TextCompArguments(argc, argv))
	{
		static_cast<TextSearchComponent*>(comp)->searchFilesRecursive(parser.getRecursionFlag());

		static_cast<TextSearchComponent*>(comp)->searchAllPatterns(parser.getAllPatternsFlag());

		Result fileSet=comp->search(parser.getDirectoryPath(),parser.getFilePatterns(),parser.getTextPatterns());
	
		displayFilesInfo(fileSet);

		comp->Release();
	}

	else
	{
		parser.displayIllegalArgumentMessage();
	}

	return 0;

}

#endif


