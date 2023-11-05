// GranaryPage.cpp : implementation file
//

#include "stdafx.h"
#include "StrongholdTrainer.h"
#include "GranaryPage.h"

#include "TrainerSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGranaryPage property page

IMPLEMENT_DYNCREATE(CGranaryPage, CPropertyPage)

CGranaryPage::CGranaryPage() : CPropertyPage(CGranaryPage::IDD)
{
	//{{AFX_DATA_INIT(CGranaryPage)
	m_iBreadVal = 0;
	m_iCheeseVal = 0;
	m_iFruitVal = 0;
	m_iMeatVal = 0;
	//}}AFX_DATA_INIT
}

CGranaryPage::~CGranaryPage()
{
}

void CGranaryPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGranaryPage)
	DDX_Text(pDX, IDC_BREAD_VAL, m_iBreadVal);
	DDX_Text(pDX, IDC_CHEESE_VAL, m_iCheeseVal);
	DDX_Text(pDX, IDC_FRUIT_VAL, m_iFruitVal);
	DDX_Text(pDX, IDC_MEAT_VAL, m_iMeatVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGranaryPage, CPropertyPage)
	//{{AFX_MSG_MAP(CGranaryPage)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_SETMEATZERO, OnSetmeatzero)
	ON_BN_CLICKED(IDC_SETFRUITZERO, OnSetfruitzero)
	ON_BN_CLICKED(IDC_SETBREADZERO, OnSetbreadzero)
	ON_BN_CLICKED(IDC_SETCHEESEZERO, OnSetcheesezero)
	ON_BN_CLICKED(IDC_INCMEAT10, OnIncmeat10)
	ON_BN_CLICKED(IDC_INCFRUIT10, OnIncfruit10)
	ON_BN_CLICKED(IDC_INCBREAD10, OnIncbread10)
	ON_BN_CLICKED(IDC_INCCHEESE10, OnInccheese10)
	ON_BN_CLICKED(IDC_INCMEAT100, OnIncmeat100)
	ON_BN_CLICKED(IDC_INCFRUIT100, OnIncfruit100)
	ON_BN_CLICKED(IDC_INCBREAD100, OnIncbread100)
	ON_BN_CLICKED(IDC_INCCHEESE100, OnInccheese100)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGranaryPage message handlers

BOOL CGranaryPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_ctlToolTip.Create( this );
	m_ctlToolTip.Activate( TRUE );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_MEAT_VAL ), "Meat" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_FRUIT_VAL ), "Fruit" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_BREAD_VAL ), "Bread" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_CHEESE_VAL ), "Cheese" );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CGranaryPage::PreTranslateMessage(MSG* pMsg) 
{
	// Let the ToolTip process this message.
	m_ctlToolTip.RelayEvent(pMsg);
	
	return CPropertyPage::PreTranslateMessage(pMsg);
}

BOOL CGranaryPage::OnSetActive() 
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();
	
	pSheet->m_oTrainer.GetValues();
	m_iMeatVal = pSheet->m_oTrainer.m_iMeatVal;
	m_iFruitVal = pSheet->m_oTrainer.m_iFruitVal;
	m_iBreadVal = pSheet->m_oTrainer.m_iBreadVal;
	m_iCheeseVal = pSheet->m_oTrainer.m_iCheeseVal;

	UpdateData( FALSE );
	
	return CPropertyPage::OnSetActive();
}

void CGranaryPage::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	OnSetActive();
	
	// Do not call CPropertyPage::OnPaint() for painting messages
}

void CGranaryPage::SetValues()
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();

	pSheet->m_oTrainer.SetMeatValue( m_iMeatVal );	
	pSheet->m_oTrainer.SetFruitValue( m_iFruitVal );	
	pSheet->m_oTrainer.SetBreadValue( m_iBreadVal );	
	pSheet->m_oTrainer.SetCheeseValue( m_iCheeseVal );		

	UpdateData( FALSE );
}

void CGranaryPage::OnSetmeatzero() 
{	m_iMeatVal = 0;		SetValues();	}
void CGranaryPage::OnSetfruitzero() 
{	m_iFruitVal = 0;	SetValues();	}
void CGranaryPage::OnSetbreadzero() 
{	m_iBreadVal = 0;	SetValues();	}
void CGranaryPage::OnSetcheesezero() 
{	m_iCheeseVal = 0;	SetValues();	}

void CGranaryPage::OnIncmeat10() 
{	m_iMeatVal += 10;		SetValues();	}
void CGranaryPage::OnIncfruit10() 
{	m_iFruitVal += 10;		SetValues();	}
void CGranaryPage::OnIncbread10() 
{	m_iBreadVal += 10;		SetValues();	}
void CGranaryPage::OnInccheese10() 
{	m_iCheeseVal += 10;		SetValues();	}

void CGranaryPage::OnIncmeat100() 
{	m_iMeatVal += 100;		SetValues();	}
void CGranaryPage::OnIncfruit100() 
{	m_iFruitVal += 100;		SetValues();	}
void CGranaryPage::OnIncbread100() 
{	m_iBreadVal += 100;		SetValues();	}
void CGranaryPage::OnInccheese100() 
{	m_iCheeseVal += 100;	SetValues();	}
