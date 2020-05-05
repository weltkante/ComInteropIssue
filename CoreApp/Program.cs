using System;
using System.Runtime.InteropServices;

namespace CoreApp
{
    class Program
    {
        const int E_POINTER = unchecked((int)0x80004003);

        static void Main(string[] args)
        {
            RunTest("INativeAPI GetInstance()", () =>
            {
                var native = new INativeClass1();
                var api = new NativeAPI_1();
                var hr = native.CallGetInstance(api);
                return (hr, api.called, api.ex);
            });

            RunTest("int GetNumber()", () =>
            {
                var native = new INativeClass1();
                var api = new NativeAPI_1();
                var hr = native.CallGetNumber(api);
                return (hr, api.called, api.ex);
            });

            RunTest("void GetInstance(out INativeAPI)", () =>
            {
                var native = new INativeClass2();
                var api = new NativeAPI_2();
                var hr = native.CallGetInstance(api);
                return (hr, api.called, api.ex);
            });

            RunTest("void GetNumber(out int)", () =>
            {
                var native = new INativeClass2();
                var api = new NativeAPI_2();
                var hr = native.CallGetNumber(api);
                return (hr, api.called, api.ex);
            });

            RunTest("int GetInstance(out INativeAPI)", () =>
            {
                var native = new INativeClass3();
                var api = new NativeAPI_3();
                var hr = native.CallGetInstance(api);
                return (hr, api.called, api.ex);
            });

            RunTest("int GetNumber(out int)", () =>
            {
                var native = new INativeClass3();
                var api = new NativeAPI_3();
                var hr = native.CallGetNumber(api);
                return (hr, api.called, api.ex);
            });

            RunTest("hresult-enum GetInstance(out INativeAPI)", () =>
            {
                var native = new INativeClass4();
                var api = new NativeAPI_4();
                var hr = native.CallGetInstance(api);
                return (hr, api.called, api.ex);
            });

            RunTest("hresult-enum GetNumber(out int)", () =>
            {
                var native = new INativeClass4();
                var api = new NativeAPI_4();
                var hr = native.CallGetNumber(api);
                return (hr, api.called, api.ex);
            });

            RunTest("hresult-struct GetInstance(out INativeAPI)", () =>
            {
                var native = new INativeClass5();
                var api = new NativeAPI_5();
                var hr = native.CallGetInstance(api);
                return (hr, api.called, api.ex);
            });

            RunTest("hresult-struct GetNumber(out int)", () =>
            {
                var native = new INativeClass5();
                var api = new NativeAPI_5();
                var hr = native.CallGetNumber(api);
                return (hr, api.called, api.ex);
            });

            Console.WriteLine("done");
            Console.ReadKey(true);
        }

        static void RunTest(string name, Func<(int, bool, Exception)> test)
        {
            try
            {
                var (hr, called, ex) = test();
                Console.WriteLine(string.Format("{0,-45} -> HR={1:x8} Called={2,-5} Exception={3}", name, (uint)hr, called, ex?.GetType().Name ?? "none"));
            }
            catch (Exception ex)
            {
                Console.WriteLine($"{name} -> {ex.Message}");
            }
        }
    }

    class NativeAPI_1 : INativeAPI_1
    {
        public bool called;
        public Exception ex;

        public INativeAPI_1 GetInstance()
        {
            try
            {
                called = true;
                return this;
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }

        public int GetNumber()
        {
            try
            {
                called = true;
                return 42;
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }
    }

    class NativeAPI_2 : INativeAPI_2
    {
        public bool called;
        public Exception ex;

        public void GetInstance(out INativeAPI_2 result)
        {
            try
            {
                called = true;
                result = this;
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }

        public void GetNumber(out int result)
        {
            try
            {
                called = true;
                result = 42;
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }
    }

    class NativeAPI_3 : INativeAPI_3
    {
        public bool called;
        public Exception ex;

        public int GetInstance(out INativeAPI_3 result)
        {
            try
            {
                called = true;
                result = this;
                return 2;
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }

        public int GetNumber(out int result)
        {
            try
            {
                called = true;
                result = 42;
                return 2;
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }
    }

    class NativeAPI_4 : INativeAPI_4
    {
        public bool called;
        public Exception ex;

        public HRESULT_Enum GetInstance(out INativeAPI_4 result)
        {
            try
            {
                called = true;
                result = this;
                return (HRESULT_Enum)2;
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }

        public HRESULT_Enum GetNumber(out int result)
        {
            try
            {
                called = true;
                result = 42;
                return (HRESULT_Enum)2;
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }
    }

    class NativeAPI_5 : INativeAPI_5
    {
        public bool called;
        public Exception ex;

        public HRESULT_Struct GetInstance(out INativeAPI_5 result)
        {
            try
            {
                called = true;
                result = this;
                return new HRESULT_Struct { Value = 2 };
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }

        public HRESULT_Struct GetNumber(out int result)
        {
            try
            {
                called = true;
                result = 42;
                return new HRESULT_Struct { Value = 2 };
            }
            catch (Exception ex) { this.ex = ex; throw; }
        }
    }

    enum HRESULT_Enum : int { }

    [StructLayout(LayoutKind.Sequential)]
    struct HRESULT_Struct { public int Value; }

    [ComImport]
    [Guid("DE133ABC-7C52-4A19-9E9C-44F4A5A54BE4")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    interface INativeAPI_1
    {
        INativeAPI_1 GetInstance();
        int GetNumber();
    }

    [ComImport]
    [Guid("DE133ABC-7C52-4A19-9E9C-44F4A5A54BE4")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    interface INativeAPI_2
    {
        void GetInstance(out INativeAPI_2 result);
        void GetNumber(out int result);
    }

    [ComImport]
    [Guid("DE133ABC-7C52-4A19-9E9C-44F4A5A54BE4")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    interface INativeAPI_3
    {
        [PreserveSig]
        int GetInstance(out INativeAPI_3 result);

        [PreserveSig]
        int GetNumber(out int result);
    }

    [ComImport]
    [Guid("DE133ABC-7C52-4A19-9E9C-44F4A5A54BE4")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    interface INativeAPI_4
    {
        [PreserveSig]
        HRESULT_Enum GetInstance(out INativeAPI_4 result);

        [PreserveSig]
        HRESULT_Enum GetNumber(out int result);
    }

    [ComImport]
    [Guid("DE133ABC-7C52-4A19-9E9C-44F4A5A54BE4")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    interface INativeAPI_5
    {
        [PreserveSig]
        HRESULT_Struct GetInstance(out INativeAPI_5 result);

        [PreserveSig]
        HRESULT_Struct GetNumber(out int result);
    }

    [ComImport]
    [Guid("b871ac0e-2923-468a-93f3-b0d36654a05d")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    [CoClass(typeof(CNativeClass1))]
    interface INativeClass1
    {
        [PreserveSig]
        int CallGetInstance(INativeAPI_1 api);

        [PreserveSig]
        int CallGetNumber(INativeAPI_1 api);
    }

    [ComImport]
    [Guid("b871ac0e-2923-468a-93f3-b0d36654a05d")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    [CoClass(typeof(CNativeClass2))]
    interface INativeClass2
    {
        [PreserveSig]
        int CallGetInstance(INativeAPI_2 api);

        [PreserveSig]
        int CallGetNumber(INativeAPI_2 api);
    }

    [ComImport]
    [Guid("b871ac0e-2923-468a-93f3-b0d36654a05d")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    [CoClass(typeof(CNativeClass3))]
    interface INativeClass3
    {
        [PreserveSig]
        int CallGetInstance(INativeAPI_3 api);

        [PreserveSig]
        int CallGetNumber(INativeAPI_3 api);
    }

    [ComImport]
    [Guid("b871ac0e-2923-468a-93f3-b0d36654a05d")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    [CoClass(typeof(CNativeClass4))]
    interface INativeClass4
    {
        [PreserveSig]
        int CallGetInstance(INativeAPI_4 api);

        [PreserveSig]
        int CallGetNumber(INativeAPI_4 api);
    }

    [ComImport]
    [Guid("b871ac0e-2923-468a-93f3-b0d36654a05d")]
    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    [CoClass(typeof(CNativeClass5))]
    interface INativeClass5
    {
        [PreserveSig]
        int CallGetInstance(INativeAPI_5 api);

        [PreserveSig]
        int CallGetNumber(INativeAPI_5 api);
    }

    [ComImport]
    [Guid("74b50739-1df8-4d9f-b2f2-033df90a4aa6")]
    [ClassInterface(ClassInterfaceType.None)]
    class CNativeClass1 { }

    [ComImport]
    [Guid("74b50739-1df8-4d9f-b2f2-033df90a4aa6")]
    [ClassInterface(ClassInterfaceType.None)]
    class CNativeClass2 { }

    [ComImport]
    [Guid("74b50739-1df8-4d9f-b2f2-033df90a4aa6")]
    [ClassInterface(ClassInterfaceType.None)]
    class CNativeClass3 { }

    [ComImport]
    [Guid("74b50739-1df8-4d9f-b2f2-033df90a4aa6")]
    [ClassInterface(ClassInterfaceType.None)]
    class CNativeClass4 { }

    [ComImport]
    [Guid("74b50739-1df8-4d9f-b2f2-033df90a4aa6")]
    [ClassInterface(ClassInterfaceType.None)]
    class CNativeClass5 { }
}
