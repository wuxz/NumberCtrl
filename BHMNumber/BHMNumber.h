#if !defined(AFX_BHMNUMBER_H__B07953AB_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_BHMNUMBER_H__B07953AB_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// BHMNumber.h : main header file for BHMNUMBER.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBHMNumberApp : See BHMNumber.cpp for implementation.

class CBHMNumberApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BHMNUMBER_H__B07953AB_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED)
