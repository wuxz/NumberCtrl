#if !defined(AFX_BHMNUMBERCTL_H__B07953B3_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED_)
#define AFX_BHMNUMBERCTL_H__B07953B3_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// BHMNumberCtl.h : Declaration of the CBHMNumberCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl : See BHMNumberCtl.cpp for implementation.
class CBHMNumEdit;

class CBHMNumberCtrl : public COleControl
{
	DECLARE_DYNCREATE(CBHMNumberCtrl)

// Constructor
public:
	CBHMNumberCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBHMNumberCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual void OnFontChanged();
	virtual BOOL OnSetObjectRects(LPCRECT lpRectPos, LPCRECT lpRectClip);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnGetPredefinedStrings(DISPID dispid, CStringArray* pStringArray, CDWordArray* pCookieArray);
	virtual BOOL OnGetPredefinedValue(DISPID dispid, DWORD dwCookie, VARIANT* lpvarOut);
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_strMask;
	CString m_strDisplayMask;
	double m_fValue;
	OLE_COLOR m_clrFore, m_clrBack, m_clrNegative;
	short m_nAlignment;

protected:
	// the pointer of the editbox window
	CBHMNumEdit * m_pEdit;

	// the handle of the using font for editbox
	HFONT m_hFont;

	// the brush to draw the background
	CBrush * m_pBrhBack;

	BOOL IsValidDisplayMask(CString strMask);
	void ExchangeStockProps(CPropExchange *pPX);
	BOOL IsValidMask(CString strMask);
	
	~CBHMNumberCtrl();

	BEGIN_OLEFACTORY(CBHMNumberCtrl)        // Class factory and guid
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR FAR*);
	END_OLEFACTORY(CBHMNumberCtrl)

	DECLARE_OLETYPELIB(CBHMNumberCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CBHMNumberCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CBHMNumberCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CBHMNumberCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CBHMNumberCtrl)
	afx_msg BSTR GetDisplayMask();
	afx_msg void SetDisplayMask(LPCTSTR lpszNewValue);
	afx_msg BSTR GetMask();
	afx_msg void SetMask(LPCTSTR lpszNewValue);
	afx_msg BSTR GetText();
	afx_msg double GetValue();
	afx_msg void SetValue(double newValue);
	afx_msg OLE_COLOR GetBackColor();
	afx_msg void SetBackColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetForeColor();
	afx_msg void SetForeColor(OLE_COLOR nNewValue);
	afx_msg OLE_COLOR GetNegativeColor();
	afx_msg void SetNegativeColor(OLE_COLOR nNewValue);
	afx_msg short GetAlignment();
	afx_msg void SetAlignment(short nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CBHMNumberCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CBHMNumberCtrl)
	dispidDisplayMask = 1L,
	dispidMask = 2L,
	dispidText = 3L,
	dispidValue = 4L,
	dispidBackColor = 5L,
	dispidForeColor = 6L,
	dispidNegativeColor = 7L,
	dispidAlignment = 8L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BHMNUMBERCTL_H__B07953B3_7FF6_11D3_A7FE_0080C8763FA4__INCLUDED)
