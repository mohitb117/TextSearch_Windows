

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Mar 26 20:32:20 2014
 */
/* Compiler settings for TextCompWrapper.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __TextCompWrapper_i_h__
#define __TextCompWrapper_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITextCompCOM_FWD_DEFINED__
#define __ITextCompCOM_FWD_DEFINED__
typedef interface ITextCompCOM ITextCompCOM;

#endif 	/* __ITextCompCOM_FWD_DEFINED__ */


#ifndef __TextCompCOM_FWD_DEFINED__
#define __TextCompCOM_FWD_DEFINED__

#ifdef __cplusplus
typedef class TextCompCOM TextCompCOM;
#else
typedef struct TextCompCOM TextCompCOM;
#endif /* __cplusplus */

#endif 	/* __TextCompCOM_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITextCompCOM_INTERFACE_DEFINED__
#define __ITextCompCOM_INTERFACE_DEFINED__

/* interface ITextCompCOM */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITextCompCOM;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C8E6AB01-9AAC-4E51-B047-C245AA080F2C")
    ITextCompCOM : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetSearchPath( 
            /* [in] */ BSTR SearchPathLocation) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetFilePatterns( 
            /* [in] */ SAFEARRAY * *FilePatterns) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetTextPatterns( 
            /* [in] */ SAFEARRAY * *TextPatterns) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetSpecialSearchClause( 
            /* [in] */ BSTR Recursion,
            /* [in] */ BSTR MatchAllTextPatterns) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetQualifyingFileList( 
            /* [out] */ SAFEARRAY * *FileSet) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitializeComponent( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITextCompCOMVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITextCompCOM * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITextCompCOM * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITextCompCOM * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITextCompCOM * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITextCompCOM * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITextCompCOM * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITextCompCOM * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetSearchPath )( 
            ITextCompCOM * This,
            /* [in] */ BSTR SearchPathLocation);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetFilePatterns )( 
            ITextCompCOM * This,
            /* [in] */ SAFEARRAY * *FilePatterns);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetTextPatterns )( 
            ITextCompCOM * This,
            /* [in] */ SAFEARRAY * *TextPatterns);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *SetSpecialSearchClause )( 
            ITextCompCOM * This,
            /* [in] */ BSTR Recursion,
            /* [in] */ BSTR MatchAllTextPatterns);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetQualifyingFileList )( 
            ITextCompCOM * This,
            /* [out] */ SAFEARRAY * *FileSet);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *InitializeComponent )( 
            ITextCompCOM * This);
        
        END_INTERFACE
    } ITextCompCOMVtbl;

    interface ITextCompCOM
    {
        CONST_VTBL struct ITextCompCOMVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITextCompCOM_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITextCompCOM_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITextCompCOM_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITextCompCOM_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITextCompCOM_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITextCompCOM_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITextCompCOM_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITextCompCOM_SetSearchPath(This,SearchPathLocation)	\
    ( (This)->lpVtbl -> SetSearchPath(This,SearchPathLocation) ) 

#define ITextCompCOM_SetFilePatterns(This,FilePatterns)	\
    ( (This)->lpVtbl -> SetFilePatterns(This,FilePatterns) ) 

#define ITextCompCOM_SetTextPatterns(This,TextPatterns)	\
    ( (This)->lpVtbl -> SetTextPatterns(This,TextPatterns) ) 

#define ITextCompCOM_SetSpecialSearchClause(This,Recursion,MatchAllTextPatterns)	\
    ( (This)->lpVtbl -> SetSpecialSearchClause(This,Recursion,MatchAllTextPatterns) ) 

#define ITextCompCOM_GetQualifyingFileList(This,FileSet)	\
    ( (This)->lpVtbl -> GetQualifyingFileList(This,FileSet) ) 

#define ITextCompCOM_InitializeComponent(This)	\
    ( (This)->lpVtbl -> InitializeComponent(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITextCompCOM_INTERFACE_DEFINED__ */



#ifndef __TextCompWrapperLib_LIBRARY_DEFINED__
#define __TextCompWrapperLib_LIBRARY_DEFINED__

/* library TextCompWrapperLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_TextCompWrapperLib;

EXTERN_C const CLSID CLSID_TextCompCOM;

#ifdef __cplusplus

class DECLSPEC_UUID("29CFFBBD-27DC-4D51-BCF5-913B2F1D76F3")
TextCompCOM;
#endif
#endif /* __TextCompWrapperLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


