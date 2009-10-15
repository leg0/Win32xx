///////////////////////////////////
// main.cpp

#include "../Win32++/wincore.h"


class CView : public CWnd
{
public:
	CView() {}
	virtual ~CView() {}
};


class CSimpleApp : public CWinApp
{
public:
	CSimpleApp() {}
    virtual ~CSimpleApp() {}
	virtual BOOL InitInstance();

private:
    CView m_View;
};

BOOL CSimpleApp::InitInstance()
{
    // Create the Window
    m_View.Create();

	return TRUE;
}

// Note:  This application doesn't end when the window is closed
// Refer to the tutorial documentation

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    // Start Win32++
    CSimpleApp MyApp;

	// Run the application
    return MyApp.Run();
}