

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for NativeCode.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=AMD64 8.01.0622 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __NativeCode_i_h__
#define __NativeCode_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __INativeAPI_FWD_DEFINED__
#define __INativeAPI_FWD_DEFINED__
typedef interface INativeAPI INativeAPI;

#endif 	/* __INativeAPI_FWD_DEFINED__ */


#ifndef __INativeClass_FWD_DEFINED__
#define __INativeClass_FWD_DEFINED__
typedef interface INativeClass INativeClass;

#endif 	/* __INativeClass_FWD_DEFINED__ */


#ifndef __NativeClass_FWD_DEFINED__
#define __NativeClass_FWD_DEFINED__

#ifdef __cplusplus
typedef class NativeClass NativeClass;
#else
typedef struct NativeClass NativeClass;
#endif /* __cplusplus */

#endif 	/* __NativeClass_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __INativeAPI_INTERFACE_DEFINED__
#define __INativeAPI_INTERFACE_DEFINED__

/* interface INativeAPI */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_INativeAPI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DE133ABC-7C52-4A19-9E9C-44F4A5A54BE4")
    INativeAPI : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetInstance( 
            /* [retval][out] */ IUnknown **pResult) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetNumber( 
            /* [retval][out] */ LONG *pResult) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INativeAPIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INativeAPI * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INativeAPI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INativeAPI * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INativeAPI * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INativeAPI * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INativeAPI * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INativeAPI * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetInstance )( 
            INativeAPI * This,
            /* [retval][out] */ IUnknown **pResult);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetNumber )( 
            INativeAPI * This,
            /* [retval][out] */ LONG *pResult);
        
        END_INTERFACE
    } INativeAPIVtbl;

    interface INativeAPI
    {
        CONST_VTBL struct INativeAPIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INativeAPI_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INativeAPI_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INativeAPI_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INativeAPI_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INativeAPI_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INativeAPI_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INativeAPI_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INativeAPI_GetInstance(This,pResult)	\
    ( (This)->lpVtbl -> GetInstance(This,pResult) ) 

#define INativeAPI_GetNumber(This,pResult)	\
    ( (This)->lpVtbl -> GetNumber(This,pResult) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INativeAPI_INTERFACE_DEFINED__ */


#ifndef __INativeClass_INTERFACE_DEFINED__
#define __INativeClass_INTERFACE_DEFINED__

/* interface INativeClass */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_INativeClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b871ac0e-2923-468a-93f3-b0d36654a05d")
    INativeClass : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CallGetInstance( 
            INativeAPI *pAPI) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CallGetNumber( 
            INativeAPI *pAPI) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct INativeClassVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            INativeClass * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            INativeClass * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            INativeClass * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            INativeClass * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            INativeClass * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            INativeClass * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            INativeClass * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CallGetInstance )( 
            INativeClass * This,
            INativeAPI *pAPI);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *CallGetNumber )( 
            INativeClass * This,
            INativeAPI *pAPI);
        
        END_INTERFACE
    } INativeClassVtbl;

    interface INativeClass
    {
        CONST_VTBL struct INativeClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define INativeClass_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define INativeClass_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define INativeClass_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define INativeClass_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define INativeClass_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define INativeClass_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define INativeClass_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define INativeClass_CallGetInstance(This,pAPI)	\
    ( (This)->lpVtbl -> CallGetInstance(This,pAPI) ) 

#define INativeClass_CallGetNumber(This,pAPI)	\
    ( (This)->lpVtbl -> CallGetNumber(This,pAPI) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __INativeClass_INTERFACE_DEFINED__ */



#ifndef __NativeCodeLib_LIBRARY_DEFINED__
#define __NativeCodeLib_LIBRARY_DEFINED__

/* library NativeCodeLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_NativeCodeLib;

EXTERN_C const CLSID CLSID_NativeClass;

#ifdef __cplusplus

class DECLSPEC_UUID("74b50739-1df8-4d9f-b2f2-033df90a4aa6")
NativeClass;
#endif
#endif /* __NativeCodeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


