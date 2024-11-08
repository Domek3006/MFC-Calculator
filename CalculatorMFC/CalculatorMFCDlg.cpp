
// CalculatorMFCDlg.cpp: plik implementacji
//

#include "pch.h"
#include "framework.h"
#include "CalculatorMFC.h"
#include "CalculatorMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Okno dialogowe CAboutDlg używane na potrzeby informacji o aplikacji

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dane okna dialogowego
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // obsługa DDX/DDV

// Implementacja
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// okno dialogowe CCalculatorMFCDlg



CCalculatorMFCDlg::CCalculatorMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATORMFC_DIALOG, pParent)
	, m_DisplayEquasion(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_RESULT, m_DisplayText);
	DDX_Text(pDX, IDC_STATIC_EQU, m_DisplayEquasion);
	DDX_Control(pDX, IDC_LIST_HISTORY, m_ListHistory);
}

BEGIN_MESSAGE_MAP(CCalculatorMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_1, &CCalculatorMFCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &CCalculatorMFCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &CCalculatorMFCDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, &CCalculatorMFCDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &CCalculatorMFCDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &CCalculatorMFCDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &CCalculatorMFCDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &CCalculatorMFCDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &CCalculatorMFCDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &CCalculatorMFCDlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_COMMA, &CCalculatorMFCDlg::OnBnClickedButtonComma)
	ON_BN_CLICKED(IDC_BUTTON_PLUS, &CCalculatorMFCDlg::OnBnClickedButtonPlus)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &CCalculatorMFCDlg::OnBnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULT, &CCalculatorMFCDlg::OnBnClickedButtonMult)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &CCalculatorMFCDlg::OnBnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_EQ, &CCalculatorMFCDlg::OnBnClickedButtonEq)
	ON_BN_CLICKED(IDC_BUTTON_CLR, &CCalculatorMFCDlg::OnBnClickedButtonClr)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &CCalculatorMFCDlg::OnBnClickedButtonSqrt)
	ON_STN_CLICKED(IDC_STATIC_RESULT, &CCalculatorMFCDlg::OnStnClickedStaticResult)
	ON_STN_CLICKED(IDC_STATIC_EQU, &CCalculatorMFCDlg::OnStnClickedStaticEqu)
	ON_BN_CLICKED(IDC_BUTTON_MEMORY, &CCalculatorMFCDlg::OnBnClickedButtonMemory)
	ON_BN_CLICKED(IDC_BUTTON_MSAVE, &CCalculatorMFCDlg::OnBnClickedButtonMemSave)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, &CCalculatorMFCDlg::OnBnClickedButtonSign)
	ON_BN_CLICKED(IDC_BUTTON_ERASE, &CCalculatorMFCDlg::OnBnClickedButtonErase)
	ON_COMMAND(ID_FILE_EXPORT, &CCalculatorMFCDlg::OnFileExport)
END_MESSAGE_MAP()


// Procedury obsługi komunikatów CCalculatorMFCDlg

BOOL CCalculatorMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Dodaj pozycję „Informacje...” do menu systemowego.

	// Element IDM_ABOUTBOX musi należeć do zakresu poleceń systemowych.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Ustaw ikonę dla tego okna dialogowego. Struktura wykonuje to automatycznie
	//  gdy okno główne aplikacji nie jest oknem dialogowym
	SetIcon(m_hIcon, TRUE);			// Ustaw duże ikony
	SetIcon(m_hIcon, FALSE);		// Ustaw małe ikony

	m_ResultFont.CreatePointFont(180, _T("Arial"));
	GetDlgItem(IDC_STATIC_RESULT)->SetFont(&m_ResultFont);
	m_DisplayText = '0';
	m_DisplayEquasion = "";
	UpdateData(FALSE);

	return TRUE;  // zwracaj wartość TRUE, dopóki fokus nie zostanie ustawiony na formant
}

void CCalculatorMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Jeśli dodasz przycisk minimalizacji do okna dialogowego, będziesz potrzebować poniższego kodu
//  aby narysować ikonę. Dla aplikacji MFC używających modelu dokumentu/widoku
//  to jest wykonywane automatycznie przez strukturę.

void CCalculatorMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // kontekst urządzenia dotyczący malowania

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Wyśrodkuj ikonę w prostokącie klienta
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Rysuj ikonę
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// System wywołuje tę funkcję, aby uzyskać kursor wyświetlany podczas przeciągania przez użytkownika
//  zminimalizowane okno.
HCURSOR CCalculatorMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CCalculatorMFCDlg::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case '0':
		case VK_NUMPAD0:
			OnBnClickedButton0();
			break;
		case '1':
		case VK_NUMPAD1:
			OnBnClickedButton1();
			break;
		case '2':
		case VK_NUMPAD2:
			OnBnClickedButton2();
			break;
		case '3':
		case VK_NUMPAD3:
			OnBnClickedButton3();
			break;
		case '4':
		case VK_NUMPAD4:
			OnBnClickedButton4();
			break;
		case '5':
		case VK_NUMPAD5:
			OnBnClickedButton5();
			break;
		case '6':
		case VK_NUMPAD6:
			OnBnClickedButton6();
			break;
		case '7':
		case VK_NUMPAD7:
			OnBnClickedButton7();
			break;
		case '8':
		case VK_NUMPAD8:
			OnBnClickedButton8();
			break;
		case '9':
		case VK_NUMPAD9:
			OnBnClickedButton9();
			break;
		case '+':
		case VK_ADD:
			OnBnClickedButtonPlus();
			break;
		case '-':
		case VK_SUBTRACT:
			OnBnClickedButtonMinus();
			break;
		case '*':
		case VK_MULTIPLY:
			OnBnClickedButtonMult();
			break;
		case '/':
		case VK_DIVIDE:
			OnBnClickedButtonDiv();
			break;
		case VK_DECIMAL:
			OnBnClickedButtonComma();
			break;
		case VK_BACK:
			OnBnClickedButtonErase();
			break;
		case VK_RETURN:
			OnBnClickedButtonEq();
			break;
		case 'S':
			if (GetKeyState(VK_CONTROL) & 0x8000) OnFileExport();
			break;
		default:
			return CDialogEx::PreTranslateMessage(pMsg);
		}
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CCalculatorMFCDlg::AppendToDisplay(TCHAR c)
{
	//CString text;
	

	//UpdateData(TRUE);

	if (!m_NextValue)
	{
		UpdateData(TRUE); //m_DisplayText.GetWindowText(text);
	}
	else {
		m_DisplayText = '0';
		if (m_Operator == '=') m_DisplayEquasion = "";
		m_NextValue = FALSE;
	}

	if (m_DisplayText.GetLength() == 1 && m_DisplayText[0] == '0' && c != '.') m_DisplayText.Empty();
	m_DisplayText += c;
	//m_DisplayText.SetWindowText(text);

	UpdateData(FALSE);
}

void CCalculatorMFCDlg::ProcessOperation()
{

	double result = 0.0;
	switch (m_Operator)
	{
	case '+':
		result = m_PrevValue + m_CurrentValue;
		break;
	case '-':
		result = m_PrevValue - m_CurrentValue;
		break;
	case '*':
		result = m_PrevValue * m_CurrentValue;
		break;
	case '/':
		if (m_CurrentValue == 0) 
		{
			MessageBox(_T("Division by zero!"));
			return;
		} 
		result = m_PrevValue / m_CurrentValue;
		break;
	default:
		result = m_CurrentValue;
		break;
	}
	m_PrevValue = result;
	CString str;
	str.Format(_T("%g"), result);
	m_DisplayText = str;

	//m_DisplayText.SetWindowText(str);

	UpdateData(FALSE);
}

void CCalculatorMFCDlg::UpdatePrevious()
{
	/*CString text;
	m_DisplayText.GetWindowText(text);*/
	CString str;
	UpdateData(TRUE);
	m_PrevValue = wcstod(m_DisplayText, NULL);
	m_NextValue = TRUE;
	str.Format(_T("%g"), m_CurrentValue);
	if((m_Operator == '*' || m_Operator == '/') && m_DisplayEquasion.FindOneOf(_T("+-")) != -1) m_DisplayEquasion = _T("(") + m_DisplayEquasion + str + _T(") ") + m_Operator + _T(" ");
	else m_DisplayEquasion += str + ' ' + m_Operator + ' ';
	UpdateData(FALSE);
}

void CCalculatorMFCDlg::UpdateCurrent()
{
	/*CString text;
	m_DisplayText.GetWindowText(text);*/
	UpdateData(TRUE);
	m_CurrentValue = wcstod(m_DisplayText, NULL);
	if (m_Operator == '=') m_DisplayEquasion = "";
	UpdateData(FALSE);
}

void CCalculatorMFCDlg::AddToHistory()
{
	m_ListHistory.AddString(m_DisplayEquasion + '\n' + m_DisplayText);
	//m_ListHistory.InsertString(0, m_DisplayEquasion + '\n' + m_DisplayText);
	m_ListHistory.SetCurSel(m_ListHistory.GetCount() - 1);
}

void CCalculatorMFCDlg::OnBnClickedButton1()
{
	AppendToDisplay(_T('1'));
}


void CCalculatorMFCDlg::OnBnClickedButton2()
{
	AppendToDisplay(_T('2'));
}


void CCalculatorMFCDlg::OnBnClickedButton3()
{
	AppendToDisplay(_T('3'));
}


void CCalculatorMFCDlg::OnBnClickedButton4()
{
	AppendToDisplay(_T('4'));
}


void CCalculatorMFCDlg::OnBnClickedButton5()
{
	AppendToDisplay(_T('5'));
}


void CCalculatorMFCDlg::OnBnClickedButton6()
{
	AppendToDisplay(_T('6'));
}


void CCalculatorMFCDlg::OnBnClickedButton7()
{
	AppendToDisplay(_T('7'));
}


void CCalculatorMFCDlg::OnBnClickedButton8()
{
	AppendToDisplay(_T('8'));
}

void CCalculatorMFCDlg::OnBnClickedButton9()
{
	AppendToDisplay(_T('9'));
}


void CCalculatorMFCDlg::OnBnClickedButton0()
{
	AppendToDisplay(_T('0'));
}


void CCalculatorMFCDlg::OnBnClickedButtonComma()
{
	//CString text;
	//m_DisplayText.GetWindowText(text);
	UpdateData(TRUE);
	if (m_NextValue & 1) AppendToDisplay(_T('0')); AppendToDisplay(_T('.'));
	if(m_DisplayText.Find('.') == -1) AppendToDisplay(_T('.'));
}


void CCalculatorMFCDlg::OnBnClickedButtonPlus()
{
	UpdateCurrent();
	if (m_Operator != '\0') ProcessOperation();
	m_Operator = '+';
	UpdatePrevious();
}


void CCalculatorMFCDlg::OnBnClickedButtonMinus()
{
	UpdateCurrent();
	if (m_Operator != '\0') ProcessOperation();
	m_Operator = '-';
	UpdatePrevious();
}


void CCalculatorMFCDlg::OnBnClickedButtonMult()
{
	UpdateCurrent();
	if (m_Operator != '\0') ProcessOperation();
	m_Operator = '*';
	UpdatePrevious();
}


void CCalculatorMFCDlg::OnBnClickedButtonDiv()
{
	UpdateCurrent();
	if (m_Operator != '\0') ProcessOperation();
	m_Operator = '/';
	UpdatePrevious();
}


void CCalculatorMFCDlg::OnBnClickedButtonEq()
{
	UpdateCurrent();
	ProcessOperation();
	m_Operator = '=';
	UpdatePrevious();
	AddToHistory();
}


void CCalculatorMFCDlg::OnBnClickedButtonClr()
{
	m_PrevValue = 0.0;
	m_CurrentValue = 0.0;
	m_Operator = '\0';
	m_DisplayText = '0';
	m_DisplayEquasion = "";
	UpdateData(FALSE);
}


void CCalculatorMFCDlg::OnBnClickedButtonSqrt()
{
	//CString text;
	//m_DisplayText.GetWindowText(text);
	UpdateData(TRUE);
	m_CurrentValue = wcstod(m_DisplayText, NULL);
	if (m_CurrentValue < 0)
	{
		MessageBox(_T("Cannot perform operation!"));
		return;
	}
	m_DisplayEquasion += _T("sqrt(") + m_DisplayText + _T(") =");
	m_CurrentValue = sqrt(m_CurrentValue);
	ProcessOperation();
	m_Operator = '=';
	UpdateData(TRUE);
	m_PrevValue = wcstod(m_DisplayText, NULL);
	AddToHistory();
	UpdateData(FALSE);
}


void CCalculatorMFCDlg::OnStnClickedStaticResult()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorMFCDlg::OnStnClickedStaticEqu()
{
	// TODO: Add your control notification handler code here
}


void CCalculatorMFCDlg::OnBnClickedButtonMemSave()
{
	UpdateData(TRUE);
	m_Memory = m_DisplayText;
}


void CCalculatorMFCDlg::OnBnClickedButtonMemory()
{
	m_DisplayText = m_Memory;
	UpdateData(FALSE);
}


void CCalculatorMFCDlg::OnBnClickedButtonSign()
{
	UpdateData(TRUE);
	if (m_DisplayText == '0') return;
	if (m_DisplayText[0] != '-') m_DisplayText = '-' + m_DisplayText;
	else m_DisplayText.Delete(0,1);
	UpdateData(FALSE);
}


void CCalculatorMFCDlg::OnBnClickedButtonErase()
{
	UpdateData(TRUE);
	int textLen = m_DisplayText.GetLength();
	if (textLen == 1) m_DisplayText = '0';
	else m_DisplayText.Delete(textLen - 1);
	UpdateData(FALSE);
}

void CCalculatorMFCDlg::OnFileExport()
{
	CFileDialog fileDlg(FALSE, _T("txt"), _T("MathExport.txt"), OFN_OVERWRITEPROMPT | OFN_HIDEREADONLY, _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||"));

	if (fileDlg.DoModal() == IDOK)
	{
		CString filePath = fileDlg.GetPathName();

		CStdioFile file;
		if (!file.Open(filePath, CFile::modeCreate | CFile::modeWrite | CFile::typeText))
		{
			AfxMessageBox(_T("Error opening file"));
			return;
		}

		CString itemText;
		int itemCount = m_ListHistory.GetCount();

		for (int i = 0; i < itemCount; ++i)
		{
			m_ListHistory.GetText(i, itemText);
			itemText.Replace(_T("\n"), _T(""));
			file.WriteString(itemText + _T("\n"));
		}

		file.Close();

		AfxMessageBox(_T("File saved successfully."));
	}
}
