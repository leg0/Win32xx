////////////////////////////////////////////////////
// Mainfrm.cpp


#include "resource.h"
#include "mainfrm.h"


// Definitions for the CMainFrame class
CMainFrame::CMainFrame()
{
	// Constructor for CMainFrame. Its called after CFrame's constructor

	//Set m_View as the view window of the frame
	SetView(m_View);

	// Set the registry key name, and load the initial window position
	// Use a registry key name like "CompanyName\\Application"
	LoadRegistrySettings(_T("Win32++\\PropertySheet Sample"));
}

CMainFrame::~CMainFrame()
{
	// Destructor for CMainFrame.
}

BOOL CMainFrame::OnCommand(WPARAM wParam, LPARAM /*lParam*/)
{
	// OnCommand responds to menu and and toolbar input

	switch(LOWORD(wParam))
	{
	case IDM_FILE_EXIT:
		// End the application
		::PostMessage(m_hWnd, WM_CLOSE, 0, 0);
		return TRUE;
	case IDM_MODELESS:
		// Permit only one Modeless property sheet
		if (!m_ModelessPS.IsWindow())
		{
			m_ModelessPS.AddPage(new CButtonPage(IDD_BUTTONS, _T("Buttons")));
			m_ModelessPS.AddPage(new CComboPage(IDD_COMBOBOXES, _T("Combo Boxes")));
			m_ModelessPS.SetTitle(_T("Modeless Property Sheet"));
			m_ModelessPS.Create(m_hWnd);
		}
		return TRUE;
	case IDM_MODAL:
		{
			CMyPropertySheet mps(_T("Modal Property Sheet"), m_hWnd);
			mps.AddPage(new CButtonPage(IDD_BUTTONS, _T("Buttons")));
			mps.AddPage(new CComboPage(IDD_COMBOBOXES, _T("Combo Boxes")));
			mps.DoModal();
		}
		return TRUE;
	case IDM_WIZARD:
		{
			CMyPropertySheet mps(NULL, m_hWnd);
			mps.AddPage(new CButtonPage(IDD_BUTTONS, _T("Buttons")));
			mps.AddPage(new CComboPage(IDD_COMBOBOXES, _T("Combo Boxes")));
			mps.SetWizardMode(TRUE);
			mps.DoModal();
		}
		return TRUE;
	case IDW_VIEW_STATUSBAR:
		OnViewStatusbar();
		return TRUE;
	case IDW_VIEW_TOOLBAR:
		OnViewToolbar();
		return TRUE;
	case IDM_HELP_ABOUT:
		// Display the help dialog
		OnHelp();
		return TRUE;
	}

	return FALSE;
}

void CMainFrame::OnCreate()
{
	// OnCreate controls the way the frame is created.
	// Overriding CFrame::Oncreate is optional.
	// The default for the following variables is TRUE

	// m_bShowIndicatorStatus = FALSE;	// Don't show statusbar indicators
	// m_bShowMenuStatus = FALSE;		// Don't show toolbar or menu status
	// m_bUseRebar = FALSE;				// Don't use rebars
	// m_bUseThemes = FALSE;            // Don't use themes
	// m_bUseToolbar = FALSE;			// Don't use a toolbar

	// call the base class function
	CFrame::OnCreate();
}

void CMainFrame::OnInitialUpdate()
{
	// The frame is now created.
	// Place any additional startup code here.

	TRACE(_T("Frame created\n"));
}

void CMainFrame::SetupToolbar()
{
	// Set the Resource IDs for the toolbar buttons
	AddToolbarButton( IDM_FILE_NEW   );
	AddToolbarButton( IDM_FILE_OPEN  );
	AddToolbarButton( IDM_FILE_SAVE  );
	AddToolbarButton( 0 );				// Separator
	AddToolbarButton( IDM_EDIT_CUT   );
	AddToolbarButton( IDM_EDIT_COPY  );
	AddToolbarButton( IDM_EDIT_PASTE );
	AddToolbarButton( 0 );				// Separator
	AddToolbarButton( IDM_FILE_PRINT );
	AddToolbarButton( 0 );				// Separator
	AddToolbarButton( IDM_HELP_ABOUT );
}

LRESULT CMainFrame::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
//	switch (uMsg)
//	{
		// Add case statements for each messages to be handled here
//	}

	// pass unhandled messages on for default processing
	return WndProcDefault(hWnd, uMsg, wParam, lParam);
}