// NativeClass.cpp : Implementation of CNativeClass

#include "pch.h"
#include "NativeClass.h"


// CNativeClass

STDMETHODIMP CNativeClass::CallGetInstance(INativeAPI* pAPI)
{
    return pAPI ? pAPI->GetInstance(NULL) : S_FALSE;
}

STDMETHODIMP CNativeClass::CallGetNumber(INativeAPI* pAPI)
{
    return pAPI ? pAPI->GetNumber(NULL) : S_FALSE;
}
