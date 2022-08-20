// BHMNumberCtl.cpp : Implementation of the CBHMNumberCtrl ActiveX Control class.

#include "stdafx.h"
#include "BHMNumber.h"
#include "BHMNumberCtl.h"
#include "BHMNumberPpg.h"
#include <msstkppg.h>
#include "BHMNumEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define IDC_EDIT 1001

#define STOCKPROP_BACKCOLOR     0x00000001
#define STOCKPROP_CAPTION       0x00000002
#define STOCKPROP_FONT          0x00000004
#define STOCKPROP_FORECOLOR     0x00000008
#define STOCKPROP_TEXT          0x00000010
#define STOCKPROP_BORDERSTYLE   0x00000020
#define STOCKPROP_ENABLED       0x00000040
#define STOCKPROP_APPEARANCE    0x00000080

#define RELEASE(lpUnk) do \
	{ if ((lpUnk) != NULL) { (lpUnk)->Release(); (lpUnk) = NULL; } } while (0)

short AFXAPI _AfxShiftState();
void AFXAPI _AfxToggleBorderStyle(CWnd* pWnd);
void AFXAPI _AfxToggleAppearance(CWnd* pWnd);

IMPLEMENT_DYNCREATE(CBHMNumberCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CBHMNumberCtrl, COleControl)
	//{{AFX_MSG_MAP(CBHMNumberCtrl)
	ON_WM_CREATE()
	ON_WM_MOUSEACTIVATE()
	ON_WM_SETFOCUS()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CBHMNumberCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CBHMNumberCtrl)
	DISP_PROPERTY_EX(CBHMNumberCtrl, "DisplayMask", GetDisplayMask, SetDisplayMask, VT_BSTR)
	DISP_PROPERTY_EX(CBHMNumberCtrl, "Mask", GetMask, SetMask, VT_BSTR)
	DISP_PROPERTY_EX(CBHMNumberCtrl, "Text", GetText, SetNotSupported, VT_BSTR)
	DISP_PROPERTY_EX(CBHMNumberCtrl, "Value", GetValue, SetValue, VT_R8)
	DISP_PROPERTY_EX(CBHMNumberCtrl, "BackColor", GetBackColor, SetBackColor, VT_COLOR)
	DISP_PROPERTY_EX(CBHMNumberCtrl, "ForeColor", GetForeColor, SetForeColor, VT_COLOR)
	DISP_PROPERTY_EX(CBHMNumberCtrl, "NegativeColor", GetNegativeColor, SetNegativeColor, VT_COLOR)
	DISP_PROPERTY_EX(CBHMNumberCtrl, "Alignment", GetAlignment, SetAlignment, VT_I2)
	DISP_DEFVALUE(CBHMNumberCtrl, "Value")
	DISP_STOCKPROP_APPEARANCE()
	DISP_STOCKPROP_FONT()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CBHMNumberCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CBHMNumberCtrl, COleControl)
	//{{AFX_EVENT_MAP(CBHMNumberCtrl)
	EVENT_STOCK_CLICK()
	EVENT_STOCK_DBLCLICK()
	EVENT_STOCK_KEYDOWN()
	EVENT_STOCK_KEYPRESS()
	EVENT_STOCK_KEYUP()
	EVENT_STOCK_MOUSEMOVE()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CBHMNumberCtrl, 3)
	PROPPAGEID(CBHMNumberPropPage::guid)
	PROPPAGEID(CLSID_StockColorPage)
	PROPPAGEID(CLSID_StockFontPage)
END_PROPPAGEIDS(CBHMNumberCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CBHMNumberCtrl, "BHMNUMBER.BHMNumberCtrl.1",
	0xb07953a5, 0x7ff6, 0x11d3, 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CBHMNumberCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DBHMNumber =
		{ 0xb07953a3, 0x7ff6, 0x11d3, { 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4 } };
const IID BASED_CODE IID_DBHMNumberEvents =
		{ 0xb07953a4, 0x7ff6, 0x11d3, { 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwBHMNumberOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CBHMNumberCtrl, IDS_BHMNUMBER, _dwBHMNumberOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::CBHMNumberCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CBHMNumberCtrl

BOOL CBHMNumberCtrl::CBHMNumberCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_BHMNUMBER,
			IDB_BHMNUMBER,
			afxRegApartmentThreading,
			_dwBHMNumberOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// Licensing strings

static const TCHAR BASED_CODE _szLicFileName[] = _T("BHMNumber.lic");

static const WCHAR BASED_CODE _szLicString[] =
	L"Copyright (c) 1999 BHM";


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::CBHMNumberCtrlFactory::VerifyUserLicense -
// Checks for existence of a user license

BOOL CBHMNumberCtrl::CBHMNumberCtrlFactory::VerifyUserLicense()
{
	return AfxVerifyLicFile(AfxGetInstanceHandle(), _szLicFileName,
		_szLicString);
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::CBHMNumberCtrlFactory::GetLicenseKey -
// Returns a runtime licensing key

BOOL CBHMNumberCtrl::CBHMNumberCtrlFactory::GetLicenseKey(DWORD dwReserved,
	BSTR FAR* pbstrKey)
{
	if (pbstrKey == NULL)
		return FALSE;

	*pbstrKey = SysAllocString(_szLicString);
	return (*pbstrKey != NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::CBHMNumberCtrl - Constructor

CBHMNumberCtrl::CBHMNumberCtrl()
{
	InitializeIIDs(&IID_DBHMNumber, &IID_DBHMNumberEvents);

	m_hFont = NULL;
	m_pBrhBack = NULL;

	m_pEdit = NULL;
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::~CBHMNumberCtrl - Destructor

CBHMNumberCtrl::~CBHMNumberCtrl()
{
	if (m_pEdit)
	{
		m_pEdit->DestroyWindow();
		delete m_pEdit;
		m_pEdit = NULL;
	}

	IFont * pIfont = InternalGetFont().m_pFont;
	if (m_hFont)
	{
		pIfont->ReleaseHfont(m_hFont);
		m_hFont = NULL;
	}

	if (m_pBrhBack)
	{
		delete m_pBrhBack;
		m_pBrhBack = NULL;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::OnDraw - Drawing function

void CBHMNumberCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (AmbientUserMode())
	{
		m_pEdit->Invalidate();
		return;
	}

	pdc->FillSolidRect(&rcBounds, TranslateColor(m_clrBack));

	CFont * pOldFont = SelectStockFont(pdc);
	pdc->SetBkColor(TranslateColor(m_clrBack));
	pdc->SetTextColor(TranslateColor(m_pEdit->GetValue() < 0 ? m_clrNegative : m_clrFore));

	CString strText;
	m_pEdit->GetWindowText(strText);

	UINT nFormat = DT_SINGLELINE;

	if (m_nAlignment == 0)
		nFormat |= DT_LEFT;
	else if (m_nAlignment == 1)
		nFormat |= DT_RIGHT;
	else
		nFormat |= DT_CENTER;

	pdc->DrawText(strText, CRect(rcBounds), nFormat);

	pdc->SelectObject(pOldFont);
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::DoPropExchange - Persistence support

void CBHMNumberCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));

	ASSERT_POINTER(pPX, CPropExchange);
	ExchangeExtent(pPX);
	ExchangeStockProps(pPX);

	PX_String(pPX, "Mask", m_strMask, _T(""));
	PX_String(pPX, "DisplayMask", m_strDisplayMask, _T(""));
	PX_Double(pPX, "Value", m_fValue, 0.0);
	PX_Color(pPX, "BackColor", m_clrBack, GetSysColor(COLOR_WINDOW));
	PX_Color(pPX, "ForeColor", m_clrFore, RGB(0, 0, 0));
	PX_Color(pPX, "NegativeColor", m_clrNegative, RGB(0, 0, 0));
	PX_Short(pPX, "Alignment", m_nAlignment, 0);
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::OnResetState - Reset control to default state

void CBHMNumberCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	m_strMask.Empty();
	m_strDisplayMask.Empty();
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl::AboutBox - Display an "About" box to the user

void CBHMNumberCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_BHMNUMBER);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberCtrl message handlers

void CBHMNumberCtrl::OnFontChanged() 
{
	HFONT hFont;
	IFont * pIfont = InternalGetFont().m_pFont;
	
	if (pIfont->get_hFont(&hFont) == S_OK)
	{
		//release previous IFont interface pointer
		if (m_hFont)
			pIfont->ReleaseHfont(m_hFont);

		m_hFont = hFont;

		if (m_pEdit)
			m_pEdit->SendMessage(WM_SETFONT, (WPARAM)m_hFont, MAKELPARAM(TRUE, 0));
	}
	
	COleControl::OnFontChanged();
}

BOOL CBHMNumberCtrl::OnSetObjectRects(LPCRECT lpRectPos, LPCRECT lpRectClip) 
{
	if (AmbientUserMode() && m_pEdit)
		m_pEdit->SetWindowPos(&wndTop, 0, 0, lpRectPos->right - lpRectPos->left, 
		lpRectPos->bottom - lpRectPos->top, SWP_NOZORDER);
	
	return COleControl::OnSetObjectRects(lpRectPos, lpRectClip);
}

BOOL CBHMNumberCtrl::PreTranslateMessage(MSG* pMsg) 
{
	USHORT nCharShort;
	short nShiftState = _AfxShiftState();

	if (pMsg->hwnd == m_hWnd || ::IsChild(m_hWnd, pMsg->hwnd))
	switch (pMsg->message)
	{
	case WM_KEYDOWN:
		nCharShort = (USHORT)pMsg->wParam;
		FireKeyDown(&nCharShort, nShiftState);
		if (nCharShort == 0)
			return TRUE;

		pMsg->wParam = MAKEWPARAM(nCharShort, HIWORD(pMsg->wParam));

		if (nCharShort == VK_LEFT || nCharShort == VK_RIGHT || nCharShort == VK_UP || 
			nCharShort == VK_DOWN || nCharShort == VK_DELETE)
		{
			GetFocus()->SendMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
			return TRUE;
		}

		break;

	case WM_KEYUP:
		nCharShort = (USHORT)pMsg->wParam;
		FireKeyUp(&nCharShort, nShiftState);
		if (nCharShort == 0)
			return TRUE;

		pMsg->wParam = MAKEWPARAM(nCharShort, HIWORD(pMsg->wParam));

		if (nCharShort == VK_LEFT || nCharShort == VK_RIGHT || nCharShort == VK_UP || 
			nCharShort == VK_DOWN || nCharShort == VK_DELETE)
		{
			GetFocus()->SendMessage(pMsg->message, pMsg->wParam, pMsg->lParam);
			return TRUE;
		}
		
		break;

	case WM_CHAR:
		nCharShort = (USHORT)pMsg->wParam;
		FireKeyPress(&nCharShort);
		if (nCharShort == 0)
			return TRUE;

		pMsg->wParam = MAKEWPARAM(nCharShort, HIWORD(pMsg->wParam));
		
		break;
	}
	
	return COleControl::PreTranslateMessage(pMsg);
}

int CBHMNumberCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect rect;
	GetClientRect(&rect);
	
	m_pEdit = new CBHMNumEdit();

	DWORD dwStyle = ES_AUTOHSCROLL | WS_VISIBLE | WS_CHILD;
	if (m_nAlignment == 0)
		dwStyle |= ES_LEFT;
	else if (m_nAlignment == 1)
		dwStyle |= ES_RIGHT;
	else
		dwStyle |= ES_CENTER;

	m_pEdit->Create(dwStyle, rect, this, IDC_EDIT);

	if (!AmbientUserMode())
		m_pEdit->ShowWindow(SW_HIDE);

	m_pEdit->SetMask(m_strMask);
	m_pEdit->SetDisplayMask(m_strDisplayMask);
	m_pEdit->SetValue(m_fValue);

	return 0;
}

int CBHMNumberCtrl::OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message) 
{
	if (AmbientUserMode())
		OnActivateInPlace (TRUE, NULL);
	
	return COleControl::OnMouseActivate(pDesktopWnd, nHitTest, message);
}

BOOL CBHMNumberCtrl::IsValidMask(CString strMask)
{
	int nIntegralLen = 0, nDecimalLen = 0;
	BOOL bDecimal = FALSE;

	for (int i = 0; i < strMask.GetLength(); i ++)
	{
		TCHAR ch = strMask[i];

		if (ch != _T('#') && ch != _T('.'))
		{
			return FALSE;
		}
		else if (ch == _T('.'))
		{
			if (bDecimal)
				return FALSE;
			else
			{
				bDecimal = TRUE;
				if (strMask.GetLength() <= (i + 1) || strMask[i + 1] != _T('#'))
					return FALSE;
			}
		}
		else
		{
			if (bDecimal)
				nDecimalLen ++;
			else
				nIntegralLen ++;
		}
	}

	if (strMask.GetLength() && nIntegralLen == 0)
		return FALSE;

	return TRUE;
}

void CBHMNumberCtrl::OnSetFocus(CWnd* pOldWnd) 
{
	COleControl::OnSetFocus(pOldWnd);
	
	m_pEdit->SetFocus();
}

BSTR CBHMNumberCtrl::GetDisplayMask() 
{
	return m_strDisplayMask.AllocSysString();
}

void CBHMNumberCtrl::SetDisplayMask(LPCTSTR lpszNewValue) 
{
	CString strNewMask = lpszNewValue, strMask;
	int nSemiColon1 = 0, nSemiColon2 = -1;

	for (int i = 0; i < 2; i ++)
	{
		nSemiColon1 = nSemiColon2 + 1;
		nSemiColon2 = strNewMask.Find(_T(';'), nSemiColon1);
		if (nSemiColon2 == -1)
			nSemiColon2 = strNewMask.GetLength();

		strMask.Empty();
		if (nSemiColon2 && nSemiColon1 < strNewMask.GetLength())
			strMask = strNewMask.Mid(nSemiColon1, nSemiColon2 - nSemiColon1);

		if (!IsValidDisplayMask(strMask))
		{
			ThrowError(CTL_E_INVALIDPROPERTYVALUE, AFX_IDP_E_INVALIDPROPERTYVALUE);
		
			return;
		}
	}

	m_strDisplayMask = lpszNewValue;
	m_pEdit->SetDisplayMask(m_strMask);

	SetModifiedFlag();
	BoundPropertyChanged(dispidDisplayMask);
}

BSTR CBHMNumberCtrl::GetMask() 
{
	return m_strMask.AllocSysString();
}

void CBHMNumberCtrl::SetMask(LPCTSTR lpszNewValue) 
{
	if (!IsValidMask(lpszNewValue))
		ThrowError(CTL_E_INVALIDPROPERTYVALUE, AFX_IDP_E_INVALIDPROPERTYVALUE);

	m_strMask = lpszNewValue;
	m_pEdit->SetMask(m_strMask);

	SetModifiedFlag();
	BoundPropertyChanged(dispidMask);
}

void CBHMNumberCtrl::ExchangeStockProps(CPropExchange *pPX)
{
	BOOL bLoading = pPX->IsLoading();
	DWORD dwStockPropMask = GetStockPropMask();
	DWORD dwPersistMask = dwStockPropMask;

	PX_ULong(pPX, _T("_StockProps"), dwPersistMask);

	if (dwStockPropMask & (STOCKPROP_CAPTION | STOCKPROP_TEXT))
	{
		CString strText;

		if (dwPersistMask & (STOCKPROP_CAPTION | STOCKPROP_TEXT))
		{
			if (!bLoading)
				strText = InternalGetText();
			if (dwStockPropMask & STOCKPROP_CAPTION)
				PX_String(pPX, _T("Caption"), strText, _T(""));
			if (dwStockPropMask & STOCKPROP_TEXT)
				PX_String(pPX, _T("Text"), strText, _T(""));
		}
		if (bLoading)
		{
			TRY
				SetText(strText);
			END_TRY
		}
	}

	if (dwStockPropMask & STOCKPROP_FORECOLOR)
	{
		if (dwPersistMask & STOCKPROP_FORECOLOR)
			PX_Color(pPX, _T("ForeColor"), m_clrForeColor, AmbientForeColor());
		else if (bLoading)
			m_clrForeColor = AmbientForeColor();
	}

	if (dwStockPropMask & STOCKPROP_BACKCOLOR)
	{
		if (dwPersistMask & STOCKPROP_BACKCOLOR)
			PX_Color(pPX, _T("BackColor"), m_clrBackColor, GetSysColor(COLOR_WINDOW));
		else if (bLoading)
			m_clrBackColor = GetSysColor(COLOR_WINDOW);
	}

	if (dwStockPropMask & STOCKPROP_FONT)
	{
		LPFONTDISP pFontDispAmbient = AmbientFont();
		BOOL bChanged = TRUE;

		if (dwPersistMask & STOCKPROP_FONT)
			bChanged = PX_Font(pPX, _T("Font"), m_font, NULL, pFontDispAmbient);
		else if (bLoading)
			m_font.InitializeFont(NULL, pFontDispAmbient);

		if (bLoading && bChanged)
			OnFontChanged();

		RELEASE(pFontDispAmbient);
	}

	if (dwStockPropMask & STOCKPROP_BORDERSTYLE)
	{
		short sBorderStyle = m_sBorderStyle ? 1 : 0;

		if (dwPersistMask & STOCKPROP_BORDERSTYLE)
			PX_Short(pPX, _T("BorderStyle"), m_sBorderStyle, 1);
		else if (bLoading)
			m_sBorderStyle = 1;

		if (sBorderStyle != m_sBorderStyle)
			_AfxToggleBorderStyle(this);
	}

	if (dwStockPropMask & STOCKPROP_ENABLED)
	{
		BOOL bEnabled = m_bEnabled;

		if (dwPersistMask & STOCKPROP_ENABLED)
			PX_Bool(pPX, _T("Enabled"), m_bEnabled, TRUE);
		else if (bLoading)
			m_bEnabled = TRUE;

		if ((bEnabled != m_bEnabled) && (m_hWnd != NULL))
			::EnableWindow(m_hWnd, m_bEnabled);
	}

	if (dwStockPropMask & STOCKPROP_APPEARANCE)
	{
		short sAppearance = m_sAppearance ? 1 : 0;

		if (dwPersistMask & STOCKPROP_APPEARANCE)
			PX_Short(pPX, _T("Appearance"), m_sAppearance, 1);
		else if (bLoading)
			m_sAppearance = AmbientAppearance();

		if (sAppearance != m_sAppearance)
			_AfxToggleAppearance(this);
	}
}

BSTR CBHMNumberCtrl::GetText() 
{
	CString strResult;
	
	m_pEdit->GetWindowText(strResult);

	return strResult.AllocSysString();
}

double CBHMNumberCtrl::GetValue() 
{
	m_fValue = m_pEdit->GetValue();

	return m_fValue;
}

void CBHMNumberCtrl::SetValue(double newValue) 
{
	m_pEdit->SetValue(newValue);

	SetModifiedFlag();
	BoundPropertyChanged(dispidValue);
}

BOOL CBHMNumberCtrl::IsValidDisplayMask(CString strMask)
{
	int nIntegralLen = 0, nDecimalLen = 0;
	BOOL bDecimal = FALSE;
	BOOL bHasPrefix = FALSE, bHasSuffix = FALSE;

	for (int i = 0; i < strMask.GetLength(); i ++)
	{
		TCHAR ch = strMask[i];

		if (ch != _T('#') && ch != _T('.'))
		{
			if (!bHasPrefix)
			{
				if (nIntegralLen == 0)
					bHasPrefix = TRUE;
				else
					bHasSuffix = TRUE;
			}
			else
			{
				if (!nIntegralLen)
					continue;
				else if (!bHasSuffix)
					bHasSuffix = TRUE;
			}
		}
		else if (ch == _T('.'))
		{
			if (bDecimal || bHasSuffix)
				return FALSE;
			else
			{
				bDecimal = TRUE;
				if (strMask.GetLength() <= (i + 1) || strMask[i + 1] != _T('#'))
					return FALSE;
			}
		}
		else
		{
			if (bHasSuffix)
				return FALSE;

			if (bDecimal)
				nDecimalLen ++;
			else
				nIntegralLen ++;
		}
	}

	if (strMask.GetLength() && nIntegralLen == 0)
		return FALSE;

	return TRUE;
}

OLE_COLOR CBHMNumberCtrl::GetBackColor() 
{
	return m_clrBack;
}

void CBHMNumberCtrl::SetBackColor(OLE_COLOR nNewValue) 
{
	m_clrBack = nNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidBackColor);
	InvalidateControl();
}

OLE_COLOR CBHMNumberCtrl::GetForeColor() 
{
	return m_clrFore;
}

void CBHMNumberCtrl::SetForeColor(OLE_COLOR nNewValue) 
{
	m_clrFore = nNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidForeColor);
	InvalidateControl();
}

OLE_COLOR CBHMNumberCtrl::GetNegativeColor() 
{
	return m_clrNegative;
}

void CBHMNumberCtrl::SetNegativeColor(OLE_COLOR nNewValue) 
{
	m_clrNegative = nNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidNegativeColor);
	InvalidateControl();
}

HBRUSH CBHMNumberCtrl::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	if (m_pEdit && pWnd->m_hWnd == m_pEdit->m_hWnd && nCtlColor == CTLCOLOR_EDIT)
	{
		if (m_pBrhBack)
		{
			delete m_pBrhBack;
			m_pBrhBack = NULL;
		}

		m_pBrhBack = new CBrush(TranslateColor(m_clrBack));
		pDC->SetTextColor(TranslateColor(m_pEdit->GetValue() < 0 ? m_clrNegative : m_clrFore));
		pDC->SetBkColor(TranslateColor(m_clrBack));

		return (HBRUSH)*m_pBrhBack;
	}

	HBRUSH hbr = COleControl::OnCtlColor(pDC, pWnd, nCtlColor);

	return hbr;
}

short CBHMNumberCtrl::GetAlignment() 
{
	return m_nAlignment;
}

void CBHMNumberCtrl::SetAlignment(short nNewValue) 
{
	if (AmbientUserMode())
		ThrowError(CTL_E_SETNOTSUPPORTEDATRUNTIME, AFX_IDP_E_SETNOTSUPPORTEDATRUNTIME);

	m_nAlignment = nNewValue;

	SetModifiedFlag();
	BoundPropertyChanged(dispidAlignment);
	InvalidateControl();
}

BOOL CBHMNumberCtrl::OnGetPredefinedStrings(DISPID dispid, CStringArray* pStringArray, CDWordArray* pCookieArray) 
{
	if (dispid == DISPID_APPEARANCE)
	{
		CString strAppearance;
		strAppearance.LoadString(IDS_APPEARANCE_FLAT);
		pStringArray->Add(strAppearance);
		strAppearance.LoadString(IDS_APPEARANCE_3D);
		pStringArray->Add(strAppearance);

		pCookieArray->Add(0);
		pCookieArray->Add(1);

		return TRUE;
	}
	
	return COleControl::OnGetPredefinedStrings(dispid, pStringArray, pCookieArray);
}

BOOL CBHMNumberCtrl::OnGetPredefinedValue(DISPID dispid, DWORD dwCookie, VARIANT* lpvarOut) 
{
	if (dispid == DISPID_APPEARANCE)
	{
		VariantInit(lpvarOut);
		lpvarOut->vt = VT_I4;
		lpvarOut->lVal = dwCookie;

		return TRUE;
	}
	
	return COleControl::OnGetPredefinedValue(dispid, dwCookie, lpvarOut);
}
