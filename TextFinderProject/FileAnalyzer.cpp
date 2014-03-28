/////////////////////////////////////////////////////////////////////
// FileAnalyzer.cpp												   //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
/*
	this package deals with all the definitions required to 
	search a file, all business logic required to search a particular
	file specified by a absolute or relative path within the file system.

*/
/////////////////////////////////////////////////////////////////////


#include <fstream>
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <set>
#include <future>
#include <mutex>
#include <functional>

#include "FileAnalyzer.h"
#include "OS_SLASH.h"

using namespace std;

std::mutex m;
std::mutex writeConsole;
using Word = std::string;
std::deque<Word> listOfWords;
using patternsAvailable=std::set<std::string>;
using patternsMatched = std::set<std::string>;

void printMatchedPatterns(FileName fname,patternsMatched x,int wordsScanned)
{
		writeConsole.lock();

		if (x.size()>0)
		{
			std::cout << "File " << fname.substr(fname.find_last_of(slash)+1) 
				<< " & Words Scanned " 
				<< wordsScanned 
				<<" Are:-"<<endl << endl;

			for (std::string inst : x)
			{
				std::cout << "\tPattern " << inst << " Found "<<endl;
			}
			std::cout << endl;
		}

		else
		{
			std::cout << "File " << fname.substr(fname.find_last_of(slash) + 1)
				<< " with "
				<< wordsScanned << " Words Scanned with No Match"<<endl << endl;
		}
		writeConsole.unlock();

}

patternsAvailable convertPatterns2Set(Patterns patterns)
{
	patternsAvailable set;

	for (std::string pattern : patterns)
	{
		set.insert(pattern);
	}
	return set;
}



bool FileAnalyzer::analyzeFile(FileName x, Patterns patterns, bool fileShouldContainAllPatterns)
{
	bool result = false;
	patternsAvailable patternSet=convertPatterns2Set(patterns);
	patternsMatched patternsMatchedSet;
	size_t maxPatternsSetSize = patternSet.size();
	ifstream fileHandle(x);
	Word wordInFile;
	int totalWordsScanned=0;

	while (fileHandle >> wordInFile )
	{
		patternsAvailable::iterator it = patternSet.find(wordInFile);
		
		const bool is_in = (patternSet.find(wordInFile) != patternSet.end());

		if (is_in && it->size() > 0)
		{

			patternsMatchedSet.insert(*it);
		
			patternSet.erase(it);
		}
		totalWordsScanned++;
	}

	if (Verbose)
		printMatchedPatterns(x,patternsMatchedSet,totalWordsScanned);

	//Even one patterns was consumed within the iteration 
	if (!fileShouldContainAllPatterns && patternSet.size() < maxPatternsSetSize)
		return true;

	else if (patternSet.size() == 0 && fileShouldContainAllPatterns)	
		return true;

	else
		return false;
}
