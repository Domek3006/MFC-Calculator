#include "pch.h"
#include "CListHistory.h"

BEGIN_MESSAGE_MAP(CListHistory, CListBox)
	ON_WM_DRAWITEM_REFLECT()
	ON_WM_MEASUREITEM_REFLECT()
END_MESSAGE_MAP()

CListHistory::CListHistory()
{
	m_StandardFont.CreatePointFont(100, _T("Arial"));
	m_BoldFont.CreatePointFont(140, _T("Arial Bold"));
}

CListHistory::~CListHistory()
{
	m_StandardFont.DeleteObject();
	m_BoldFont.DeleteObject();
}

void CListHistory::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	if (lpDrawItemStruct->itemID == LB_ERR) return;
	
	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	if (lpDrawItemStruct->itemState & ODS_SELECTED)
	{
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(200, 200, 255));
	}
	else
	{
		dc.FillSolidRect(&lpDrawItemStruct->rcItem, RGB(255, 255, 255));
	}

	CString itemText;
	GetText(lpDrawItemStruct->itemID, itemText);

	int splitPos = itemText.Find(_T('\n'));
	CString line1 = itemText.Left(splitPos);
	CString line2 = itemText.Mid(splitPos + 1);

	dc.SelectObject(&m_StandardFont);
	dc.SetTextColor(RGB(0, 0, 0));
	dc.TextOut(lpDrawItemStruct->rcItem.right - dc.GetTextExtent(line1).cx - 5, lpDrawItemStruct->rcItem.top + 2, line1);

	dc.SelectObject(&m_BoldFont);
	dc.SetTextColor(RGB(0, 0, 0));
	dc.TextOutW(lpDrawItemStruct->rcItem.right - dc.GetTextExtent(line2).cx - 5, lpDrawItemStruct->rcItem.top + 20, line2);

	dc.Detach();
}

void CListHistory::MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct)
{
	lpMeasureItemStruct->itemHeight = 40;
}