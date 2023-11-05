#if !defined(AFX_ARMORYPAGE_H__9CE73DAB_CB39_4FD5_BAE4_9532BF1A3372__INCLUDED_)
#define AFX_ARMORYPAGE_H__9CE73DAB_CB39_4FD5_BAE4_9532BF1A3372__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ArmoryPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CArmoryPage dialog

class CArmoryPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CArmoryPage)

// Construction
public:
	void SetValues();
	CArmoryPage();
	~CArmoryPage();
	CToolTipCtrl m_ctlToolTip;
	
// Dialog Data
	//{{AFX_DATA(CArmoryPage)
	enum { IDD = IDD_ARMORY_PAGE };
	int		m_iSwordVal;
	int		m_iBowVal;
	int		m_iCrossBowVal;
	int		m_iSpearVal;
	int		m_iPikeVal;
	int		m_iMaceVal;
	int		m_iLeatherArmorVal;
	int		m_iMetalArmorVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CArmoryPage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CArmoryPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSetswordzero();
	afx_msg void OnSetbowzero();
	afx_msg void OnSetcrossbowzero();
	afx_msg void OnSetspearzero();
	afx_msg void OnSetpikezero();
	afx_msg void OnSetmacezero();
	afx_msg void OnSetleatherarmzero();
	afx_msg void OnSetmetalarmzero();
	afx_msg void OnIncsword10();
	afx_msg void OnIncbow10();
	afx_msg void OnInccrossbow10();
	afx_msg void OnIncspear10();
	afx_msg void OnIncpike10();
	afx_msg void OnIncmace10();
	afx_msg void OnIncleatherarm10();
	afx_msg void OnIncmetalarm10();
	afx_msg void OnIncsword100();
	afx_msg void OnIncbow100();
	afx_msg void OnInccrossbow100();
	afx_msg void OnIncspear100();
	afx_msg void OnIncpike100();
	afx_msg void OnIncmace100();
	afx_msg void OnIncleatherarm100();
	afx_msg void OnIncmetalarm100();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ARMORYPAGE_H__9CE73DAB_CB39_4FD5_BAE4_9532BF1A3372__INCLUDED_)
