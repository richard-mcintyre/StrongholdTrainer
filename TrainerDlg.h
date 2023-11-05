// TrainerDlg.h : header file
//

#if !defined(AFX_TRAINERDLG_H__29CEA57B_440A_4910_9F9F_FC9CDD19F5DC__INCLUDED_)
#define AFX_TRAINERDLG_H__29CEA57B_440A_4910_9F9F_FC9CDD19F5DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTrainerDlg dialog

class CTrainerDlg : public CDialog
{
// Construction
public:
	CTrainerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTrainerDlg)
	enum { IDD = IDD_STRONGHOLDTRAINER_DIALOG };
	int		m_iStoneVal;
	int		m_iWoodVal;
	int		m_iIronVal;
	int		m_iPitchVal;
	int		m_iAleVal;
	int		m_iFlourVal;
	int		m_iWheatVal;
	int		m_iAniSkinsVal;
	int		m_iHopsVal;
	int		m_iMeatVal;
	int		m_iFruitVal;
	int		m_iBreadVal;
	int		m_iCheeseVal;
	int		m_iSwordVal;
	int		m_iBowVal;
	int		m_iCrossBowVal;
	int		m_iSpearVal;
	int		m_iPikeVal;
	int		m_iMaceVal;
	int		m_iLeatherArmorVal;
	int		m_iMetalArmorVal;
	int		m_iCurGoldVal;
	BOOL	m_bFreezeMoney;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainerDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTrainerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnSetwoodzero();
	afx_msg void OnIncwood10();
	afx_msg void OnIncwood100();
	afx_msg void OnSetstonezero();
	afx_msg void OnIncstone10();
	afx_msg void OnIncstone100();
	afx_msg void OnSetironzero();
	afx_msg void OnInciron10();
	afx_msg void OnInciron100();
	afx_msg void OnSetpitchzero();
	afx_msg void OnSetalezero();
	afx_msg void OnIncpitch10();
	afx_msg void OnIncpitch100();
	afx_msg void OnIncale10();
	afx_msg void OnIncale100();
	afx_msg void OnSetflourzero();
	afx_msg void OnSetwheatzero();
	afx_msg void OnSethopszero();
	afx_msg void OnSetaniskinszero();
	afx_msg void OnIncflour10();
	afx_msg void OnIncflour100();
	afx_msg void OnIncwheat10();
	afx_msg void OnIncwheat100();
	afx_msg void OnInchops10();
	afx_msg void OnIncaniskins10();
	afx_msg void OnIncaniskins100();
	afx_msg void OnInchops100();
	afx_msg void OnSetmeatzero();
	afx_msg void OnSetfruitzero();
	afx_msg void OnSetbreadzero();
	afx_msg void OnSetcheesezero();
	afx_msg void OnIncmeat10();
	afx_msg void OnIncmeat100();
	afx_msg void OnIncfruit10();
	afx_msg void OnIncfruit100();
	afx_msg void OnIncbread10();
	afx_msg void OnIncbread100();
	afx_msg void OnInccheese10();
	afx_msg void OnInccheese100();
	afx_msg void OnSetspearzero();
	afx_msg void OnSetbowzero();
	afx_msg void OnSetcrossbowzero();
	afx_msg void OnSetswordzero();
	afx_msg void OnSetpikezero();
	afx_msg void OnSetmacezero();
	afx_msg void OnSetleatherarmzero();
	afx_msg void OnSetmetalarmzero();
	afx_msg void OnIncsword10();
	afx_msg void OnIncsword100();
	afx_msg void OnIncbow10();
	afx_msg void OnIncbow100();
	afx_msg void OnInccrossbow10();
	afx_msg void OnInccrossbow100();
	afx_msg void OnIncspear10();
	afx_msg void OnIncspear100();
	afx_msg void OnIncpike10();
	afx_msg void OnIncpike100();
	afx_msg void OnIncmace10();
	afx_msg void OnIncmace100();
	afx_msg void OnIncleatherarm10();
	afx_msg void OnIncleatherarm100();
	afx_msg void OnIncmetalarm10();
	afx_msg void OnIncmetalarm100();
	afx_msg void OnSetgoldzero();
	afx_msg void OnIncgold10();
	afx_msg void OnIncgold100();
	afx_msg void OnChkFreezeMoney();
	afx_msg void OnLoadGranary();
	afx_msg void OnLoadArmory();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBitmapButton m_ctlLoadGranary;
	CBitmapButton m_ctlLoadArmory;
	CToolTipCtrl m_ctlToolTip;
	int m_iFreezeCurGoldVal;
	void OpenProcess();
	void GetValues( );
	void SetAddrValue( void* pAddr, int iValue );
	void SetValues( );
	int GetAddrValue( void* pAddr );
	HANDLE m_hProcess;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAINERDLG_H__29CEA57B_440A_4910_9F9F_FC9CDD19F5DC__INCLUDED_)
