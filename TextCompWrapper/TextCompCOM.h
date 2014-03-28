/////////////////////////////////////////////////////////////////////
// TextCompCOM.cpp										           //
//                                                                 //
// Mohit Bhalla CSE Syracuse University, Spring 2014	           //
// Just the Definition of The TextSearchComponent COM Interface	   //
/////////////////////////////////////////////////////////////////////

// TextCompCOM.h : Declaration of the CTextCompCOM

#pragma once
#include "resource.h"       // main symbols

#include "TextCompWrapper_i.h"
#include <atlsafe.h>

# include "../TextFinderProject/TextSearchFactory.h"

using TextComp = AbstractTextSearchComponentReferenceCounted;

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CTextCompCOM

class ATL_NO_VTABLE CTextCompCOM :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTextCompCOM, &CLSID_TextCompCOM>,
	public IDispatchImpl<ITextCompCOM, &IID_ITextCompCOM, &LIBID_TextCompWrapperLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTextCompCOM()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TEXTCOMPCOM)


BEGIN_COM_MAP(CTextCompCOM)
	COM_INTERFACE_ENTRY(ITextCompCOM)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(SetSearchPath)(BSTR SearchPathLocation);
	STDMETHOD(SetFilePatterns)(SAFEARRAY ** FilePatterns);
	STDMETHOD(SetTextPatterns)(SAFEARRAY** TextPatterns);
	STDMETHOD(SetSpecialSearchClause)(BSTR Recursion, BSTR MatchAllTextPatterns);
	STDMETHOD(GetQualifyingFileList)(SAFEARRAY** FileSet);
	STDMETHOD(InitializeComponent)();
private:
	TextComp *comp;
	CComBSTR SearchPathLocation ;
	//CComBSTR RecursionFlag, MatchAllPatternsFlag;
	CComSafeArray<BSTR> FilePatterns, TextPatterns;
};

OBJECT_ENTRY_AUTO(__uuidof(TextCompCOM), CTextCompCOM)
