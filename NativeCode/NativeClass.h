// NativeClass.h : Declaration of the CNativeClass

#pragma once
#include "resource.h"       // main symbols



#include "NativeCode_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CNativeClass

class ATL_NO_VTABLE CNativeClass :
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CNativeClass, &CLSID_NativeClass>,
	public IDispatchImpl<INativeClass, &IID_INativeClass, &LIBID_NativeCodeLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CNativeClass()
	{
		m_pUnkMarshaler = nullptr;
	}

	//DECLARE_REGISTRY_RESOURCEID(106)
	DECLARE_NO_REGISTRY()

	DECLARE_NOT_AGGREGATABLE(CNativeClass)

	BEGIN_COM_MAP(CNativeClass)
		COM_INTERFACE_ENTRY(INativeClass)
		COM_INTERFACE_ENTRY(IDispatch)
		COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
	END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_GET_CONTROLLING_UNKNOWN()

	HRESULT FinalConstruct()
	{
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

public:



	STDMETHOD(CallGetInstance)(INativeAPI* pAPI);
	STDMETHOD(CallGetNumber)(INativeAPI* pAPI);
};

OBJECT_ENTRY_AUTO(__uuidof(NativeClass), CNativeClass)
