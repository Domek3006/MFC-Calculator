
// CalculatorMFC.h: główny plik nagłówkowy aplikacji PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "dołącz nagłówek „pch.h” przed dołączeniem tego pliku na potrzeby optymalizacji PCH"
#endif

#include "resource.h"		// główne symbole


// CCalculatorMFCApp:
// Aby uzyskać implementację klasy, zobacz CalculatorMFC.cpp
//

class CCalculatorMFCApp : public CWinApp
{
public:
	CCalculatorMFCApp();

// Przesłania
public:
	virtual BOOL InitInstance();

// Implementacja

	DECLARE_MESSAGE_MAP()
};

extern CCalculatorMFCApp theApp;
