#include <afxwin.h>
#pragma once


class CListHistory : public CListBox
{
public:
	CListHistory();
	virtual ~CListHistory();

protected:
	afx_msg void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct) override;
	afx_msg void MeasureItem(LPMEASUREITEMSTRUCT lpMeasureItemStruct) override;

private:
	CFont m_StandardFont;
	CFont m_BoldFont;

	DECLARE_MESSAGE_MAP()
};