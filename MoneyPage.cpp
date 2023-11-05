// MoneyPage.cpp : implementation file
//

#include "stdafx.h"
#include "StrongholdTrainer.h"
#include "MoneyPage.h"

#include "TrainerSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMoneyPage property page

IMPLEMENT_DYNCREATE(CMoneyPage, CPropertyPage)

CMoneyPage::CMoneyPage() : CPropertyPage(CMoneyPage::IDD)
{
	//{{AFX_DATA_INIT(CMoneyPage)
	m_iCurGoldVal = 0;
	m_bFreezeMoney = FALSE;
	//}}AFX_DATA_INIT
}

CMoneyPage::~CMoneyPage()
{
}

void CMoneyPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMoneyPage)
	DDX_Text(pDX, IDC_GOLD_VAL, m_iCurGoldVal);
	DDX_Check(pDX, IDC_CHK_FREEZE_MONEY, m_bFreezeMoney);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMoneyPage, CPropertyPage)
	//{{AFX_MSG_MAP(CMoneyPage)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_SETGOLDZERO, OnSetgoldzero)
	ON_BN_CLICKED(IDC_INCGOLD10, OnIncgold10)
	ON_BN_CLICKED(IDC_INCGOLD100, OnIncgold100)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_INCGOLD1000, OnIncgold1000)
	ON_BN_CLICKED(IDC_INCGOLD10000, OnIncgold10000)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoneyPage message handlers

BOOL CMoneyPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_ctlToolTip.Create( this );
	m_ctlToolTip.Activate( TRUE );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_GOLD_VAL ), "Gold" );

	SetTimer( 1, 1000, NULL );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CMoneyPage::PreTranslateMessage(MSG* pMsg) 
{
	// Let the ToolTip process this message.
	m_ctlToolTip.RelayEvent(pMsg);
	
	return CPropertyPage::PreTranslateMessage(pMsg);
}

BOOL CMoneyPage::OnSetActive() 
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();
	
	pSheet->m_oTrainer.GetValues();
	m_iCurGoldVal = pSheet->m_oTrainer.m_iCurGoldVal;

	UpdateData( FALSE );
	
	return CPropertyPage::OnSetActive();
}

void CMoneyPage::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	OnSetActive();
	
	// Do not call CPropertyPage::OnPaint() for painting messages
}

void CMoneyPage::SetValues()
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();

	pSheet->m_oTrainer.SetCurGoldValue( m_iCurGoldVal );	
	m_iMoneyFreezeVal = m_iCurGoldVal;

	UpdateData( FALSE );
}

void CMoneyPage::OnSetgoldzero() 
{	m_iCurGoldVal = 0;		SetValues();	}
void CMoneyPage::OnIncgold10() 
{	m_iCurGoldVal += 10;		SetValues();	}
void CMoneyPage::OnIncgold100() 
{	m_iCurGoldVal += 100;		SetValues();	}
void CMoneyPage::OnIncgold1000() 
{	m_iCurGoldVal += 1000;		SetValues();	}
void CMoneyPage::OnIncgold10000() 
{	m_iCurGoldVal += 10000;		SetValues();	}

void CMoneyPage::OnTimer(UINT nIDEvent) 
{
	UpdateData( TRUE );
	if( m_bFreezeMoney )
	{
		m_iCurGoldVal = m_iMoneyFreezeVal;
		SetValues( );
	}

	CPropertyPage::OnTimer(nIDEvent);
}
