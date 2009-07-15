////////////////////////////////////////////////////
// Mainfrm.cpp


#include "resource.h"
#include "mainfrm.h"


// Definitions for the CMainFrame class
CMainFrame::CMainFrame() : m_nColor(IDM_BLUE), m_bUseThemes(TRUE), m_bBandColors(TRUE), m_bFlatStyle(FALSE),
							m_bBandsLeft(TRUE), m_bLockMenuBand(TRUE), m_bRoundBorders(TRUE),
                            m_bShortBands(TRUE), m_bUseLines(FALSE), m_bShowArrows(TRUE), m_bShowCards(TRUE)
{
	// Constructor for CMainFrame. Its called after CFrame's constructor

	//Set m_View as the view window of the frame
	SetView(m_View);

	// Set the registry key name, and load the initial window position
	// Use a registry key name like "CompanyName\\Application"
	LoadRegistrySettings(_T("Win32++\\Themes Sample"));
}

CMainFrame::~CMainFrame()
{
	// Destructor for CMainFrame.
}

void CMainFrame::AddCombo()
{ 
	// We'll be placing the ComboBoxEx control over the 'File Save' toolbar button
	int nComboWidth = 120; 
	CToolbar& TB = GetToolbar();
	if (TB.CommandToIndex(IDM_FILE_SAVE) < 0) return;
     
	TB.SetButtonStyle(IDM_FILE_SAVE, TBSTYLE_SEP);	// Convert the button to a seperator
	TB.SetButtonWidth(IDM_FILE_SAVE, nComboWidth);
	 
	// Determine the size and position of the ComboBox 
	int nIndex = TB.CommandToIndex(IDM_FILE_SAVE); 
	CRect rc = TB.GetItemRect(nIndex); 
	 
	// Create and position the ComboboxEx window 
	m_ComboBoxEx.Create(TB.GetHwnd());
	m_ComboBoxEx.SetWindowPos(NULL, rc, SWP_NOACTIVATE);

	// Set ComboBox Height
	m_ComboBoxEx.SendMessage(CB_SETITEMHEIGHT, (WPARAM)-1, (LPARAM)rc.Height()-6);
	
	m_ComboBoxEx.AddItems();
	RecalcLayout();
}

void CMainFrame::ChooseColor(UINT nColor)
{
	CToolbar& TB = GetToolbar();
	CMenubar& MB = GetMenubar();
	m_nColor = nColor;

	switch (nColor)
	{
	case IDM_BLUE:	// ICY_BLUE Theme
		{
			SetRebarTheme( RGB(150,190,245), RGB(196,215,250), RGB(220,230,250), RGB( 70,130,220) );

			ThemeToolbar tt = {TRUE, RGB(255, 230, 190), RGB(255, 190, 100), RGB(255, 140, 40), RGB(255, 180, 80), RGB(128, 128, 255)};
			TB.SetToolbarTheme(tt);
			Arrows.SetToolbarTheme(tt);
			Cards.SetToolbarTheme(tt);

			ThemeMenu tm = {TRUE, RGB(255, 230, 190), RGB(255, 190, 100), RGB(150,190,245), RGB(220,230,250), RGB(128, 128, 200)};
			if (IsRebarUsed()) MB.SetMenubarTheme(tm);
			SetMenuTheme(tm);
		}
		break;
	case IDM_GREY:	// Grey Theme
		{
			SetRebarTheme( RGB(210, 210, 200), RGB(238, 236, 224), RGB(248, 247, 243), RGB(195, 195, 172) );

			ThemeToolbar tt = {TRUE, RGB(192, 210, 238), RGB(192, 210, 238), RGB(152, 181, 226), RGB(152, 181, 226), RGB(49, 106, 197)};
			TB.SetToolbarTheme(tt);
			Arrows.SetToolbarTheme(tt);
			Cards.SetToolbarTheme(tt);

			ThemeMenu tm = {TRUE, RGB(196, 215, 250), RGB( 120, 180, 220), RGB(210, 210, 200), RGB(248, 247, 243), RGB(128, 128, 200)};
			if (IsRebarUsed()) MB.SetMenubarTheme(tm);
			SetMenuTheme(tm);
		}
		break;
	case IDM_OLIVE:
		{
			SetRebarTheme( RGB(160, 180, 80), RGB(180, 200, 100), RGB(200, 220, 120), RGB(80, 159, 78) );

			ThemeToolbar tt = {TRUE, RGB(255, 230, 190), RGB(255, 190, 100), RGB(255, 140, 40), RGB(255, 180, 80), RGB(128, 128, 255)};
			TB.SetToolbarTheme(tt);
			Arrows.SetToolbarTheme(tt);
			Cards.SetToolbarTheme(tt);

			ThemeMenu tm = {TRUE, RGB(255, 200, 190), RGB(255, 210, 90), RGB(255, 230, 190), RGB(230, 160, 190), RGB(128, 128, 128)};
			if (IsRebarUsed()) MB.SetMenubarTheme(tm);
			SetMenuTheme(tm);
		}
		break;
	case IDM_GOLD:
		{
			SetRebarTheme( RGB(230, 180, 0), RGB(240, 210, 90), RGB(255, 240, 150), RGB(180, 140, 50) );

			ThemeToolbar tt = {TRUE, RGB(192, 210, 238), RGB(192, 210, 238), RGB(152, 181, 226), RGB(152, 181, 226), RGB(49, 106, 197)};
			TB.SetToolbarTheme(tt);
			Arrows.SetToolbarTheme(tt);
			Cards.SetToolbarTheme(tt);

			ThemeMenu tm = {TRUE, RGB(196, 215, 250), RGB( 120, 180, 220), RGB(240, 210, 90), RGB(255, 240, 150), RGB(128, 128, 128)};
			if (IsRebarUsed()) MB.SetMenubarTheme(tm);
			SetMenuTheme(tm);
		}
		break;
	case IDM_OCHRE:
		{
			SetRebarTheme( RGB(248, 132, 12), RGB(248, 198, 10), RGB(248, 210, 20), RGB(248, 141, 6) );

			ThemeToolbar tt = {TRUE, RGB(192, 210, 238), RGB(192, 210, 238), RGB(152, 181, 226), RGB(152, 181, 226), RGB(49, 106, 197)};
			TB.SetToolbarTheme(tt);
			Arrows.SetToolbarTheme(tt);
			Cards.SetToolbarTheme(tt);

			ThemeMenu tm = {TRUE, RGB(196, 215, 250), RGB( 120, 180, 220), RGB(150,190,245), RGB(220,230,250), RGB(128, 128, 128)};
			if (IsRebarUsed()) MB.SetMenubarTheme(tm);
			SetMenuTheme(tm);
		}
		break;
	case IDM_PINK:
		{
			SetRebarTheme( RGB(255, 130, 190), RGB(250, 205, 235), RGB(250, 205, 235), RGB(255, 120, 170) );

			ThemeToolbar tt = {TRUE, RGB(192, 210, 238), RGB(192, 210, 238), RGB(248, 147, 220), RGB(248, 153, 179), RGB(49, 106, 197)};
			TB.SetToolbarTheme(tt);
			Arrows.SetToolbarTheme(tt);
			Cards.SetToolbarTheme(tt);

			ThemeMenu tm = {TRUE, RGB(196, 215, 250), RGB( 120, 180, 220), RGB(255, 130, 190), RGB(250, 205, 235), RGB(128, 128, 128)};
			if (IsRebarUsed()) MB.SetMenubarTheme(tm);
			SetMenuTheme(tm);
		}
		break;
	case IDM_MAUVE:
		{
			SetRebarTheme( RGB(210, 128, 155), RGB(230, 160, 190), RGB(230, 158, 188), RGB(110, 100, 125) );

			ThemeToolbar tt = {TRUE, RGB(192, 210, 238), RGB(192, 210, 238), RGB(152, 181, 226), RGB(152, 181, 226), RGB(49, 106, 197)};
			TB.SetToolbarTheme(tt);
			Arrows.SetToolbarTheme(tt);
			Cards.SetToolbarTheme(tt);

			ThemeMenu tm = {TRUE, RGB(196, 215, 250), RGB( 120, 180, 220), RGB(150,190,245), RGB(220,230,250), RGB(128, 128, 128)};
			if (IsRebarUsed()) MB.SetMenubarTheme(tm);
			SetMenuTheme(tm);
		}
		break;
	case IDM_BLACK:
		{
			SetRebarTheme( RGB(128, 138 ,176), RGB(98, 108 ,136), RGB(77, 87, 97), RGB(7, 17, 27) );
			
			ThemeToolbar tt = {TRUE, RGB(49, 106, 197), RGB(64,177,230), RGB(27,65, 160), RGB(64,177,230), RGB(49, 106, 197)};
			TB.SetToolbarTheme(tt);
			Arrows.SetToolbarTheme(tt);
			Cards.SetToolbarTheme(tt);

			ThemeMenu tm = {TRUE, RGB(84,197,240), RGB(89, 136, 217), RGB(59, 126, 197), RGB(94,187,230), RGB(128, 128, 128)};
			if (IsRebarUsed()) MB.SetMenubarTheme(tm);
			SetMenuTheme(tm);
		}
	}

	// Check the appropriate menu item
	int nFileItem = GetMenuItemPos(GetFrameMenu(), _T("Theme"));
	if (nFileItem >= 0)
	{
		HMENU hTheme = ::GetSubMenu(GetFrameMenu(), nFileItem);
		::CheckMenuRadioItem(hTheme, IDM_BLUE, IDM_BLACK, nColor, 0);
	}
  
	CheckMenuItem(GetFrameMenu(), IDM_USE_THEMES,    m_bUseThemes? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(GetFrameMenu(), IDM_BAND_COLORS,   m_bBandColors? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(GetFrameMenu(), IDM_FLAT_STYLE,    m_bFlatStyle? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(GetFrameMenu(), IDM_LEFT_BANDS,    m_bBandsLeft? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(GetFrameMenu(), IDM_LOCK_MENUBAR,  m_bLockMenuBand? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(GetFrameMenu(), IDM_ROUND_BORDERS, m_bRoundBorders? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(GetFrameMenu(), IDM_SHORT_BANDS,   m_bShortBands? MF_CHECKED : MF_UNCHECKED);
	CheckMenuItem(GetFrameMenu(), IDM_USE_LINES,     m_bUseLines? MF_CHECKED : MF_UNCHECKED);
	RecalcLayout();
}

DWORD CMainFrame::GetRegDwordFromOpenKey(HKEY hKey, LPCTSTR pName)
{
  DWORD   dwType;
  DWORD   dwCount = sizeof(DWORD);
  DWORD   dwValue = 0;
  if (ERROR_SUCCESS == RegQueryValueEx(hKey, pName, NULL, &dwType, (LPBYTE)&dwValue, &dwCount))
	  return dwValue;
  else 
	  return 0;
}

void CMainFrame::LoadRegistrySettings(LPCTSTR szKeyName)
{
	CFrame::LoadRegistrySettings(szKeyName);

	HKEY hKey;
	tString tsKey = _T("Software\\");
	tsKey += szKeyName;
	tsKey += (_T("\\Theme Settings"));
	
	if (ERROR_SUCCESS ==RegCreateKeyEx(HKEY_CURRENT_USER, tsKey.c_str(), 0, "", 
		REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL))
	{
		m_nColor = GetRegDwordFromOpenKey(hKey, _T("ColorStyle"));
		m_bUseThemes = GetRegDwordFromOpenKey(hKey, _T("UseThemes")) & 1;
		m_bBandColors = GetRegDwordFromOpenKey(hKey, _T("UseBandColors")) & 1;
		m_bFlatStyle = GetRegDwordFromOpenKey(hKey, _T("UseFlatStyle")) & 1;
		m_bBandsLeft = GetRegDwordFromOpenKey(hKey, _T("PutBandsLeft")) & 1;
		m_bLockMenuBand = GetRegDwordFromOpenKey(hKey, _T("LockMenuBand")) & 1;
		m_bRoundBorders = GetRegDwordFromOpenKey(hKey, _T("UseRoundBorders")) & 1;
		m_bShortBands = GetRegDwordFromOpenKey(hKey, _T("UseShortBands")) & 1;
		m_bUseLines = GetRegDwordFromOpenKey(hKey, _T("UseLines")) & 1;
		m_bShowArrows = GetRegDwordFromOpenKey(hKey, _T("ShowArrows")) & 1;
		m_bShowCards = GetRegDwordFromOpenKey(hKey, _T("ShowCards")) & 1;
		int nBands = GetRegDwordFromOpenKey(hKey, _T("NumBands"));
		
		// Retrieve the band styles and IDs
		for (int i = 0; i < nBands; ++i)
		{
			TCHAR szSubKey[16];
			wsprintf(szSubKey, _T("Band ID %d\0"), i+1);
			UINT nID = GetRegDwordFromOpenKey(hKey, szSubKey);
			m_vBandIDs.push_back(nID);
			
			wsprintf(szSubKey, _T("Band Style %d\0"), i+1);
			UINT nStyle = GetRegDwordFromOpenKey(hKey, szSubKey);
			m_vBandStyles.push_back(nStyle);
		}

		RegCloseKey(hKey);
	}
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
	case IDM_BLUE:
		ChooseColor(IDM_BLUE);
		return TRUE;
	case IDM_GREY:
		ChooseColor(IDM_GREY);
		return TRUE;
	case IDM_OLIVE:
		ChooseColor(IDM_OLIVE);
		return TRUE;
	case IDM_OCHRE:
		ChooseColor(IDM_OCHRE);
		return TRUE;
	case IDM_MAUVE:
		ChooseColor(IDM_MAUVE);
		return TRUE;
	case IDM_PINK:
		ChooseColor(IDM_PINK);
		return TRUE;
	case IDM_GOLD:
		ChooseColor(IDM_GOLD);
		return TRUE;
	case IDM_BLACK:
		ChooseColor(IDM_BLACK);
		return TRUE;
	case IDM_USE_THEMES:
		OnUseThemes();
		return TRUE;
	case IDM_BAND_COLORS:
		OnBandColors();
		return TRUE;
	case IDM_FLAT_STYLE:
		OnFlatStyle();
		return TRUE;
	case IDM_LEFT_BANDS:
		OnLeftBands();
		return TRUE;
	case IDM_LOCK_MENUBAR:
		OnLockMenubar();
		return TRUE;
	case IDM_ROUND_BORDERS:
		OnRoundBorders();
		return TRUE;
	case IDM_SHORT_BANDS:
		OnShortBands();
		return TRUE;
	case IDM_USE_LINES:
		OnUseLines();
		return TRUE;
	case IDM_VIEW_ARROWS:
		OnViewArrows();
		break;
	case IDM_VIEW_CARDS:
		OnViewCards();
		break;
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
	// m_bUseToolbar = FALSE;			// Don't use a toolbar

	// call the base class function
	CFrame::OnCreate();

	// Set the band styles and positions
	for (int i = 0; i < GetRebar().GetBandCount(); ++i)
	{
		if (i < (int)m_vBandStyles.size())
		{
			// Move the band to the correct position
			int iFrom = GetRebar().IDToIndex(m_vBandIDs[i]);
			GetRebar().MoveBand(iFrom, i);
		
			// Set the band's style
			REBARBANDINFO rbbi = {0};
			rbbi.fMask = RBBIM_STYLE;
			rbbi.fStyle = m_vBandStyles[i];
			GetRebar().SetBandInfo(i, rbbi);
		}
	}

	ShowArrows(m_bShowArrows);
	ShowCards(m_bShowCards);
}

void CMainFrame::OnInitialUpdate()
{
	// The frame is now created.
	// Place any additional startup code here.

	TRACE("Frame created\n");
}

LRESULT CMainFrame::OnNotify(WPARAM wParam, LPARAM lParam)
{
	// Process notification messages sent by child windows
//	switch(((LPNMHDR)lParam)->code)
//	{
 		//Add case statments for each notification message here
//	}

	// Pass any unhandled messages on for default processing
	return CFrame::OnNotify(wParam, lParam);
}

void CMainFrame::OnUseThemes()
{
	m_bUseThemes = !m_bUseThemes;
	BOOL bCheck = m_bUseThemes;
	::CheckMenuItem(GetFrameMenu(), IDM_USE_THEMES, MF_BYCOMMAND | (bCheck ? MF_CHECKED : MF_UNCHECKED));
	ThemeRebar tr = GetRebar().GetRebarTheme();
	tr.UseThemes = m_bUseThemes;
	GetRebar().SetRebarTheme(tr);
	
	GetRebar().RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	RecalcLayout();
}

void CMainFrame::OnBandColors()
{
	m_bBandColors = !m_bBandColors;
	BOOL bCheck = m_bBandColors;
	::CheckMenuItem(GetFrameMenu(), IDM_BAND_COLORS, MF_BYCOMMAND | (bCheck ? MF_CHECKED : MF_UNCHECKED));
	ChooseColor(m_nColor);

	GetRebar().RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	RecalcLayout();
}
void CMainFrame::OnFlatStyle()
{
	m_bFlatStyle = !m_bFlatStyle;
	BOOL bCheck = m_bFlatStyle;
	::CheckMenuItem(GetFrameMenu(), IDM_FLAT_STYLE, MF_BYCOMMAND | (bCheck ? MF_CHECKED : MF_UNCHECKED));
	ThemeRebar tr = GetRebar().GetRebarTheme();
	tr.FlatStyle = m_bFlatStyle;
	GetRebar().SetRebarTheme(tr);
	
	GetRebar().RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	RecalcLayout();
}
void CMainFrame::OnLeftBands()
{
	m_bBandsLeft = !m_bBandsLeft;
	BOOL bCheck = m_bBandsLeft;
	::CheckMenuItem(GetFrameMenu(), IDM_LEFT_BANDS, MF_BYCOMMAND | (bCheck ? MF_CHECKED : MF_UNCHECKED));
	ThemeRebar tr = GetRebar().GetRebarTheme();
	tr.BandsLeft = m_bBandsLeft;
	GetRebar().SetRebarTheme(tr);
	
	GetRebar().RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	RecalcLayout();
}
void CMainFrame::OnLockMenubar()
{
	m_bLockMenuBand = !m_bLockMenuBand;
	BOOL bCheck = m_bLockMenuBand;
	::CheckMenuItem(GetFrameMenu(), IDM_LOCK_MENUBAR, MF_BYCOMMAND | (bCheck ? MF_CHECKED : MF_UNCHECKED));
	ThemeRebar tr = GetRebar().GetRebarTheme();
	tr.LockMenuBand = m_bLockMenuBand;
	GetRebar().SetRebarTheme(tr);
	GetRebar().MoveBand(GetRebar().GetBand(GetMenubar()), 0);	// Move the Menubar to band 0
	
	GetRebar().RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	RecalcLayout();
}
void CMainFrame::OnRoundBorders()
{
	m_bRoundBorders = !m_bRoundBorders;
	BOOL bCheck = m_bRoundBorders;
	::CheckMenuItem(GetFrameMenu(), IDM_ROUND_BORDERS, MF_BYCOMMAND | (bCheck ? MF_CHECKED : MF_UNCHECKED));
	ThemeRebar tr = GetRebar().GetRebarTheme();
	tr.RoundBorders = m_bRoundBorders;
	GetRebar().SetRebarTheme(tr);
	
	GetRebar().RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	RecalcLayout();
}
void CMainFrame::OnShortBands()
{
	m_bShortBands = !m_bShortBands;
	BOOL bCheck = m_bShortBands;
	::CheckMenuItem(GetFrameMenu(), IDM_SHORT_BANDS, MF_BYCOMMAND | (bCheck ? MF_CHECKED : MF_UNCHECKED));
	ThemeRebar tr = GetRebar().GetRebarTheme();
	tr.ShortBands = m_bShortBands;
	GetRebar().SetRebarTheme(tr);
	
	GetRebar().RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	RecalcLayout();
}
void CMainFrame::OnUseLines()
{
	m_bUseLines = !m_bUseLines;
	BOOL bCheck = m_bUseLines;
	::CheckMenuItem(GetFrameMenu(), IDM_USE_LINES, MF_BYCOMMAND | (bCheck ? MF_CHECKED : MF_UNCHECKED));
	ThemeRebar tr = GetRebar().GetRebarTheme();
	tr.UseLines = m_bUseLines;
	GetRebar().SetRebarTheme(tr);
	
	GetRebar().RedrawWindow(0, 0, RDW_INVALIDATE|RDW_UPDATENOW|RDW_ERASE|RDW_ALLCHILDREN);
	RecalcLayout();
}

void CMainFrame::OnViewArrows()
{
	m_bShowArrows = !m_bShowArrows;
	ShowArrows(m_bShowArrows);
}

void CMainFrame::OnViewCards()
{
	m_bShowCards = !m_bShowCards;
	ShowCards(m_bShowCards);
}

void CMainFrame::SaveRegistrySettings()
{
	CFrame::SaveRegistrySettings();

	HKEY hKey;
	tString szKeyName = GetRegistryKeyName();
	tString tsKey = _T("Software\\");
	tsKey += szKeyName + (_T("\\Theme Settings"));
	int nBands = GetRebar().GetBandCount();

	RegCreateKeyEx(HKEY_CURRENT_USER, tsKey.c_str(), 0, "", 
		REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

	// Save the theme settings
	RegSetValueEx(hKey, _T("ColorStyle"), NULL, REG_DWORD, (LPBYTE)&m_nColor, sizeof(DWORD));
	RegSetValueEx(hKey, _T("UseThemes"), NULL, REG_DWORD, (LPBYTE)&m_bUseThemes, sizeof(DWORD));
	RegSetValueEx(hKey, _T("UseBandColors"), NULL, REG_DWORD, (LPBYTE)&m_bBandColors, sizeof(DWORD));
	RegSetValueEx(hKey, _T("UseFlatStyle"), NULL, REG_DWORD, (LPBYTE)&m_bFlatStyle, sizeof(DWORD));
	RegSetValueEx(hKey, _T("PutBandsLeft"), NULL, REG_DWORD, (LPBYTE)&m_bBandsLeft, sizeof(DWORD));
	RegSetValueEx(hKey, _T("LockMenuBand"), NULL, REG_DWORD, (LPBYTE)&m_bLockMenuBand, sizeof(DWORD));
	RegSetValueEx(hKey, _T("UseRoundBorders"), NULL, REG_DWORD, (LPBYTE)&m_bRoundBorders, sizeof(DWORD));
	RegSetValueEx(hKey, _T("UseShortBands"), NULL, REG_DWORD, (LPBYTE)&m_bShortBands, sizeof(DWORD));
	RegSetValueEx(hKey, _T("UseLines"), NULL, REG_DWORD, (LPBYTE)&m_bUseLines, sizeof(DWORD));
	RegSetValueEx(hKey, _T("ShowArrows"), NULL, REG_DWORD, (LPBYTE)&m_bShowArrows, sizeof(DWORD));
	RegSetValueEx(hKey, _T("ShowCards"), NULL, REG_DWORD, (LPBYTE)&m_bShowCards, sizeof(DWORD));
	RegSetValueEx(hKey, _T("NumBands"), NULL, REG_DWORD, (LPBYTE)&nBands, sizeof(DWORD));

	// Save the rebar band settings
	REBARBANDINFO rbbi = {0};
	rbbi.fMask = RBBIM_ID|RBBIM_STYLE;
	
	for (int i = 0; i < nBands; i++)
	{
		GetRebar().GetBandInfo(i, rbbi);
		UINT nID = rbbi.wID;
		UINT nStyle = rbbi.fStyle;
		
		TCHAR szSubKey[16];
		wsprintf(szSubKey, _T("Band ID %d\0"), i+1);
		RegSetValueEx(hKey, szSubKey, NULL, REG_DWORD, (LPBYTE)&nID, sizeof(DWORD));
		wsprintf(szSubKey, _T("Band Style %d\0"), i+1);
		RegSetValueEx(hKey, szSubKey, NULL, REG_DWORD, (LPBYTE)&nStyle, sizeof(DWORD));
	}

	RegCloseKey(hKey);
}

void CMainFrame::SetRebarTheme(COLORREF clrBkGnd1, COLORREF clrBkGnd2, COLORREF clrBand1, COLORREF clrBand2)
{
	ThemeRebar tr = {0};
	tr.UseThemes = m_bUseThemes;
	tr.clrBkgnd1 = clrBkGnd1;
	tr.clrBkgnd2 = clrBkGnd2;
	tr.clrBand1  = clrBand1;
	tr.clrBand2  = clrBand2;
	tr.FlatStyle = m_bFlatStyle;
	tr.BandsLeft = m_bBandsLeft;		
	tr.LockMenuBand = m_bLockMenuBand;
	tr.RoundBorders = m_bRoundBorders;
	tr.ShortBands = m_bShortBands;
	tr.UseLines = m_bUseLines;

	if (!m_bBandColors)
	{
		tr.clrBand1 = 0;
		tr.clrBand2 = 0;
	} 

	GetRebar().SetRebarTheme(tr);
}

void CMainFrame::SetupToolbar()
{
	// Set the Resource IDs for the first toolbar buttons
	AddToolbarButton( IDM_FILE_NEW   );
	AddToolbarButton( IDM_FILE_OPEN  );
	AddToolbarButton( 0 );				// Separator
	AddToolbarButton( IDM_FILE_SAVE  );
	AddToolbarButton( 0 );				// Separator
	AddToolbarButton( IDM_EDIT_CUT   );
	AddToolbarButton( IDM_EDIT_COPY  );
	AddToolbarButton( IDM_EDIT_PASTE );
	AddToolbarButton( 0 );				// Separator
	AddToolbarButton( IDM_FILE_PRINT );
	AddToolbarButton( 0 );				// Separator
	AddToolbarButton( IDM_HELP_ABOUT );

	// Set the three image lists for the first toolbar
	SetToolbarImages(RGB(255, 0, 255), IDB_TOOLBAR_NORM, IDB_TOOLBAR_HOT, IDB_TOOLBAR_DIS);

	// Add the two other toolbars if we use rebars
	if (IsRebarUsed())
	{
		//Set our theme
		ChooseColor(m_nColor);

		// Add the Arrows toolbar
		AddToolbarBand(Arrows, 0, IDC_ARROWS);
		Arrows.AddToolbarButton(IDM_ARROW_LEFT);
		Arrows.AddToolbarButton(IDM_ARROW_RIGHT);
		Arrows.SetImages(RGB(255,0,255), IDB_ARROWS, 0, 0);
		
		// Add the Cards toolbar
		AddToolbarBand(Cards, 0, IDC_CARDS);
		Cards.AddToolbarButton(IDM_CARD_CLUB);
		Cards.AddToolbarButton(IDM_CARD_DIAMOND);
		Cards.AddToolbarButton(IDM_CARD_HEART);
		Cards.AddToolbarButton(IDM_CARD_SPADE);
		Cards.SetImages(RGB(255,0,255), IDB_CARDS, 0, 0);
	}

	AddCombo();
}

void CMainFrame::ShowArrows(BOOL bShow)
{
	UINT uCheck = bShow? MF_CHECKED: MF_UNCHECKED;
	
	::CheckMenuItem (GetFrameMenu(), IDM_VIEW_ARROWS, uCheck);
	GetRebar().SendMessage(RB_SHOWBAND, GetRebar().GetBand(Arrows), bShow);
	
	if (GetRebar().GetRebarTheme().UseThemes && GetRebar().GetRebarTheme().BandsLeft)
		GetRebar().MoveBandsLeft();
}

void CMainFrame::ShowCards(BOOL bShow)
{
	UINT uCheck = bShow? MF_CHECKED: MF_UNCHECKED;
	
	::CheckMenuItem (GetFrameMenu(), IDM_VIEW_CARDS, uCheck);
	GetRebar().SendMessage(RB_SHOWBAND, GetRebar().GetBand(Cards), bShow);

	if (GetRebar().GetRebarTheme().UseThemes && GetRebar().GetRebarTheme().BandsLeft)
		GetRebar().MoveBandsLeft();
}

LRESULT CMainFrame::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
//	switch (uMsg)
//	{
//		Add case statements for each messages to be handled here
//	}

//	pass unhandled messages on for default processing
	return WndProcDefault(hWnd, uMsg, wParam, lParam);
}

