#if !defined(AFX_BHMNUMEDIT_H__E00B2780_8076_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_BHMNUMEDIT_H__E00B2780_8076_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BHMNumEdit.h : header file
//
#include "..\testgrid\numedit.h"
/////////////////////////////////////////////////////////////////////////////
// CBHMNumEdit window

class CBHMNumEdit : public CNumEdit
{
// Construction
public:
	CBHMNumEdit();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBHMNumEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetValue(double fValue);
	double GetValue();
	void CalcText(BOOL bIsFocused);
	void SetDisplayMask(CString strNewMask);
	void SetMask(CString strMask);
	virtual ~CBHMNumEdit();

protected:
	CString m_strPositivePrefix, m_strPositiveSuffix;
	CString m_strNegativePrefix, m_strNegativeSuffix;

	// Generated message map functions
protected:
	void CalcDisplayMask(CString strMask, int i);
	//{{AFX_MSG(CBHMNumEdit)
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BHMNUMEDIT_H__E00B2780_8076_11D3_A7FE_0080C8763FA4__INCLUDED_)
