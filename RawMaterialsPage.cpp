// RawMaterialsPage.cpp : implementation file
//

#include "stdafx.h"
#include "StrongholdTrainer.h"
#include "RawMaterialsPage.h"

#include "TrainerSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRawMaterialsPage property page

IMPLEMENT_DYNCREATE(CRawMaterialsPage, CPropertyPage)

CRawMaterialsPage::CRawMaterialsPage() : CPropertyPage(CRawMaterialsPage::IDD)
{
	//{{AFX_DATA_INIT(CRawMaterialsPage)
	m_iAniSkinsVal = 0;
	m_iFlourVal = 0;
	m_iHopsVal = 0;
	m_iWheatVal = 0;
	//}}AFX_DATA_INIT
}

CRawMaterialsPage::~CRawMaterialsPage()
{
}

void CRawMaterialsPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRawMaterialsPage)
	DDX_Text(pDX, IDC_ANISKINS_VAL, m_iAniSkinsVal);
	DDX_Text(pDX, IDC_FLOUR_VAL, m_iFlourVal);
	DDX_Text(pDX, IDC_HOPS_VAL, m_iHopsVal);
	DDX_Text(pDX, IDC_WHEAT_VAL, m_iWheatVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRawMaterialsPage, CPropertyPage)
	//{{AFX_MSG_MAP(CRawMaterialsPage)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_SETFLOURZERO, OnSetflourzero)
	ON_BN_CLICKED(IDC_SETWHEATZERO, OnSetwheatzero)
	ON_BN_CLICKED(IDC_SETHOPSZERO, OnSethopszero)
	ON_BN_CLICKED(IDC_SETANISKINSZERO, OnSetaniskinszero)
	ON_BN_CLICKED(IDC_INCFLOUR10, OnIncflour10)
	ON_BN_CLICKED(IDC_INCWHEAT10, OnIncwheat10)
	ON_BN_CLICKED(IDC_INCHOPS10, OnInchops10)
	ON_BN_CLICKED(IDC_INCANISKINS10, OnIncaniskins10)
	ON_BN_CLICKED(IDC_INCFLOUR100, OnIncflour100)
	ON_BN_CLICKED(IDC_INCWHEAT100, OnIncwheat100)
	ON_BN_CLICKED(IDC_INCHOPS100, OnInchops100)
	ON_BN_CLICKED(IDC_INCANISKINS100, OnIncaniskins100)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRawMaterialsPage message handlers

BOOL CRawMaterialsPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_ctlToolTip.Create( this );
	m_ctlToolTip.Activate( TRUE );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_FLOUR_VAL ), "Flour" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_WHEAT_VAL ), "Wheat" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_HOPS_VAL ), "Hops" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_ANISKINS_VAL ), "Animal Skins" );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CRawMaterialsPage::PreTranslateMessage(MSG* pMsg) 
{
	// Let the ToolTip process this message.
	m_ctlToolTip.RelayEvent(pMsg);
	
	return CPropertyPage::PreTranslateMessage(pMsg);
}

BOOL CRawMaterialsPage::OnSetActive() 
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();
	
	pSheet->m_oTrainer.GetValues();
	m_iFlourVal = pSheet->m_oTrainer.m_iFlourVal;
	m_iWheatVal = pSheet->m_oTrainer.m_iWheatVal;
	m_iHopsVal = pSheet->m_oTrainer.m_iHopsVal;
	m_iAniSkinsVal = pSheet->m_oTrainer.m_iAniSkinsVal;

	UpdateData( FALSE );
	
	return CPropertyPage::OnSetActive();
}

void CRawMaterialsPage::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	OnSetActive();
	
	// Do not call CPropertyPage::OnPaint() for painting messages
}

void CRawMaterialsPage::SetValues()
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();

	pSheet->m_oTrainer.SetFlourValue( m_iFlourVal );	
	pSheet->m_oTrainer.SetWheatValue( m_iWheatVal );	
	pSheet->m_oTrainer.SetHopsValue( m_iHopsVal );	
	pSheet->m_oTrainer.SetAniSkinsValue( m_iAniSkinsVal );		

	UpdateData( FALSE );
}

void CRawMaterialsPage::OnSetflourzero() 
{	m_iFlourVal = 0;		SetValues();	}
void CRawMaterialsPage::OnSetwheatzero() 
{	m_iWheatVal = 0;		SetValues();	}
void CRawMaterialsPage::OnSethopszero() 
{	m_iHopsVal = 0;		SetValues();	}
void CRawMaterialsPage::OnSetaniskinszero() 
{	m_iAniSkinsVal = 0;		SetValues();	}

void CRawMaterialsPage::OnIncflour10() 
{	m_iFlourVal += 10;		SetValues();	}
void CRawMaterialsPage::OnIncwheat10() 
{	m_iWheatVal += 10;		SetValues();	}
void CRawMaterialsPage::OnInchops10() 
{	m_iHopsVal += 10;		SetValues();	}
void CRawMaterialsPage::OnIncaniskins10() 
{	m_iAniSkinsVal += 10;		SetValues();	}

void CRawMaterialsPage::OnIncflour100() 
{	m_iFlourVal += 100;		SetValues();	}
void CRawMaterialsPage::OnIncwheat100() 
{	m_iWheatVal += 100;		SetValues();	}
void CRawMaterialsPage::OnInchops100() 
{	m_iHopsVal += 100;		SetValues();	}
void CRawMaterialsPage::OnIncaniskins100() 
{	m_iAniSkinsVal += 100;		SetValues();	}
