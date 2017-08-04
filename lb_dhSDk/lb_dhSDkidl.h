

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Thu Jul 20 15:23:33 2017
 */
/* Compiler settings for lb_dhSDk.idl:
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


#ifndef __lb_dhSDkidl_h__
#define __lb_dhSDkidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___Dlb_dhSDk_FWD_DEFINED__
#define ___Dlb_dhSDk_FWD_DEFINED__
typedef interface _Dlb_dhSDk _Dlb_dhSDk;

#endif 	/* ___Dlb_dhSDk_FWD_DEFINED__ */


#ifndef ___Dlb_dhSDkEvents_FWD_DEFINED__
#define ___Dlb_dhSDkEvents_FWD_DEFINED__
typedef interface _Dlb_dhSDkEvents _Dlb_dhSDkEvents;

#endif 	/* ___Dlb_dhSDkEvents_FWD_DEFINED__ */


#ifndef __lb_dhSDk_FWD_DEFINED__
#define __lb_dhSDk_FWD_DEFINED__

#ifdef __cplusplus
typedef class lb_dhSDk lb_dhSDk;
#else
typedef struct lb_dhSDk lb_dhSDk;
#endif /* __cplusplus */

#endif 	/* __lb_dhSDk_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_lb_dhSDk_0000_0000 */
/* [local] */ 

#pragma once
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_lb_dhSDk_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_lb_dhSDk_0000_0000_v0_0_s_ifspec;


#ifndef __lb_dhSDkLib_LIBRARY_DEFINED__
#define __lb_dhSDkLib_LIBRARY_DEFINED__

/* library lb_dhSDkLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_lb_dhSDkLib;

#ifndef ___Dlb_dhSDk_DISPINTERFACE_DEFINED__
#define ___Dlb_dhSDk_DISPINTERFACE_DEFINED__

/* dispinterface _Dlb_dhSDk */
/* [uuid] */ 


EXTERN_C const IID DIID__Dlb_dhSDk;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("1A016936-64F7-4986-B470-17C6F2D6AFEA")
    _Dlb_dhSDk : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _Dlb_dhSDkVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _Dlb_dhSDk * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _Dlb_dhSDk * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _Dlb_dhSDk * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _Dlb_dhSDk * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _Dlb_dhSDk * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _Dlb_dhSDk * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _Dlb_dhSDk * This,
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
        
        END_INTERFACE
    } _Dlb_dhSDkVtbl;

    interface _Dlb_dhSDk
    {
        CONST_VTBL struct _Dlb_dhSDkVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _Dlb_dhSDk_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _Dlb_dhSDk_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _Dlb_dhSDk_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _Dlb_dhSDk_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _Dlb_dhSDk_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _Dlb_dhSDk_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _Dlb_dhSDk_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___Dlb_dhSDk_DISPINTERFACE_DEFINED__ */


#ifndef ___Dlb_dhSDkEvents_DISPINTERFACE_DEFINED__
#define ___Dlb_dhSDkEvents_DISPINTERFACE_DEFINED__

/* dispinterface _Dlb_dhSDkEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__Dlb_dhSDkEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A7B41738-2E19-494C-9F33-B9B383FC2A6D")
    _Dlb_dhSDkEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _Dlb_dhSDkEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _Dlb_dhSDkEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _Dlb_dhSDkEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _Dlb_dhSDkEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _Dlb_dhSDkEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _Dlb_dhSDkEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _Dlb_dhSDkEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _Dlb_dhSDkEvents * This,
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
        
        END_INTERFACE
    } _Dlb_dhSDkEventsVtbl;

    interface _Dlb_dhSDkEvents
    {
        CONST_VTBL struct _Dlb_dhSDkEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _Dlb_dhSDkEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _Dlb_dhSDkEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _Dlb_dhSDkEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _Dlb_dhSDkEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _Dlb_dhSDkEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _Dlb_dhSDkEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _Dlb_dhSDkEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___Dlb_dhSDkEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_lb_dhSDk;

#ifdef __cplusplus

class DECLSPEC_UUID("FF15A064-10DF-46D8-BB42-8BEC5D395370")
lb_dhSDk;
#endif
#endif /* __lb_dhSDkLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


