/////////////////////////////////////////////////////////////////////
// FileAnalyzer.h										           //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
// File Analysis Abstarction which deals with a single file name   //
// and returns true or false if the file contains				   // 
//					all patterns or not (depending on the situation)//
/////////////////////////////////////////////////////////////////////

#pragma once

using FileName = std::string;
using Patterns = std::vector <std::string>;

class FileAnalyzer
{
public:
	bool analyzeFile(FileName fileName, Patterns x, bool fileShouldContainAllPatterns);
};

