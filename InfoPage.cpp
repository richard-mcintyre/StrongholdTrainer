// InfoPage.cpp : implementation file
//

#include "stdafx.h"
#include "StrongholdTrainer.h"
#include "InfoPage.h"

#include "TrainerSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInfoPage property page

IMPLEMENT_DYNCREATE(CInfoPage, CPropertyPage)

CInfoPage::CInfoPage() : CPropertyPage(CInfoPage::IDD)
{
	//{{AFX_DATA_INIT(CInfoPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CInfoPage::~CInfoPage()
{
}

void CInfoPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfoPage)
	DDX_Control(pDX, IDC_PLAYER, m_ctlPlayers);
	DDX_Control(pDX, IDC_EMAIL, m_ctlEMail);
	DDX_Control(pDX, IDC_URL, m_ctlURL);
	DDX_Control(pDX, IDC_GAME_STATUS, m_ctlGameStatus);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfoPage, CPropertyPage)
	//{{AFX_MSG_MAP(CInfoPage)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_LOAD_ARMORY, OnLoadArmory)
	ON_BN_CLICKED(IDC_LOAD_GRANARY, OnLoadGranary)
	ON_CBN_SELCHANGE(IDC_PLAYER, OnSelchangePlayer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfoPage message handlers

BOOL CInfoPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();

	m_ctlLoadGranary.AutoLoad( IDC_LOAD_GRANARY, this );	
	m_ctlLoadArmory.AutoLoad( IDC_LOAD_ARMORY, this );	
	
	m_ctlURL.SetURL( "http://www.thecompwiz.com" );
	m_ctlEMail.SetURL( "mailto:trainers@thecompwiz.com?subject=Stronghold Trainer" );
	
	SetTimer( 1, 1000, NULL );

	int i = m_ctlPlayers.AddString( "Player 1" );
	m_ctlPlayers.SetItemData( i, 0 );

	i = m_ctlPlayers.AddString( "Player 2" );
	m_ctlPlayers.SetItemData( i, 0x39f4 );
	
	m_ctlPlayers.SetCurSel( 0 );

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CInfoPage::OnTimer(UINT nIDEvent) 
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();
	
	if( pSheet->m_oTrainer.m_hProcess != NULL )
		m_ctlGameStatus.SetWindowText( "running" );
	else
		m_ctlGameStatus.SetWindowText( "not running!" );
	
	CPropertyPage::OnTimer(nIDEvent);
}

void CInfoPage::OnLoadGranary() 
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();

	pSheet->m_oTrainer.SetMeatValue( pSheet->m_oTrainer.m_iMeatVal + 62 );
	pSheet->m_oTrainer.SetFruitValue( pSheet->m_oTrainer.m_iFruitVal + 62 );
	pSheet->m_oTrainer.SetBreadValue( pSheet->m_oTrainer.m_iBreadVal + 63 );
	pSheet->m_oTrainer.SetCheeseValue( pSheet->m_oTrainer.m_iCheeseVal + 63 );
}

void CInfoPage::OnLoadArmory() 
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();

	pSheet->m_oTrainer.SetSwordValue( pSheet->m_oTrainer.m_iSwordVal + 6 );
	pSheet->m_oTrainer.SetBowValue( pSheet->m_oTrainer.m_iBowVal + 6 );
	pSheet->m_oTrainer.SetCrossBowValue( pSheet->m_oTrainer.m_iCrossBowVal + 6 );
	pSheet->m_oTrainer.SetSpearValue( pSheet->m_oTrainer.m_iSpearVal + 6 );
	pSheet->m_oTrainer.SetPikeValue( pSheet->m_oTrainer.m_iPikeVal + 6 );
	pSheet->m_oTrainer.SetMaceValue( pSheet->m_oTrainer.m_iMaceVal + 6 );
	pSheet->m_oTrainer.SetLeatherArmorValue( pSheet->m_oTrainer.m_iLeatherArmorVal + 7 );
	pSheet->m_oTrainer.SetMetalArmorValue( pSheet->m_oTrainer.m_iMetalArmorVal + 7 );
}


void CInfoPage::OnSelchangePlayer() 
{
	int i = m_ctlPlayers.GetCurSel( );
	if( i < 0 )
		return;

	gdwPlayerOffset = m_ctlPlayers.GetItemData( i );	
}
