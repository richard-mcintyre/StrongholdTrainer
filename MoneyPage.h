#if !defined(AFX_MONEYPAGE_H__EAA09375_C615_4309_A4B3_EE5651C12749__INCLUDED_)
#define AFX_MONEYPAGE_H__EAA09375_C615_4309_A4B3_EE5651C12749__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MoneyPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMoneyPage dialog

class CMoneyPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CMoneyPage)

// Construction
public:
	int m_iMoneyFreezeVal;
	void SetValues( );
	CMoneyPage();
	~CMoneyPage();
	CToolTipCtrl m_ctlToolTip;

// Dialog Data
	//{{AFX_DATA(CMoneyPage)
	enum { IDD = IDD_MONEY_PAGE };
	int		m_iCurGoldVal;
	BOOL	m_bFreezeMoney;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CMoneyPage)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CMoneyPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSetgoldzero();
	afx_msg void OnIncgold10();
	afx_msg void OnIncgold100();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnIncgold1000();
	afx_msg void OnIncgold10000();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MONEYPAGE_H__EAA09375_C615_4309_A4B3_EE5651C12749__INCLUDED_)
