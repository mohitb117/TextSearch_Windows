/////////////////////////////////////////////////////////////////////
// TextCompCOM.cpp										           //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
// Declaration of The TextSearchComponent COM Interface	           //
/////////////////////////////////////////////////////////////////////

// TextCompCOM.cpp : Implementation of CTextCompCOM
#include "stdafx.h"
#include "TextCompCOM.h"

# include <iostream>
using namespace std;

// CTextCompCOM

std::string  convertBSTR2stdSTR(BSTR ms_str)
{
	std::wstring ws(ms_str);

	std::string result(ws.begin(), ws.end());

	return result;
}

STDMETHODIMP CTextCompCOM::InitializeComponent()
{
	//std::cout << "Init TextComponent"<<endl;

	comp = TextSearchFactory::createTextSearchComponent();

	comp->verbose();

	return S_OK;
}

STDMETHODIMP CTextCompCOM::SetSearchPath(BSTR SearchPathLocation)
{
	//std::cout << "SetSearchPath"<<endl;

	CTextCompCOM::SearchPathLocation = SearchPathLocation;

	return S_OK;
}


STDMETHODIMP CTextCompCOM::SetFilePatterns(SAFEARRAY** FilePatterns)
{

	CTextCompCOM::FilePatterns=*FilePatterns;

	return S_OK;
}


STDMETHODIMP CTextCompCOM::SetTextPatterns(SAFEARRAY** TextPatterns)
{
	CTextCompCOM::TextPatterns=*TextPatterns;

	return S_OK;
}


STDMETHODIMP CTextCompCOM::SetSpecialSearchClause(BSTR Recursion, BSTR MatchAllTextPatterns)
{
	TextSearchComponent *classPtr = static_cast<TextSearchComponent*>(comp);

	std::string recur(convertBSTR2stdSTR(Recursion));
	std::string allPatterns(convertBSTR2stdSTR(MatchAllTextPatterns));

	//std::cout << "Recursion" << recur << " Patterns" << allPatterns << endl;

	if (recur == "True" || recur == "TRUE" || recur=="true")
	{
		classPtr->searchFilesRecursive(true);
	}
	else
	{
		classPtr->searchFilesRecursive(false);
	}

	if (allPatterns == "True" || allPatterns == "TRUE" || allPatterns=="true")
	{
		classPtr->searchAllPatterns(true);
	}
	else
	{
		classPtr->searchAllPatterns(false);
	}

	return S_OK;
}

void titleFunc(const std::string& title, char ch = '=')
{
	std::cout << "\n  " << title<<"\n";
	std::cout << std::string(title.size() + 2, ch)<<"\n";

}


void displayFilesSet(Result files)
{
	titleFunc("Files that Match All Pattern Restrictions :-");

	for (std::string file : files)
	{
		std::cout << file.substr(file.find_last_of(slash) + 1) << endl;
	}

}



STDMETHODIMP CTextCompCOM::GetQualifyingFileList(SAFEARRAY** FileSet)
{
	CComSafeArray<BSTR> _filesSet;

	Patterns filePatterns,textPatterns;

		for (size_t i = 0; i < CTextCompCOM::FilePatterns.GetCount(); i++)
		{
			auto bstr = CTextCompCOM::FilePatterns.GetAt(i);
			// convert directly into str-allocated buffer.		
			std::string str = convertBSTR2stdSTR(bstr);
			filePatterns.push_back(str);
		}

		for (size_t i = 0; i < CTextCompCOM::TextPatterns.GetCount(); i++)
		{
			auto bstr = CTextCompCOM::TextPatterns.GetAt(i);
			// convert directly into str-allocated buffer.
			std::string str = convertBSTR2stdSTR(bstr);
			textPatterns.push_back(str);
		}

		std::string pathDir = convertBSTR2stdSTR(CTextCompCOM::SearchPathLocation);
		
		std::cout << "\n Path Location:-" << pathDir<<endl;

		displayFilesSet(filePatterns);
		
		displayFilesSet(textPatterns);

		Result res = comp->search(pathDir, filePatterns,textPatterns);
		
		for (std::string fileName : res)
		{
			_filesSet.Add(CComBSTR(fileName.c_str()));
		}

		if (res.size() > 0)
			std::cout << "\n Files Found :" << _filesSet.GetCount() << endl;
		
		else
		{
			_filesSet.Add(CComBSTR("No Files Found"));
		}
		*FileSet = _filesSet.Detach();

		comp->Release();

	return S_OK;
}


