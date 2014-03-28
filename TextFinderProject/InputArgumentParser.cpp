/////////////////////////////////////////////////////////////////////
// InputArgumentParser.cpp										   //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //

/*
	The Input Argument Parser performs the conversion logic of 
	parsing the command line arguments to the data required by the
	TextSearchComponent i.e recursion, findPatterns , directoryPaths, 
	text and file patterns
*/

/////////////////////////////////////////////////////////////////////

# include "InputArgumentParser.h"

/*
	Schema of TextCompParsing :=

	<AppExec>.exe  /R(optional)   /O(optional)      -Path    ____    -Words  ____ ____ -Files ______ _______
					recursion      strings patterns
*/

std::string boolean2String(bool b)
{
	if (b)
		return "true";
	else
		return "false";
}

void printList(Result x)
{
	for(std::string inst : x)
	{
		std::cout <<inst<<" , ";
	}
	std::cout << std::endl;
}

void VerboseArgumentsPassed(bool recursion,bool allPatterns, Result TextPatterns,Result FilePatterns, DirectoryPath dirPath)
{

	std::cout<<"Arguments Scanned by the Parser"<<std::endl;

	std::cout<<"Recursion Search Flag ==>" << boolean2String(recursion)  << std::endl;

	std::cout << "Search Files That contain Text Strings Flag ==> " << boolean2String(allPatterns) << std::endl;

	std::cout<<"Directory Path Provided for Searching==>"<<dirPath<<std::endl;

	std::cout<<"Text Patterns Needed for Searching==> ";

	printList(TextPatterns);

	std::cout<<"File Patterns Needed for Searching==> ";

	printList(FilePatterns);

}





void StoreAllPatterns(int argc, char ** argv, size_t currPos, Result & x)
{
	for (int i = currPos + 1; i < argc; i++)
	{
		std::string str(argv[i]);

		size_t pos = str.find("-");
		size_t maxPos = str.length();

		if ( pos >= 0 && pos <maxPos)
		{
			return;
		}

		else
		{
			x.push_back(str);
		}

	}

}

void scanTextCompFlags(int argc, char ** argv,bool & recursion,bool & allPatterns)
{

	for (int i = 0; i < argc; i++)
	{
		std::string arg(argv[i]);

		//If no /R mentioned .. then recursion is false
		if (arg == "/R")
		{
			recursion = true;
		}

		//If no /O is mentioned find allPatterns
		if (arg == "/O")
		{
			allPatterns = false;
		}
	}

}


void scanTextCompDirPath( int argc, char ** argv, DirectoryPath &dirPath)
{
	for (int i =0; i < argc; i++)
	{
		std::string arg(argv[i]);

		if (arg == "-Path"  && argc >= i+1)
		{
		    std::string path(argv[i+1]);
			dirPath = path;
			return;
		}
	}
}

void scanTextCompFileSearchString( int argc, char ** argv, Result &x)
{
	for (int i = 0; i < argc; i++)
	{
		std::string arg(argv[i]);

		if (arg == "-Files" && argc >= i + 1)
		{
			StoreAllPatterns(argc, argv, i, x);

			return;
		}
	}
}



void scanTextCompTextSearchString( int argc, char ** argv, Result &x)
{
	for (int i = 0; i < argc; i++)
	{

		std::string arg(argv[i]);

		if (arg == "-Words" && argc >= i + 1)
		{
			StoreAllPatterns(argc, argv, i, x);

			return;
		}
	}
}

Result InputArgumentParser::getFilePatterns()
{
	return filePatterns;
}


Result InputArgumentParser::getTextPatterns()
{
	return textPatterns;
}

DirectoryPath InputArgumentParser::getDirectoryPath()
{
	return dirPath;
}

bool InputArgumentParser::getRecursionFlag()
{
	return recursion;
}

bool InputArgumentParser::getAllPatternsFlag()
{
	return allPatterns;
}

bool InputArgumentParser::parseCommandLineArgs2TextCompArguments(int argc, char ** argv)
{
	scanTextCompDirPath(argc, argv, dirPath);

	scanTextCompFlags(argc, argv, recursion, allPatterns);

	scanTextCompFileSearchString(argc, argv, filePatterns);

	scanTextCompTextSearchString(argc, argv, textPatterns);

	if (filePatterns.size() == 0)
	{
		filePatterns.push_back("*.*");
	}

	if (textPatterns.size() == 0)
	{
		return false;
	}

	if (!(dirPath != "" || dirPath != " " || dirPath!="\t" || dirPath!= "\n" || dirPath!="\b" ))
	{
		dirPath = ".";
	}

	VerboseArgumentsPassed(getRecursionFlag(), getAllPatternsFlag(), getTextPatterns(), getFilePatterns(), getDirectoryPath());

	return true;
}

void InputArgumentParser::displayIllegalArgumentMessage()
{
	std::cout << "Error During Parsing of Arguments of the TextSearchComponent" << std::endl;
	std::cout << "Arguments==> /R(opt)   /O(opt)   -Path ______  -Words __ ___   -Files ___ ___" << std::endl;
	std::cout << "             recursion Condition  DirectoryPath TextPatterns     FilePatterns  " << std::endl;
}
