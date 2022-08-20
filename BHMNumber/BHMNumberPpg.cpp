// BHMNumberPpg.cpp : Implementation of the CBHMNumberPropPage property page class.

#include "stdafx.h"
#include "BHMNumber.h"
#include "BHMNumberPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CBHMNumberPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CBHMNumberPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CBHMNumberPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CBHMNumberPropPage, "BHMNUMBER.BHMNumberPropPage.1",
	0xb07953a6, 0x7ff6, 0x11d3, 0xa7, 0xfe, 0, 0x80, 0xc8, 0x76, 0x3f, 0xa4)


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberPropPage::CBHMNumberPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CBHMNumberPropPage

BOOL CBHMNumberPropPage::CBHMNumberPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_BHMNUMBER_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberPropPage::CBHMNumberPropPage - Constructor

CBHMNumberPropPage::CBHMNumberPropPage() :
	COlePropertyPage(IDD, IDS_BHMNUMBER_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CBHMNumberPropPage)
	m_strDisplayMask = _T("");
	m_sAppearance = -1;
	m_nAlignment = -1;
	m_strMask = _T("");
	m_fValue = 0.0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberPropPage::DoDataExchange - Moves data between page and properties

void CBHMNumberPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CBHMNumberPropPage)
	DDP_CBString(pDX, IDC_COMBO_DISPLAYMASK, m_strDisplayMask, _T("DisplayMask") );
	DDX_CBString(pDX, IDC_COMBO_DISPLAYMASK, m_strDisplayMask);
	DDP_CBIndex(pDX, IDC_COMBO_APPEARANCE, m_sAppearance, _T("Appearance") );
	DDX_CBIndex(pDX, IDC_COMBO_APPEARANCE, m_sAppearance);
	DDP_CBIndex(pDX, IDC_COMBO_ALIGNMENT, m_nAlignment, _T("Alignment") );
	DDX_CBIndex(pDX, IDC_COMBO_ALIGNMENT, m_nAlignment);
	DDP_Text(pDX, IDC_EDIT_MASK, m_strMask, _T("Mask") );
	DDX_Text(pDX, IDC_EDIT_MASK, m_strMask);
	DDP_Text(pDX, IDC_EDIT_VALUE, m_fValue, _T("Value") );
	DDX_Text(pDX, IDC_EDIT_VALUE, m_fValue);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CBHMNumberPropPage message handlers
