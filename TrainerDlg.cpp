// TrainerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StrongholdTrainer.h"
#include "TrainerDlg.h"
#include "ModuleInstance.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

typedef struct
{
	void*	pAddr;		// Address of item
} GAME_TABLE;

// The table of items
GAME_TABLE gaTable2[] = {	(void*)0xB21BA4,		// Wood
							(void*)0xB21BA8,		// Hops
							(void*)0xB21BAC,		// Stone
							(void*)0xB21BB0,		// Animal Skins
							(void*)0xB21BB4,		// Iron
							(void*)0xB21BB8,		// Pitch
							(void*)0xB21BBC,		// Unknown
							(void*)0xB21BC0,		// Wheat
							(void*)0xB21BC4,		// Bread
							(void*)0xB21BC8,		// Cheese
							(void*)0xB21BCC,		// Meat
							(void*)0xB21BD0,		// Fruit
							(void*)0xB21BD4,		// Ale
							(void*)0xB21BD8,		// Gold
							(void*)0xB21BDC,		// Flour
							(void*)0xB21BE0,		// Bow
							(void*)0xB21BE4,		// Cross Bow
							(void*)0xB21BE8,		// Spear
							(void*)0xB21BEC,		// Pike
							(void*)0xB21BF0,		// Mace
							(void*)0xB21BF4,		// Sword
							(void*)0xB21BF8,		// Leather Armor
							(void*)0xB21BFC,		// Metal Armor
							(void*)0xB21C3C		// Current Gold
						}; 

#define VER10_OFFSET	(-0x2840)
#define CRUSADER_OFFSET (-0x23c52c)

#define IDX_WOOD		0
#define IDX_HOPS		1
#define IDX_STONE		2
#define IDX_ANI_SKINS	3
#define IDX_IRON		4
#define IDX_PITCH		5
#define IDX_UNKNOWN		6
#define IDX_WHEAT		7
#define IDX_BREAD		8
#define IDX_CHEESE		9
#define IDX_MEAT		10
#define IDX_FRUIT		11
#define IDX_ALE			12
#define IDX_GOLD		13
#define IDX_FLOUR		14
#define IDX_BOW			15
#define IDX_CROSS_BOW	16
#define IDX_SPEAR		17
#define IDX_PIKE		18
#define IDX_MACE		19
#define IDX_SWORD		20
#define IDX_LEATHER_ARMOR	21
#define IDX_METAL_ARMOR		22
#define IDX_GOLD_CURRENT	23

#define IDX_LAST_INDEX		23

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrainerDlg dialog

CTrainerDlg::CTrainerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTrainerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTrainerDlg)
	m_iStoneVal = 0;
	m_iWoodVal = 0;
	m_iIronVal = 0;
	m_iPitchVal = 0;
	m_iAleVal = 0;
	m_iFlourVal = 0;
	m_iWheatVal = 0;
	m_iAniSkinsVal = 0;
	m_iHopsVal = 0;
	m_iMeatVal = 0;
	m_iFruitVal = 0;
	m_iBreadVal = 0;
	m_iCheeseVal = 0;
	m_iSwordVal = 0;
	m_iBowVal = 0;
	m_iCrossBowVal = 0;
	m_iSpearVal = 0;
	m_iPikeVal = 0;
	m_iMaceVal = 0;
	m_iLeatherArmorVal = 0;
	m_iMetalArmorVal = 0;
	m_iCurGoldVal = 0;
	m_bFreezeMoney = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTrainerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTrainerDlg)
	DDX_Text(pDX, IDC_STONE_VAL, m_iStoneVal);
	DDX_Text(pDX, IDC_WOOD_VAL, m_iWoodVal);
	DDX_Text(pDX, IDC_IRON_VAL, m_iIronVal);
	DDX_Text(pDX, IDC_PITCH_VAL, m_iPitchVal);
	DDX_Text(pDX, IDC_ALE_VAL, m_iAleVal);
	DDX_Text(pDX, IDC_FLOUR_VAL, m_iFlourVal);
	DDX_Text(pDX, IDC_WHEAT_VAL, m_iWheatVal);
	DDX_Text(pDX, IDC_ANISKINS_VAL, m_iAniSkinsVal);
	DDX_Text(pDX, IDC_HOPS_VAL, m_iHopsVal);
	DDX_Text(pDX, IDC_MEAT_VAL, m_iMeatVal);
	DDX_Text(pDX, IDC_FRUIT_VAL, m_iFruitVal);
	DDX_Text(pDX, IDC_BREAD_VAL, m_iBreadVal);
	DDX_Text(pDX, IDC_CHEESE_VAL, m_iCheeseVal);
	DDX_Text(pDX, IDC_SWORD_VAL, m_iSwordVal);
	DDX_Text(pDX, IDC_BOW_VAL, m_iBowVal);
	DDX_Text(pDX, IDC_CROSSBOW_VAL, m_iCrossBowVal);
	DDX_Text(pDX, IDC_SPEAR_VAL, m_iSpearVal);
	DDX_Text(pDX, IDC_PIKE_VAL, m_iPikeVal);
	DDX_Text(pDX, IDC_MACE_VAL, m_iMaceVal);
	DDX_Text(pDX, IDC_LEATHERARM_VAL, m_iLeatherArmorVal);
	DDX_Text(pDX, IDC_METALARM_VAL, m_iMetalArmorVal);
	DDX_Text(pDX, IDC_GOLD_VAL, m_iCurGoldVal);
	DDX_Check(pDX, IDC_CHK_FREEZE_MONEY, m_bFreezeMoney);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTrainerDlg, CDialog)
	//{{AFX_MSG_MAP(CTrainerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_SETWOODZERO, OnSetwoodzero)
	ON_BN_CLICKED(IDC_INCWOOD10, OnIncwood10)
	ON_BN_CLICKED(IDC_INCWOOD100, OnIncwood100)
	ON_BN_CLICKED(IDC_SETSTONEZERO, OnSetstonezero)
	ON_BN_CLICKED(IDC_INCSTONE10, OnIncstone10)
	ON_BN_CLICKED(IDC_INCSTONE100, OnIncstone100)
	ON_BN_CLICKED(IDC_SETIRONZERO, OnSetironzero)
	ON_BN_CLICKED(IDC_INCIRON10, OnInciron10)
	ON_BN_CLICKED(IDC_INCIRON100, OnInciron100)
	ON_BN_CLICKED(IDC_SETPITCHZERO, OnSetpitchzero)
	ON_BN_CLICKED(IDC_SETALEZERO, OnSetalezero)
	ON_BN_CLICKED(IDC_INCPITCH10, OnIncpitch10)
	ON_BN_CLICKED(IDC_INCPITCH100, OnIncpitch100)
	ON_BN_CLICKED(IDC_INCALE10, OnIncale10)
	ON_BN_CLICKED(IDC_INCALE100, OnIncale100)
	ON_BN_CLICKED(IDC_SETFLOURZERO, OnSetflourzero)
	ON_BN_CLICKED(IDC_SETWHEATZERO, OnSetwheatzero)
	ON_BN_CLICKED(IDC_SETHOPSZERO, OnSethopszero)
	ON_BN_CLICKED(IDC_SETANISKINSZERO, OnSetaniskinszero)
	ON_BN_CLICKED(IDC_INCFLOUR10, OnIncflour10)
	ON_BN_CLICKED(IDC_INCFLOUR100, OnIncflour100)
	ON_BN_CLICKED(IDC_INCWHEAT10, OnIncwheat10)
	ON_BN_CLICKED(IDC_INCWHEAT100, OnIncwheat100)
	ON_BN_CLICKED(IDC_INCHOPS10, OnInchops10)
	ON_BN_CLICKED(IDC_INCANISKINS10, OnIncaniskins10)
	ON_BN_CLICKED(IDC_INCANISKINS100, OnIncaniskins100)
	ON_BN_CLICKED(IDC_INCHOPS100, OnInchops100)
	ON_BN_CLICKED(IDC_SETMEATZERO, OnSetmeatzero)
	ON_BN_CLICKED(IDC_SETFRUITZERO, OnSetfruitzero)
	ON_BN_CLICKED(IDC_SETBREADZERO, OnSetbreadzero)
	ON_BN_CLICKED(IDC_SETCHEESEZERO, OnSetcheesezero)
	ON_BN_CLICKED(IDC_INCMEAT10, OnIncmeat10)
	ON_BN_CLICKED(IDC_INCMEAT100, OnIncmeat100)
	ON_BN_CLICKED(IDC_INCFRUIT10, OnIncfruit10)
	ON_BN_CLICKED(IDC_INCFRUIT100, OnIncfruit100)
	ON_BN_CLICKED(IDC_INCBREAD10, OnIncbread10)
	ON_BN_CLICKED(IDC_INCBREAD100, OnIncbread100)
	ON_BN_CLICKED(IDC_INCCHEESE10, OnInccheese10)
	ON_BN_CLICKED(IDC_INCCHEESE100, OnInccheese100)
	ON_BN_CLICKED(IDC_SETSPEARZERO, OnSetspearzero)
	ON_BN_CLICKED(IDC_SETBOWZERO, OnSetbowzero)
	ON_BN_CLICKED(IDC_SETCROSSBOWZERO, OnSetcrossbowzero)
	ON_BN_CLICKED(IDC_SETSWORDZERO, OnSetswordzero)
	ON_BN_CLICKED(IDC_SETPIKEZERO, OnSetpikezero)
	ON_BN_CLICKED(IDC_SETMACEZERO, OnSetmacezero)
	ON_BN_CLICKED(IDC_SETLEATHERARMZERO, OnSetleatherarmzero)
	ON_BN_CLICKED(IDC_SETMETALARMZERO, OnSetmetalarmzero)
	ON_BN_CLICKED(IDC_INCSWORD10, OnIncsword10)
	ON_BN_CLICKED(IDC_INCSWORD100, OnIncsword100)
	ON_BN_CLICKED(IDC_INCBOW10, OnIncbow10)
	ON_BN_CLICKED(IDC_INCBOW100, OnIncbow100)
	ON_BN_CLICKED(IDC_INCCROSSBOW10, OnInccrossbow10)
	ON_BN_CLICKED(IDC_INCCROSSBOW100, OnInccrossbow100)
	ON_BN_CLICKED(IDC_INCSPEAR10, OnIncspear10)
	ON_BN_CLICKED(IDC_INCSPEAR100, OnIncspear100)
	ON_BN_CLICKED(IDC_INCPIKE10, OnIncpike10)
	ON_BN_CLICKED(IDC_INCPIKE100, OnIncpike100)
	ON_BN_CLICKED(IDC_INCMACE10, OnIncmace10)
	ON_BN_CLICKED(IDC_INCMACE100, OnIncmace100)
	ON_BN_CLICKED(IDC_INCLEATHERARM10, OnIncleatherarm10)
	ON_BN_CLICKED(IDC_INCLEATHERARM100, OnIncleatherarm100)
	ON_BN_CLICKED(IDC_INCMETALARM10, OnIncmetalarm10)
	ON_BN_CLICKED(IDC_INCMETALARM100, OnIncmetalarm100)
	ON_BN_CLICKED(IDC_SETGOLDZERO, OnSetgoldzero)
	ON_BN_CLICKED(IDC_INCGOLD10, OnIncgold10)
	ON_BN_CLICKED(IDC_INCGOLD100, OnIncgold100)
	ON_BN_CLICKED(IDC_CHK_FREEZE_MONEY, OnChkFreezeMoney)
	ON_BN_CLICKED(IDC_LOAD_GRANARY, OnLoadGranary)
	ON_BN_CLICKED(IDC_LOAD_ARMORY, OnLoadArmory)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrainerDlg message handlers

BOOL CTrainerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

#ifdef GAMEVER_10	// If this is for version 1.0 of the game
	// Adjust the offsets
	for( int iIdx=0; iIdx<=IDX_LAST_INDEX; iIdx++ )
	{
		DWORD dwAddr = (DWORD)gaTable2[iIdx].pAddr;
		dwAddr += VER10_OFFSET;
		gaTable2[iIdx].pAddr = (void*)dwAddr;
	}
#endif

#ifdef STRONGHOLD_CRUSADER	// If we are compiling for crusader
	// Adjust the offsets
	for( int iIdx=0; iIdx<=IDX_LAST_INDEX; iIdx++ )
	{
		DWORD dwAddr = (DWORD)gaTable2[iIdx].pAddr;
		dwAddr += CRUSADER_OFFSET;
		gaTable2[iIdx].pAddr = (void*)dwAddr;
	}
#endif

	m_ctlToolTip.Create( this );
	m_ctlToolTip.Activate( TRUE );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_WOOD_VAL ), "Wood" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_STONE_VAL ), "Stone" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_IRON_VAL ), "Iron" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_PITCH_VAL ), "Pitch" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_ALE_VAL ), "Ale" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_FLOUR_VAL ), "Flour" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_WHEAT_VAL ), "Wheat" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_HOPS_VAL ), "Hops" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_ANISKINS_VAL ), "Animal Skins" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_MEAT_VAL ), "Meat" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_FRUIT_VAL ), "Fruit" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_BREAD_VAL ), "Bread" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_CHEESE_VAL ), "Cheese" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_SWORD_VAL ), "Sword" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_BOW_VAL ), "Bow" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_CROSSBOW_VAL ), "Cross Bow" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_SPEAR_VAL ), "Spear" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_PIKE_VAL ), "Pike" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_MACE_VAL ), "Mace" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_LEATHERARM_VAL ), "Leather Armor" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_METALARM_VAL ), "Metal Armor" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_GOLD_VAL ), "Gold" );

	m_ctlLoadGranary.AutoLoad( IDC_LOAD_GRANARY, this );	
	m_ctlLoadArmory.AutoLoad( IDC_LOAD_ARMORY, this );	

	m_hProcess = NULL;
	SetTimer( 1, 1, NULL );
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTrainerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTrainerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTrainerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTrainerDlg::OnTimer(UINT nIDEvent) 
{
	if( nIDEvent == 1 )
		KillTimer( nIDEvent );

	if( m_hProcess == NULL )
		OpenProcess( );

	UpdateData( TRUE );
	if( m_hProcess != NULL )
	{
		if( m_bFreezeMoney )
		{		
			m_iCurGoldVal = m_iFreezeCurGoldVal;
			SetAddrValue( gaTable2[IDX_GOLD_CURRENT].pAddr, m_iCurGoldVal );
		}

		GetValues( );
	}

	SetTimer( 1, 1000, NULL );

	//CDialog::OnTimer(nIDEvent);
}

void CTrainerDlg::OpenProcess()
{
	CWaitCursor wait;

	// If we havent found stronghold yet
	if( m_hProcess == NULL )
	{
#ifdef STRONGHOLD_CRUSADER
		SetWindowText( "Stronghold Trainer - Looking for Stronghold Crusader..." );
#else
		SetWindowText( "Stronghold Trainer - Looking for Stronghold..." );
#endif

		// See if we can get the process id of it
#ifdef STRONGHOLD_CRUSADER
		char pszImageName[] = "Crusader";
#else
		char pszImageName[] = "Stronghold";
#endif
		CTaskManager        taskManager;
		CExeModuleInstance  *pProcess;
		int iPID = -1;

		// Retrieves information about processes and modules. 
		// The taskManager dynamically decides whether to use ToolHelp library or PSAPI
		taskManager.Populate();

		// Enumerates all processes
		for (unsigned i = 0; i < taskManager.GetProcessCount(); i++)
		{
			pProcess = taskManager.GetProcessByIndex(i);

			char fname[_MAX_FNAME];
			_splitpath( pProcess->Get_Name(), NULL, NULL, fname, NULL );

			if( stricmp( fname, pszImageName ) == 0 )
			{
				iPID = pProcess->Get_ProcessId(); 
				break;
			}
		}

		// Now try and open the process
		if( iPID != -1 )
		{
			m_hProcess = ::OpenProcess( PROCESS_ALL_ACCESS,	// Access flags
										FALSE,	// Inheritable
										iPID );
		}

		if( m_hProcess == NULL )
		{
#ifdef STRONGHOLD_CRUSADER
			SetWindowText( "Stronghold Crusader Trainer - Game Not Running!" );
#else
			SetWindowText( "Stronghold Trainer - Game Not Running!" );
#endif
		}
		else
		{
#ifdef STRONGHOLD_CRUSADER
			SetWindowText( "Stronghold Crusader Trainer" );
#else
			SetWindowText( "Stronghold Trainer" );
#endif
		}
	}
}

void CTrainerDlg::GetValues()
{
	m_iWoodVal = GetAddrValue( gaTable2[IDX_WOOD].pAddr );
	m_iHopsVal = GetAddrValue( gaTable2[IDX_HOPS].pAddr );
	m_iStoneVal = GetAddrValue( gaTable2[IDX_STONE].pAddr );	
	m_iAniSkinsVal = GetAddrValue( gaTable2[IDX_ANI_SKINS].pAddr );	
	m_iIronVal = GetAddrValue( gaTable2[IDX_IRON].pAddr );
	m_iPitchVal = GetAddrValue( gaTable2[IDX_PITCH].pAddr );
	//m_iUnknownVal = GetAddrValue( gaTable2[IDX_UNKNOWN].pAddr );
	m_iWheatVal = GetAddrValue( gaTable2[IDX_WHEAT].pAddr );
	m_iBreadVal = GetAddrValue( gaTable2[IDX_BREAD].pAddr );
	m_iCheeseVal = GetAddrValue( gaTable2[IDX_CHEESE].pAddr );
	m_iMeatVal = GetAddrValue( gaTable2[IDX_MEAT].pAddr );
	m_iFruitVal = GetAddrValue( gaTable2[IDX_FRUIT].pAddr );
	m_iAleVal = GetAddrValue( gaTable2[IDX_ALE].pAddr );
	//m_iGoldVal = GetAddrValue( gaTable2[IDX_GOLD].pAddr );
	m_iFlourVal = GetAddrValue( gaTable2[IDX_FLOUR].pAddr );
	m_iBowVal = GetAddrValue( gaTable2[IDX_BOW].pAddr );
	m_iCrossBowVal = GetAddrValue( gaTable2[IDX_CROSS_BOW].pAddr );
	m_iSpearVal = GetAddrValue( gaTable2[IDX_SPEAR].pAddr );
	m_iPikeVal = GetAddrValue( gaTable2[IDX_PIKE].pAddr );
	m_iMaceVal = GetAddrValue( gaTable2[IDX_MACE].pAddr );
	m_iSwordVal = GetAddrValue( gaTable2[IDX_SWORD].pAddr );
	m_iLeatherArmorVal = GetAddrValue( gaTable2[IDX_LEATHER_ARMOR].pAddr );
	m_iMetalArmorVal = GetAddrValue( gaTable2[IDX_METAL_ARMOR].pAddr );
	m_iCurGoldVal = GetAddrValue( gaTable2[IDX_GOLD_CURRENT].pAddr );

	UpdateData( FALSE );
}

void CTrainerDlg::SetValues()
{
	UpdateData( FALSE );

	SetAddrValue( gaTable2[IDX_WOOD].pAddr, m_iWoodVal );
	SetAddrValue( gaTable2[IDX_HOPS].pAddr, m_iHopsVal );
	SetAddrValue( gaTable2[IDX_STONE].pAddr, m_iStoneVal );
	SetAddrValue( gaTable2[IDX_ANI_SKINS].pAddr, m_iAniSkinsVal );	
	SetAddrValue( gaTable2[IDX_IRON].pAddr, m_iIronVal );
	SetAddrValue( gaTable2[IDX_PITCH].pAddr, m_iPitchVal );
	//SetAddrValue( gaTable2[IDX_UNKNOWN].pAddr, m_iUnknownVal );
	SetAddrValue( gaTable2[IDX_WHEAT].pAddr, m_iWheatVal );
	SetAddrValue( gaTable2[IDX_BREAD].pAddr, m_iBreadVal );
	SetAddrValue( gaTable2[IDX_CHEESE].pAddr, m_iCheeseVal );
	SetAddrValue( gaTable2[IDX_MEAT].pAddr, m_iMeatVal );
	SetAddrValue( gaTable2[IDX_FRUIT].pAddr, m_iFruitVal );
	SetAddrValue( gaTable2[IDX_ALE].pAddr, m_iAleVal );
	//SetAddrValue( gaTable2[IDX_GOLD].pAddr, m_iGoldVal );
	SetAddrValue( gaTable2[IDX_FLOUR].pAddr, m_iFlourVal );
	SetAddrValue( gaTable2[IDX_BOW].pAddr, m_iBowVal );
	SetAddrValue( gaTable2[IDX_CROSS_BOW].pAddr, m_iCrossBowVal );
	SetAddrValue( gaTable2[IDX_SPEAR].pAddr, m_iSpearVal );
	SetAddrValue( gaTable2[IDX_PIKE].pAddr, m_iPikeVal );
	SetAddrValue( gaTable2[IDX_MACE].pAddr, m_iMaceVal );
	SetAddrValue( gaTable2[IDX_SWORD].pAddr, m_iSwordVal );
	SetAddrValue( gaTable2[IDX_LEATHER_ARMOR].pAddr, m_iLeatherArmorVal );
	SetAddrValue( gaTable2[IDX_METAL_ARMOR].pAddr, m_iMetalArmorVal );
	SetAddrValue( gaTable2[IDX_GOLD_CURRENT].pAddr, m_iCurGoldVal );
}

int CTrainerDlg::GetAddrValue(void *pAddr)
{
	int iValue;
	DWORD dwBytesRead;

	if( m_hProcess == NULL )
		return 0;

	BOOL bResult = ReadProcessMemory( m_hProcess, pAddr, &iValue, sizeof(int), &dwBytesRead );

	if( bResult == FALSE )
		iValue = 0;

	return iValue;
}

void CTrainerDlg::SetAddrValue(void *pAddr, int iValue)
{
	DWORD dwBytesWritten;

	if( m_hProcess == NULL )
		return;

	BOOL bResult = WriteProcessMemory( m_hProcess, pAddr, &iValue, sizeof(int), &dwBytesWritten );
}

void CTrainerDlg::OnSetwoodzero() 
{	m_iWoodVal = 0;			SetValues( );	}
void CTrainerDlg::OnIncwood10() 
{	m_iWoodVal += 10;		SetValues( );	}
void CTrainerDlg::OnIncwood100() 
{	m_iWoodVal += 100;		SetValues( );	}

void CTrainerDlg::OnSetstonezero() 
{	m_iStoneVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncstone10() 
{	m_iStoneVal += 10;		SetValues( );	}
void CTrainerDlg::OnIncstone100() 
{	m_iStoneVal += 100;		SetValues( );	}

void CTrainerDlg::OnSetironzero() 
{	m_iIronVal = 0;		SetValues( );	}
void CTrainerDlg::OnInciron10() 
{	m_iIronVal += 10;	SetValues( );	}
void CTrainerDlg::OnInciron100() 
{	m_iIronVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetpitchzero() 
{	m_iPitchVal = 0;	SetValues( );	}
void CTrainerDlg::OnIncpitch10() 
{	m_iPitchVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncpitch100() 
{	m_iPitchVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetalezero() 
{	m_iAleVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncale10() 
{	m_iAleVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncale100() 
{	m_iAleVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetflourzero() 
{	m_iFlourVal = 0;	SetValues( );	}
void CTrainerDlg::OnIncflour10() 
{	m_iFlourVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncflour100() 
{	m_iFlourVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetwheatzero() 
{	m_iWheatVal = 0;	SetValues( );	}
void CTrainerDlg::OnIncwheat10() 
{	m_iWheatVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncwheat100() 
{	m_iWheatVal += 100;	SetValues( );	}

void CTrainerDlg::OnSethopszero() 
{	m_iHopsVal = 0;		SetValues( );	}
void CTrainerDlg::OnInchops10() 
{	m_iHopsVal += 10;	SetValues( );	}
void CTrainerDlg::OnInchops100() 
{	m_iHopsVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetaniskinszero() 
{	m_iAniSkinsVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncaniskins10() 
{	m_iAniSkinsVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncaniskins100() 
{	m_iAniSkinsVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetmeatzero() 
{	m_iMeatVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncmeat10() 
{	m_iMeatVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncmeat100() 
{	m_iMeatVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetfruitzero() 
{	m_iFruitVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncfruit10() 
{	m_iFruitVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncfruit100() 
{	m_iFruitVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetbreadzero() 
{	m_iBreadVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncbread10() 
{	m_iBreadVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncbread100() 
{	m_iBreadVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetcheesezero() 
{	m_iCheeseVal = 0;		SetValues( );	}
void CTrainerDlg::OnInccheese10() 
{	m_iCheeseVal += 10;	SetValues( );	}
void CTrainerDlg::OnInccheese100() 
{	m_iCheeseVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetswordzero() 
{	m_iSwordVal = 0;	SetValues( );	}
void CTrainerDlg::OnIncsword10() 
{	m_iSwordVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncsword100() 
{	m_iSwordVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetbowzero() 
{	m_iBowVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncbow10() 
{	m_iBowVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncbow100() 
{	m_iBowVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetcrossbowzero() 
{	m_iCrossBowVal = 0;		SetValues( );	}
void CTrainerDlg::OnInccrossbow10() 
{	m_iCrossBowVal += 10;	SetValues( );	}
void CTrainerDlg::OnInccrossbow100() 
{	m_iCrossBowVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetspearzero() 
{	m_iSpearVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncspear10() 
{	m_iSpearVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncspear100() 
{	m_iSpearVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetpikezero() 
{	m_iPikeVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncpike10() 
{	m_iPikeVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncpike100() 
{	m_iPikeVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetmacezero() 
{	m_iMaceVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncmace10() 
{	m_iMaceVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncmace100() 
{	m_iMaceVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetleatherarmzero() 
{	m_iLeatherArmorVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncleatherarm10() 
{	m_iLeatherArmorVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncleatherarm100() 
{	m_iLeatherArmorVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetmetalarmzero() 
{	m_iMetalArmorVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncmetalarm10() 
{	m_iMetalArmorVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncmetalarm100() 
{	m_iMetalArmorVal += 100;	SetValues( );	}

void CTrainerDlg::OnSetgoldzero() 
{	m_iCurGoldVal = 0;		SetValues( );	}
void CTrainerDlg::OnIncgold10() 
{	m_iCurGoldVal += 10;	SetValues( );	}
void CTrainerDlg::OnIncgold100() 
{	m_iCurGoldVal += 100;	SetValues( );	}

void CTrainerDlg::OnChkFreezeMoney() 
{
	UpdateData( TRUE );

	m_iFreezeCurGoldVal = m_iCurGoldVal;
}


BOOL CTrainerDlg::PreTranslateMessage(MSG* pMsg) 
{
	{
		// Let the ToolTip process this message.
		m_ctlToolTip.RelayEvent(pMsg);

		return CDialog::PreTranslateMessage(pMsg);
	}
}

void CTrainerDlg::OnLoadGranary() 
{
	if( m_hProcess == NULL )
		return;

	m_iMeatVal += 62;
	m_iFruitVal += 62;
	m_iBreadVal += 63;
	m_iCheeseVal += 63;

	SetAddrValue( gaTable2[IDX_MEAT].pAddr, m_iMeatVal );
	SetAddrValue( gaTable2[IDX_FRUIT].pAddr, m_iFruitVal );
	SetAddrValue( gaTable2[IDX_BREAD].pAddr, m_iBreadVal );
	SetAddrValue( gaTable2[IDX_CHEESE].pAddr, m_iCheeseVal );

	GetValues( );
}

void CTrainerDlg::OnLoadArmory() 
{
	if( m_hProcess == NULL )
		return;
	
	m_iSwordVal += 6;
	m_iBowVal += 6;
	m_iCrossBowVal += 6;
	m_iSpearVal += 6;
	m_iPikeVal += 6;
	m_iMaceVal += 6;
	m_iLeatherArmorVal += 7;
	m_iMetalArmorVal += 7;
	
	SetAddrValue( gaTable2[IDX_SWORD].pAddr, m_iSwordVal );
	SetAddrValue( gaTable2[IDX_BOW].pAddr, m_iBowVal );
	SetAddrValue( gaTable2[IDX_CROSS_BOW].pAddr, m_iCrossBowVal );
	SetAddrValue( gaTable2[IDX_SPEAR].pAddr, m_iSpearVal );
	SetAddrValue( gaTable2[IDX_PIKE].pAddr, m_iPikeVal );
	SetAddrValue( gaTable2[IDX_MACE].pAddr, m_iMaceVal );	
	SetAddrValue( gaTable2[IDX_LEATHER_ARMOR].pAddr, m_iLeatherArmorVal );
	SetAddrValue( gaTable2[IDX_METAL_ARMOR].pAddr, m_iMetalArmorVal );

	GetValues( );
}

