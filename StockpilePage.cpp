// StockpilePage.cpp : implementation file
//

#include "stdafx.h"
#include "StrongholdTrainer.h"
#include "StockpilePage.h"

#include "TrainerSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStockpilePage property page

IMPLEMENT_DYNCREATE(CStockpilePage, CPropertyPage)

CStockpilePage::CStockpilePage() : CPropertyPage(CStockpilePage::IDD)
{
	//{{AFX_DATA_INIT(CStockpilePage)
	m_iAleVal = 0;
	m_iStoneVal = 0;
	m_iWoodVal = 0;
	m_iIronVal = 0;
	m_iPitchVal = 0;
	//}}AFX_DATA_INIT
}

CStockpilePage::~CStockpilePage()
{
}

void CStockpilePage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStockpilePage)
	DDX_Text(pDX, IDC_ALE_VAL, m_iAleVal);
	DDX_Text(pDX, IDC_STONE_VAL, m_iStoneVal);
	DDX_Text(pDX, IDC_WOOD_VAL, m_iWoodVal);
	DDX_Text(pDX, IDC_IRON_VAL, m_iIronVal);
	DDX_Text(pDX, IDC_PITCH_VAL, m_iPitchVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStockpilePage, CPropertyPage)
	//{{AFX_MSG_MAP(CStockpilePage)
	ON_BN_CLICKED(IDC_SETWOODZERO, OnSetwoodzero)
	ON_BN_CLICKED(IDC_SETSTONEZERO, OnSetstonezero)
	ON_BN_CLICKED(IDC_SETIRONZERO, OnSetironzero)
	ON_BN_CLICKED(IDC_SETPITCHZERO, OnSetpitchzero)
	ON_BN_CLICKED(IDC_SETALEZERO, OnSetalezero)
	ON_BN_CLICKED(IDC_INCWOOD10, OnIncwood10)
	ON_BN_CLICKED(IDC_INCSTONE10, OnIncstone10)
	ON_BN_CLICKED(IDC_INCIRON10, OnInciron10)
	ON_BN_CLICKED(IDC_INCPITCH10, OnIncpitch10)
	ON_BN_CLICKED(IDC_INCALE10, OnIncale10)
	ON_BN_CLICKED(IDC_INCWOOD100, OnIncwood100)
	ON_BN_CLICKED(IDC_INCSTONE100, OnIncstone100)
	ON_BN_CLICKED(IDC_INCIRON100, OnInciron100)
	ON_BN_CLICKED(IDC_INCPITCH100, OnIncpitch100)
	ON_BN_CLICKED(IDC_INCALE100, OnIncale100)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStockpilePage message handlers

BOOL CStockpilePage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_ctlToolTip.Create( this );
	m_ctlToolTip.Activate( TRUE );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_WOOD_VAL ), "Wood" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_STONE_VAL ), "Stone" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_IRON_VAL ), "Iron" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_PITCH_VAL ), "Pitch" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_ALE_VAL ), "Ale" );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CStockpilePage::PreTranslateMessage(MSG* pMsg) 
{
	// Let the ToolTip process this message.
	m_ctlToolTip.RelayEvent(pMsg);
	
	return CPropertyPage::PreTranslateMessage(pMsg);
}

BOOL CStockpilePage::OnSetActive() 
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();
	
	pSheet->m_oTrainer.GetValues();
	m_iWoodVal = pSheet->m_oTrainer.m_iWoodVal;
	m_iStoneVal = pSheet->m_oTrainer.m_iStoneVal;
	m_iIronVal = pSheet->m_oTrainer.m_iIronVal;
	m_iPitchVal = pSheet->m_oTrainer.m_iPitchVal;
	m_iAleVal = pSheet->m_oTrainer.m_iAleVal;

	UpdateData( FALSE );
	
	return CPropertyPage::OnSetActive();
}


void CStockpilePage::SetValues()
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();

	pSheet->m_oTrainer.SetWoodValue( m_iWoodVal );	
	pSheet->m_oTrainer.SetStoneValue( m_iStoneVal );	
	pSheet->m_oTrainer.SetIronValue( m_iIronVal );	
	pSheet->m_oTrainer.SetPitchValue( m_iPitchVal );	
	pSheet->m_oTrainer.SetAleValue( m_iAleVal );	

	UpdateData( FALSE );
}

void CStockpilePage::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	OnSetActive();	
	// Do not call CPropertyPage::OnPaint() for painting messages
}

void CStockpilePage::OnSetwoodzero() 
{	m_iWoodVal = 0;		SetValues();	}
void CStockpilePage::OnSetstonezero() 
{	m_iStoneVal = 0;		SetValues();	}
void CStockpilePage::OnSetironzero() 
{	m_iIronVal = 0;		SetValues();	}
void CStockpilePage::OnSetpitchzero() 
{	m_iPitchVal = 0;		SetValues();	}
void CStockpilePage::OnSetalezero() 
{	m_iAleVal = 0;		SetValues();	}

void CStockpilePage::OnIncwood10() 
{	m_iWoodVal += 10;		SetValues();	}
void CStockpilePage::OnIncstone10() 
{	m_iStoneVal += 10;		SetValues();	}
void CStockpilePage::OnInciron10() 
{	m_iIronVal += 10;		SetValues();	}
void CStockpilePage::OnIncpitch10() 
{	m_iPitchVal += 10;		SetValues();	}
void CStockpilePage::OnIncale10() 
{	m_iAleVal += 10;		SetValues();	}

void CStockpilePage::OnIncwood100() 
{	m_iWoodVal += 100;		SetValues();	}
void CStockpilePage::OnIncstone100() 
{	m_iStoneVal += 100;		SetValues();	}
void CStockpilePage::OnInciron100() 
{	m_iIronVal += 100;		SetValues();	}
void CStockpilePage::OnIncpitch100() 
{	m_iPitchVal += 100;		SetValues();	}
void CStockpilePage::OnIncale100() 
{	m_iAleVal += 100;		SetValues();	}
