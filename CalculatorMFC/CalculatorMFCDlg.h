
// CalculatorMFCDlg.h: plik nagłówkowy
//
#include "CListHistory.h"

#pragma once



// okno dialogowe CCalculatorMFCDlg
class CCalculatorMFCDlg : public CDialogEx
{

private:
	double m_CurrentValue = 0.0;
	double m_PrevValue = 0.0;
	char m_Operator = '\0';
	bool m_NextValue = FALSE;
	CString m_DisplayText;
	CString m_DisplayEquasion;
	CString m_Memory;
	CFont m_ResultFont;
	CListHistory m_ListHistory;

// Konstrukcja
public:
	CCalculatorMFCDlg(CWnd* pParent = nullptr);	// konstruktor standardowy

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR_DLG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// obsługa DDX/DDV
	BOOL PreTranslateMessage(MSG* pMsg) override;

// Implementacja
protected:
	HICON m_hIcon;

	// Wygenerowano funkcje mapy komunikatów
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void AppendToDisplay(TCHAR c);
	void ProcessOperation();
	void UpdatePrevious();
	void UpdateCurrent();
	void AddToHistory();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedButtonComma();
	afx_msg void OnBnClickedButtonPlus();
	afx_msg void OnBnClickedButtonMinus();
	afx_msg void OnBnClickedButtonMult();
	afx_msg void OnBnClickedButtonDiv();
	afx_msg void OnBnClickedButtonEq();
	afx_msg void OnBnClickedButtonClr();
	afx_msg void OnBnClickedButtonSqrt();
	afx_msg void OnStnClickedStaticResult();
	afx_msg void OnStnClickedStaticEqu();
	afx_msg void OnBnClickedButtonMemory();
	afx_msg void OnBnClickedButtonMemSave();
	afx_msg void OnBnClickedButtonSign();
	afx_msg void OnBnClickedButtonErase();
	afx_msg void OnFileExport();
};
