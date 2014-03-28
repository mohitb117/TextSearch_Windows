/////////////////////////////////////////////////////////////////////
// InputArgumentParser.h								           //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
// 	The Skeleton of the parser to scan COmmand Line Arguments	   //
//  For valid arguments to the TextSearchComponent				   //
/////////////////////////////////////////////////////////////////////

# include "TextSearchFactory.h"

class InputArgumentParser
{

private:
	Patterns textPatterns, filePatterns;

	bool recursion = false;   //By Default false its not Recursion
	bool allPatterns = true;  //By default true  ... Find Files which have all String Occurences

	DirectoryPath dirPath;

	public:
		bool parseCommandLineArgs2TextCompArguments(int argc, char ** argv);

		bool getRecursionFlag();
		bool getAllPatternsFlag();

		Patterns getTextPatterns();
		Patterns getFilePatterns();
		DirectoryPath getDirectoryPath();
		void displayIllegalArgumentMessage();
	
};