// dllmain.h : Declaration of module class.

class CNativeCodeModule : public ATL::CAtlDllModuleT< CNativeCodeModule >
{
public:
	DECLARE_LIBID(LIBID_NativeCodeLib)
	//DECLARE_REGISTRY_APPID_RESOURCEID(IDR_NATIVECODE, "{b6d661ee-b2a6-4fbe-91ab-7d4223505666}")
	DECLARE_NO_REGISTRY()
};

extern class CNativeCodeModule _AtlModule;
