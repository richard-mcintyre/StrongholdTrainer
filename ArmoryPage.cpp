// ArmoryPage.cpp : implementation file
//

#include "stdafx.h"
#include "StrongholdTrainer.h"
#include "ArmoryPage.h"

#include "TrainerSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CArmoryPage property page

IMPLEMENT_DYNCREATE(CArmoryPage, CPropertyPage)

CArmoryPage::CArmoryPage() : CPropertyPage(CArmoryPage::IDD)
{
	//{{AFX_DATA_INIT(CArmoryPage)
	m_iSwordVal = 0;
	m_iBowVal = 0;
	m_iCrossBowVal = 0;
	m_iSpearVal = 0;
	m_iPikeVal = 0;
	m_iMaceVal = 0;
	m_iLeatherArmorVal = 0;
	m_iMetalArmorVal = 0;
	//}}AFX_DATA_INIT

}

CArmoryPage::~CArmoryPage()
{
}

void CArmoryPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CArmoryPage)
	DDX_Text(pDX, IDC_SWORD_VAL, m_iSwordVal);
	DDX_Text(pDX, IDC_BOW_VAL, m_iBowVal);
	DDX_Text(pDX, IDC_CROSSBOW_VAL, m_iCrossBowVal);
	DDX_Text(pDX, IDC_SPEAR_VAL, m_iSpearVal);
	DDX_Text(pDX, IDC_PIKE_VAL, m_iPikeVal);
	DDX_Text(pDX, IDC_MACE_VAL, m_iMaceVal);
	DDX_Text(pDX, IDC_LEATHERARM_VAL, m_iLeatherArmorVal);
	DDX_Text(pDX, IDC_METALARM_VAL, m_iMetalArmorVal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CArmoryPage, CPropertyPage)
	//{{AFX_MSG_MAP(CArmoryPage)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_SETSWORDZERO, OnSetswordzero)
	ON_BN_CLICKED(IDC_SETBOWZERO, OnSetbowzero)
	ON_BN_CLICKED(IDC_SETCROSSBOWZERO, OnSetcrossbowzero)
	ON_BN_CLICKED(IDC_SETSPEARZERO, OnSetspearzero)
	ON_BN_CLICKED(IDC_SETPIKEZERO, OnSetpikezero)
	ON_BN_CLICKED(IDC_SETMACEZERO, OnSetmacezero)
	ON_BN_CLICKED(IDC_SETLEATHERARMZERO, OnSetleatherarmzero)
	ON_BN_CLICKED(IDC_SETMETALARMZERO, OnSetmetalarmzero)
	ON_BN_CLICKED(IDC_INCSWORD10, OnIncsword10)
	ON_BN_CLICKED(IDC_INCBOW10, OnIncbow10)
	ON_BN_CLICKED(IDC_INCCROSSBOW10, OnInccrossbow10)
	ON_BN_CLICKED(IDC_INCSPEAR10, OnIncspear10)
	ON_BN_CLICKED(IDC_INCPIKE10, OnIncpike10)
	ON_BN_CLICKED(IDC_INCMACE10, OnIncmace10)
	ON_BN_CLICKED(IDC_INCLEATHERARM10, OnIncleatherarm10)
	ON_BN_CLICKED(IDC_INCMETALARM10, OnIncmetalarm10)
	ON_BN_CLICKED(IDC_INCSWORD100, OnIncsword100)
	ON_BN_CLICKED(IDC_INCBOW100, OnIncbow100)
	ON_BN_CLICKED(IDC_INCCROSSBOW100, OnInccrossbow100)
	ON_BN_CLICKED(IDC_INCSPEAR100, OnIncspear100)
	ON_BN_CLICKED(IDC_INCPIKE100, OnIncpike100)
	ON_BN_CLICKED(IDC_INCMACE100, OnIncmace100)
	ON_BN_CLICKED(IDC_INCLEATHERARM100, OnIncleatherarm100)
	ON_BN_CLICKED(IDC_INCMETALARM100, OnIncmetalarm100)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CArmoryPage message handlers

BOOL CArmoryPage::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	m_ctlToolTip.Create( this );
	m_ctlToolTip.Activate( TRUE );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_SWORD_VAL ), "Sword" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_BOW_VAL ), "Bow" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_CROSSBOW_VAL ), "Cross Bow" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_SPEAR_VAL ), "Spear" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_PIKE_VAL ), "Pike" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_MACE_VAL ), "Mace" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_LEATHERARM_VAL ), "Leather Armor" );
	m_ctlToolTip.AddTool( GetDlgItem( IDC_METALARM_VAL ), "Metal Armor" );
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CArmoryPage::PreTranslateMessage(MSG* pMsg) 
{
	// Let the ToolTip process this message.
	m_ctlToolTip.RelayEvent(pMsg);
	
	return CPropertyPage::PreTranslateMessage(pMsg);
}
 
BOOL CArmoryPage::OnSetActive() 
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();
	
	pSheet->m_oTrainer.GetValues();
	m_iSwordVal = pSheet->m_oTrainer.m_iSwordVal;
	m_iBowVal = pSheet->m_oTrainer.m_iBowVal;
	m_iCrossBowVal = pSheet->m_oTrainer.m_iCrossBowVal;
	m_iSpearVal = pSheet->m_oTrainer.m_iSpearVal;
	m_iPikeVal = pSheet->m_oTrainer.m_iPikeVal;
	m_iMaceVal = pSheet->m_oTrainer.m_iMaceVal;
	m_iLeatherArmorVal = pSheet->m_oTrainer.m_iLeatherArmorVal;
	m_iMetalArmorVal = pSheet->m_oTrainer.m_iMetalArmorVal;

	UpdateData( FALSE );
		
	return CPropertyPage::OnSetActive();
}

void CArmoryPage::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	OnSetActive();
		
	// Do not call CPropertyPage::OnPaint() for painting messages
}

void CArmoryPage::SetValues()
{
	CTrainerSheet* pSheet = (CTrainerSheet*)GetParent();

	pSheet->m_oTrainer.SetSwordValue( m_iSwordVal );	
	pSheet->m_oTrainer.SetBowValue( m_iBowVal );	
	pSheet->m_oTrainer.SetCrossBowValue( m_iCrossBowVal );	
	pSheet->m_oTrainer.SetSpearValue( m_iSpearVal );		
	pSheet->m_oTrainer.SetPikeValue( m_iPikeVal );	
	pSheet->m_oTrainer.SetMaceValue( m_iMaceVal );	
	pSheet->m_oTrainer.SetLeatherArmorValue( m_iLeatherArmorVal );	
	pSheet->m_oTrainer.SetMetalArmorValue( m_iMetalArmorVal );		

	UpdateData( FALSE );
}


void CArmoryPage::OnSetswordzero() 
{	m_iSwordVal = 0;		SetValues();	}
void CArmoryPage::OnSetbowzero() 
{	m_iBowVal = 0;		SetValues();	}
void CArmoryPage::OnSetcrossbowzero() 
{	m_iCrossBowVal = 0;		SetValues();	}
void CArmoryPage::OnSetspearzero() 
{	m_iSpearVal = 0;		SetValues();	}
void CArmoryPage::OnSetpikezero() 
{	m_iPikeVal = 0;		SetValues();	}
void CArmoryPage::OnSetmacezero() 
{	m_iMaceVal = 0;		SetValues();	}
void CArmoryPage::OnSetleatherarmzero() 
{	m_iLeatherArmorVal = 0;		SetValues();	}
void CArmoryPage::OnSetmetalarmzero() 
{	m_iMetalArmorVal = 0;		SetValues();	}

void CArmoryPage::OnIncsword10() 
{	m_iSwordVal += 10;		SetValues();	}
void CArmoryPage::OnIncbow10() 
{	m_iBowVal += 10;		SetValues();	}
void CArmoryPage::OnInccrossbow10() 
{	m_iCrossBowVal += 10;		SetValues();	}
void CArmoryPage::OnIncspear10() 
{	m_iSpearVal += 10;		SetValues();	}
void CArmoryPage::OnIncpike10() 
{	m_iPikeVal += 10;		SetValues();	}
void CArmoryPage::OnIncmace10() 
{	m_iMaceVal += 10;		SetValues();	}
void CArmoryPage::OnIncleatherarm10() 
{	m_iLeatherArmorVal += 10;		SetValues();	}
void CArmoryPage::OnIncmetalarm10() 
{	m_iMetalArmorVal += 10;		SetValues();	}

void CArmoryPage::OnIncsword100() 
{	m_iSwordVal += 100;		SetValues();	}
void CArmoryPage::OnIncbow100() 
{	m_iBowVal += 100;		SetValues();	}
void CArmoryPage::OnInccrossbow100() 
{	m_iCrossBowVal += 100;		SetValues();	}
void CArmoryPage::OnIncspear100() 
{	m_iSpearVal += 100;		SetValues();	}
void CArmoryPage::OnIncpike100() 
{	m_iPikeVal += 100;		SetValues();	}
void CArmoryPage::OnIncmace100() 
{	m_iMaceVal += 100;		SetValues();	}
void CArmoryPage::OnIncleatherarm100() 
{	m_iLeatherArmorVal += 100;		SetValues();	}
void CArmoryPage::OnIncmetalarm100() 
{	m_iMetalArmorVal += 100;		SetValues();	}
