///////////////////////////////////////
// MyDialog.cpp

#include "stdafx.h"
#include "MyDialog.h"
#include "resource.h"


// Definitions for the CMyDialog class
CMyDialog::CMyDialog(UINT nResID) : CDialog(nResID)
{
	m_hInfo = (HICON)GetApp().LoadIcon(IDI_INFO);
}

CMyDialog::~CMyDialog()
{
	DestroyIcon(m_hInfo);
}

void CMyDialog::OnDestroy()
{
	// End the application
	::PostQuitMessage(0);
}

INT_PTR CMyDialog::DialogProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
//	switch (uMsg)
//	{

//	}

	// Pass unhandled messages on to parent DialogProc
	return DialogProcDefault(uMsg, wParam, lParam);
}

BOOL CMyDialog::OnCommand(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	switch (LOWORD(wParam))
    {
	case IDC_BUTTON1:	return OnButton();
	case IDC_RADIO1:	return OnRadio1();
	case IDC_RADIO2:	return OnRadio2();
	case IDC_RADIO3:	return OnRadio3();
	case IDC_CHECK1:	return OnCheck1();
	case IDC_CHECK2:	return OnCheck2();
	case IDC_CHECK3:	return OnCheck3();
    }

	return FALSE;
}

BOOL CMyDialog::OnInitDialog()
{
	// Set the Icon
	SetIconLarge(IDW_MAIN);
	SetIconSmall(IDW_MAIN);

	// Attach the edit control to m_Edit
	AttachItem(IDC_EDIT1, m_Edit);

	// Attach the rich edit control to m_RichEdit
	AttachItem(IDC_RICHEDIT1, m_RichEdit);

	// Put some text in the edit boxes
	SetDlgItemText(IDC_EDIT1, _T("Edit Control"));
	SetDlgItemText(IDC_RICHEDIT1, _T("Rich Edit Window"));

	// Put some text in the list box
	for (int i = 0 ; i < 8 ; i++)
		SendDlgItemMessage(IDC_LIST1, LB_ADDSTRING, 0, (LPARAM) _T("List Box"));

	// Create the bubble tooltip
	m_BubbleTT.Create(*this);

	// Set the background colour
	m_BubbleTT.SetWindowTheme(L" ", L" ");	// Turn XP themes off
	m_BubbleTT.SetTipBkColor(RGB(150, 255, 255));

	// Add controls to the bubble tooltip
	m_BubbleTT.AddTool(GetDlgItem(IDC_RADIO1), _T("Radio Button 1"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_RADIO2), _T("Radio Button 2"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_RADIO3), _T("Radio Button 3"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_BUTTON1), _T("Button 1"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_CHECK1), _T("Check Box 1"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_CHECK2), _T("Check Box 2"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_CHECK3), _T("Check Box 3"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_LIST1), _T("List Box"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_STATIC1), _T("Picture in a static control"));
	m_BubbleTT.AddTool(GetDlgItem(IDC_STATIC3), _T("Status display"));
	m_BubbleTT.AddTool(GetDlgItem(IDOK), _T("OK Button"));

	// Modify tooltip for IDC_RADIO3
	TOOLINFO ti1 = m_BubbleTT.GetToolInfo( GetDlgItem(IDC_RADIO3).GetHwnd());
	ti1.uFlags |= TTF_CENTERTIP;
	ti1.lpszText = (LPTSTR)_T("Modified tooltip for Radio Button 3");
	m_BubbleTT.SetToolInfo(ti1);

	// Create a standard tooltip for the Edit and RichEdit controls
	m_TT.Create(*this);

	// Set the background color
	m_TT.SetWindowTheme(L" ", L" ");	// Turn XP themes off
	m_TT.SetTipBkColor(RGB(255, 255, 125));

	// The tooltip will request the text to display via a TTN_GETDISPINFO notification
	m_TT.AddTool(m_Edit, LPSTR_TEXTCALLBACK);
	m_TT.AddTool(m_RichEdit, LPSTR_TEXTCALLBACK);


#ifdef	TTM_SETTITLE	// not supported by some GNU compilers
	// Add Title and Icon to the tooltip (a pretty icon for Vista and above)
	if (GetWinVersion() >= 2600)
		m_TT.SetTitle((UINT)m_hInfo, _T("Displaying the contents of the control ..."));
	else
		m_TT.SetTitle(TTI_INFO, _T("Displaying the contents of the control ..."));
#endif


	return true;
}

LRESULT CMyDialog::OnNotify(WPARAM, LPARAM lParam)
{
	switch (((LPNMHDR)lParam)->code)
	{
		case TTN_GETDISPINFO:
		{
			LPNMTTDISPINFO lpnmtdi = (LPNMTTDISPINFO)lParam;

			if (lpnmtdi->hdr.idFrom == (UINT_PTR)m_Edit.GetHwnd())
			{
				m_str = m_Edit.GetWindowText();
				if (m_str.IsEmpty()) m_str = "No text to display";
				lpnmtdi->lpszText = (LPTSTR)m_str.c_str();
			}
			else if (lpnmtdi->hdr.idFrom == (UINT_PTR)m_RichEdit.GetHwnd())
			{
				m_str = m_RichEdit.GetWindowText();
				if (m_str.IsEmpty()) m_str = "No text to display";
				lpnmtdi->lpszText = (LPTSTR)m_str.c_str();
			}
		}
	}

	return 0L;
}

void CMyDialog::OnOK()
{
	MessageBox(_T("OK Button Pressed.  Program will exit now."), _T("Button"), MB_OK);
	CDialog::OnOK();
}

BOOL CMyDialog::OnButton()
{
	SetDlgItemText(IDC_STATIC3, _T("Button Pressed"));
	TRACE("Button Pressed\n");
	return TRUE;
}

BOOL CMyDialog::OnCheck1()
{
	SetDlgItemText(IDC_STATIC3, _T("Check Box 1"));
	TRACE("Check Box 1\n");
	return TRUE;
}

BOOL CMyDialog::OnCheck2()
{
	SetDlgItemText(IDC_STATIC3, _T("Check Box 2"));
	TRACE("Check Box 2\n");
	return TRUE;
}

BOOL CMyDialog::OnCheck3()
{
	SetDlgItemText(IDC_STATIC3, _T("Check Box 3"));
	TRACE("Check Box 3\n");
	return TRUE;
}

BOOL CMyDialog::OnRadio1()
{
	SetDlgItemText(IDC_STATIC3, _T("Radio 1"));
	TRACE("Radio 1\n");
	return TRUE;
}

BOOL CMyDialog::OnRadio2()
{
	SetDlgItemText(IDC_STATIC3, _T("Radio 2"));
	TRACE("Radio 2\n");
	return TRUE;
}

BOOL CMyDialog::OnRadio3()
{
	SetDlgItemText(IDC_STATIC3, _T("Radio 3"));
	TRACE("Radio 3\n");
	return TRUE;
}

