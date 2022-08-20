#if !defined(AFX_BHMNUMBERPPG_H__B07953B5_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_BHMNUMBERPPG_H__B07953B5_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// BHMNumberPpg.h : Declaration of the CBHMNumberPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CBHMNumberPropPage : See BHMNumberPpg.cpp.cpp for implementation.

class CBHMNumberPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CBHMNumberPropPage)
	DECLARE_OLECREATE_EX(CBHMNumberPropPage)

// Constructor
public:
	CBHMNumberPropPage();

// Dialog Data
	//{{AFX_DATA(CBHMNumberPropPage)
	enum { IDD = IDD_PROPPAGE_BHMNUMBER };
	CString	m_strDisplayMask;
	int		m_sAppearance;
	int		m_nAlignment;
	CString	m_strMask;
	double	m_fValue;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CBHMNumberPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BHMNUMBERPPG_H__B07953B5_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED)
