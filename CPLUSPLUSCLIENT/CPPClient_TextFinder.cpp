/////////////////////////////////////////////////////////////////////
// CPPClient_TextFinder.cpp						                   //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
// C++ Client which Loads the COM DLL and Invokes the Library      //
// packaged Methods  											   //
/////////////////////////////////////////////////////////////////////

#define _WIN32_WINNT 0x0501

#include <iostream>
#include <atlbase.h>
#include <atlsafe.h>

#include "../TextCompWrapper/TextCompWrapper_i.h"
# include "../TextFinderProject/TextSearchFactory.h"
# include "../TextFinderProject/InputArgumentParser.h"

using TextComp = AbstractTextSearchComponentReferenceCounted;

std::string bool2String(bool b)
{
	if (b)
		return "true";
	else
		return "false";
}

std::string  convertBSTR2stdSTR(BSTR ms_str)
{
	std::wstring ws(ms_str);

	std::string result(ws.begin(), ws.end());

	return result;
}

BSTR  convertstdSTR2BSTR(std::string str)
{
	return ::SysAllocString( CComBSTR(str.c_str()) );
}

CComSafeArray<BSTR> convertVector2CCOMSafeArray(Result x)
{
\
	CComSafeArray<BSTR> result;

	for (std::string inst : x)
	{
		result.Add(convertstdSTR2BSTR(inst));
	}
	return result;

}

void displayCCOMBSTRFiles(CComSafeArray<BSTR> fileSet)
{

	std::wcout << "Displaying Files Generated from the C++ Interface from COM OBJECT" << std::endl;

	for (ULONG i = 0; i < fileSet.GetCount(); i++)
	{
		std::cout << "Qualified File # " <<i<<" : "<< convertBSTR2stdSTR(fileSet.GetAt(i)) << "\n";
	}

}

void main(int argc, char**argv)
{
	std::wcout << L"\n ===================================\n";
	std::wcout << L"\n  TextFinderComponent C++ Interface ";
	std::wcout << L"\n ===================================\n";

	HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

	if (!SUCCEEDED(hr))
	{
		std::wcout << L"\n  could not initialize COM";
	}

	try
	{
		CComQIPtr<ITextCompCOM> TextFinderComp;

		TextFinderComp.CoCreateInstance(CLSID_TextCompCOM);
		
		if (TextFinderComp != 0)
		{
			std::wcout << L"\n =============================================================\n";

			std::wcout << "The Text Component Interface was successfully initialized" << std::endl;

			std::wcout << L"\n =============================================================\n";

			InputArgumentParser parser;

			if (parser.parseCommandLineArgs2TextCompArguments(argc, argv))
			{
				HRESULT h0 = TextFinderComp->InitializeComponent();

				HRESULT h1 = TextFinderComp->SetSearchPath(CComBSTR(parser.getDirectoryPath().c_str()));

				BSTR allPatterns;
				BSTR recursion;

				allPatterns = convertstdSTR2BSTR(bool2String(true)) ;    //By default find all patterns
				
				recursion = convertstdSTR2BSTR(bool2String(false)) ;  // By default Recursion is disabled

				if (parser.getRecursionFlag())
				{
					recursion = convertstdSTR2BSTR(bool2String(true));
				}

				if (!parser.getAllPatternsFlag())
				{
					allPatterns = convertstdSTR2BSTR(bool2String(false));
				}

				HRESULT h2 = TextFinderComp->SetSpecialSearchClause(recursion, allPatterns);

				HRESULT h3 = TextFinderComp->SetFilePatterns(convertVector2CCOMSafeArray(parser.getFilePatterns()).GetSafeArrayPtr());

				HRESULT h4 = TextFinderComp->SetTextPatterns(convertVector2CCOMSafeArray(parser.getTextPatterns()).GetSafeArrayPtr());

				if (SUCCEEDED(h0) && SUCCEEDED(h1) && SUCCEEDED(h2) && SUCCEEDED(h3) && SUCCEEDED(h4))
				{
					
					SAFEARRAY files;
				
					SAFEARRAY* pFiles = &files;

					TextFinderComp->GetQualifyingFileList(&pFiles);

					CComSafeArray<BSTR> Files;

					Files.Attach(pFiles);	

					std::wcout << L"\n =============================================================\n";
					std::wcout << L"\n =============================================================\n";

					std::wcout<<"The Qualifying Files from the Text Search Component via C++ COM interface"<<std::endl;

					displayCCOMBSTRFiles(Files);

					std::cout << "End of C++ Client for Text Search Component" << std::endl;

					std::wcout << L"\n =============================================================\n";

				}
			}

			else
			{
				parser.displayIllegalArgumentMessage();
			}

		}

	}
	catch (std::exception& ex)
	{
		std::wcout << L"\n  Exception Encountered during COM Stuff .. Contact Admin and Bug Him!" << ex.what() << L"\n\n";
		return;
	}

	std::wcout << L"\n\n";
	CoUninitialize();
}
