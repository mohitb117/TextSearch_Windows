// dllmain.h : Declaration of module class.

class CTextCompWrapperModule : public ATL::CAtlDllModuleT< CTextCompWrapperModule >
{
public :
	DECLARE_LIBID(LIBID_TextCompWrapperLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_TEXTCOMPWRAPPER, "{395E1537-5843-4F5A-A13A-C81F3D9072D7}")
};

extern class CTextCompWrapperModule _AtlModule;
