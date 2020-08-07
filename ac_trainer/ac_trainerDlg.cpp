
// ac_trainerDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ac_trainer.h"
#include "ac_trainerDlg.h"
#include <stdlib.h>
#include <iostream>

#include "afxdialogex.h"
#include "cheats.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
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


// CactrainerDlg dialog



CactrainerDlg::CactrainerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AC_TRAINER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CactrainerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HEALTH, m_health);
	DDX_Control(pDX, IDC_SET_VALUES, m_setValues);
	DDX_Control(pDX, IDC_TOGGLE_CHEATS, m_toggleCheats);
}

BEGIN_MESSAGE_MAP(CactrainerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CactrainerDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK2, &CactrainerDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &CactrainerDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK4, &CactrainerDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK3, &CactrainerDlg::OnBnClickedCheck3)
	ON_EN_CHANGE(IDC_HEALTH, &CactrainerDlg::OnEnChangeHealth)
	ON_BN_CLICKED(IDC_BUTTON1, &CactrainerDlg::OnBnClickedButton1)
	ON_EN_ERRSPACE(IDC_HEALTH, &CactrainerDlg::OnErrspaceHealth)
	ON_BN_CLICKED(IDCANCEL, &CactrainerDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &CactrainerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &CactrainerDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CactrainerDlg message handlers

BOOL CactrainerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CFont font;
	font.CreateFontW(20,                        // nHeight
		0,                         // nWidth
		0,                         // nEscapement
		0,                         // nOrientation
		FW_NORMAL,                 // nWeight
		FALSE,                     // bItalic
		FALSE,                     // bUnderline
		0,                         // cStrikeOut
		ANSI_CHARSET,              // nCharSet
		OUT_DEFAULT_PRECIS,        // nOutPrecision
		CLIP_DEFAULT_PRECIS,       // nClipPrecision
		DEFAULT_QUALITY,           // nQuality
		DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
		_T("Arial"));                 // lpszFacename

	GetDlgItem(IDC_SET_VALUES)->SetFont(&font);
	GetDlgItem(IDC_TOGGLE_CHEATS)->SetFont(&font);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CactrainerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CactrainerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CactrainerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CactrainerDlg::OnBnClickedOk(void)
{
	
}

void CactrainerDlg::OnEnChangeHealth(void)
{

}

void CactrainerDlg::OnErrspaceHealth(void)
{

}

void CactrainerDlg::OnBnClickedCancel(void)
{
	CDialog::OnCancel();
}

void CactrainerDlg::OnBnClickedCheck2()
{
	if(cheats::inf_ammo()){
		SetDlgItemText(IDC_LOG, L"Enabled Infinite Ammo");
	}else{
		SetDlgItemText(IDC_LOG, L"Disabled Infinite Ammo");
	}
}


void CactrainerDlg::OnBnClickedCheck1()
{
	if (cheats::inf_health()) {
		SetDlgItemText(IDC_LOG, L"Enabled Infinite Health");
	}
	else {
		SetDlgItemText(IDC_LOG, L"Disabled Infinite Health");
	}
}


void CactrainerDlg::OnBnClickedCheck4()
{
	if (cheats::inf_jump()) {
		SetDlgItemText(IDC_LOG, L"Enabled Infinite Jump");
	}
	else {
		SetDlgItemText(IDC_LOG, L"Disabled Infinite Jump");
	}
}


void CactrainerDlg::OnBnClickedCheck3()
{
	if (cheats::inf_grenade()) {
		SetDlgItemText(IDC_LOG, L"Enabled Infinite Grenades");
	}
	else {
		SetDlgItemText(IDC_LOG, L"Disabled Infinite Grenades");
	}
}

void CactrainerDlg::OnBnClickedButton1()
{
	CString input;
	GetDlgItemText(IDC_HEALTH, input);
	BYTE int_input = _ttoi(input);

	if (cheats::set_health(int_input)) {
		SetDlgItemText(IDC_LOG, L"Set Health");
	}
	else {
		SetDlgItemText(IDC_LOG, L"Could Not Set Health");
	}
}

void CactrainerDlg::OnBnClickedButton3()
{
	CString input;
	GetDlgItemText(IDC_ARMOR, input);
	BYTE int_input = _ttoi(input);
	
	if (cheats::set_armor(int_input)) {
		SetDlgItemText(IDC_LOG, L"Set Armor");
	}
	else {
		SetDlgItemText(IDC_LOG, L"Could Not Set Armor");
	}
}


void CactrainerDlg::OnBnClickedButton2()
{
	CString input;
	GetDlgItemText(IDC_AMMO, input);
	BYTE int_input = _ttoi(input);

	if (cheats::set_ammo(int_input)) {
		SetDlgItemText(IDC_LOG, L"Set Ammo");
	}
	else {
		SetDlgItemText(IDC_LOG, L"Could Not Set Ammo");
	}
}
