// BHMNumEdit.cpp : implementation file
//

#include "stdafx.h"
#include "BHMNumber.h"
#include "BHMNumEdit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBHMNumEdit

CBHMNumEdit::CBHMNumEdit()
{
	m_nIntegralDigits = 5;
	m_nDecimalDigits = 2;

	m_strNegativePrefix = _T('-');
}

CBHMNumEdit::~CBHMNumEdit()
{
}


BEGIN_MESSAGE_MAP(CBHMNumEdit, CNumEdit)
	//{{AFX_MSG_MAP(CBHMNumEdit)
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBHMNumEdit message handlers

void CBHMNumEdit::OnSetFocus(CWnd* pOldWnd) 
{
	CNumEdit::OnSetFocus(pOldWnd);
	
	CalcText(TRUE);
}

void CBHMNumEdit::OnKillFocus(CWnd* pNewWnd) 
{
	CNumEdit::OnKillFocus(pNewWnd);
	
	CalcText(FALSE);
}

void CBHMNumEdit::SetMask(CString strMask)
{
	int nIntegralLen = 0, nDecimalLen = 0;
	BOOL bDecimal = FALSE;

	for (int i = 0; i < strMask.GetLength(); i ++)
	{
		TCHAR ch = strMask[i];

		if (ch == _T('.'))
			bDecimal = TRUE;
		else
		{
			if (bDecimal)
				nDecimalLen ++;
			else
				nIntegralLen ++;
		}
	}

	if (nIntegralLen)
		m_nIntegralDigits = nIntegralLen;
	else if (strMask.IsEmpty())
		m_nIntegralDigits = 5;
	
	if (strMask.IsEmpty())
		m_nDecimalDigits = 2;
	else
		m_nDecimalDigits = nDecimalLen;

	m_nIntegralLen = (m_nIntegralDigits ? m_nIntegralDigits : 1) + (m_nIntegralDigits - 1) / 3;
	m_nDecimalLen = m_nDecimalDigits;
	
	if (GetFocus() == this)
		CalcText(TRUE);
}

void CBHMNumEdit::SetDisplayMask(CString strNewMask)
{
	CString strMask;
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

		CalcDisplayMask(strMask, i);
	}
}

void CBHMNumEdit::CalcText(BOOL bIsFocused)
{
	CString strText;
	strText.Format("%f", m_fValue);
	CNumEdit::CalcText(strText);
	GetWindowText(strText);

	if (!bIsFocused)
	{

		if (m_fValue > 0)
		{
			strText = m_strPositivePrefix + strText;
			strText += m_strPositiveSuffix;
		}
		else if (m_fValue < 0)
		{
			strText.Delete(0);
			strText = m_strNegativePrefix + strText;
			strText += m_strNegativeSuffix;
		}

		SetWndText(strText);
	}
}

double CBHMNumEdit::GetValue()
{
	return m_fValue;
}

void CBHMNumEdit::SetValue(double fValue)
{
	m_fValue = fValue;

	CalcText(GetFocus() == this);
}

void CBHMNumEdit::CalcDisplayMask(CString strMask, int i)
{
	CString strPrefix, strSuffix;
	int nFirst, nEnd;
	
	if (strMask.GetLength())
	{
		nFirst = strMask.Find(_T('#'));
		if (nFirst == -1)
			nFirst = strMask.GetLength() - 1;

		nEnd = strMask.ReverseFind(_T('#'));
		if (nEnd == -1)
			nEnd = strMask.GetLength();

		strPrefix = strMask.Left(nFirst);
		if (nEnd < strMask.GetLength())
			strSuffix = strMask.Right(strMask.GetLength() - nEnd - 1);
	}

	if (i == 0)
	{
		m_strPositivePrefix = strPrefix;
		m_strPositiveSuffix = strSuffix;
	}
	else if (i == 1)
	{
		m_strNegativePrefix = strPrefix;
		m_strNegativeSuffix = strSuffix;
	}
}

void CBHMNumEdit::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CNumEdit::OnLButtonDown(nFlags, point);

	MoveRight();
}
