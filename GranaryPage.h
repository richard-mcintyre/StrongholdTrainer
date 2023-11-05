#if !defined(AFX_GRANARYPAGE_H__85DFCB22_2DF5_4711_BC7C_36C0865A49C1__INCLUDED_)
#define AFX_GRANARYPAGE_H__85DFCB22_2DF5_4711_BC7C_36C0865A49C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GranaryPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGranaryPage dialog

class CGranaryPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CGranaryPage)

// Construction
public:
	void SetValues( );
	CGranaryPage();
	~CGranaryPage();
	CToolTipCtrl m_ctlToolTip;

// Dialog Data
	//{{AFX_DATA(CGranaryPage)
	enum { IDD = IDD_GRANARY_PAGE };
	int		m_iBreadVal;
	int		m_iCheeseVal;
	int		m_iFruitVal;
	int		m_iMeatVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CGranaryPage)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CGranaryPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSetmeatzero();
	afx_msg void OnSetfruitzero();
	afx_msg void OnSetbreadzero();
	afx_msg void OnSetcheesezero();
	afx_msg void OnIncmeat10();
	afx_msg void OnIncfruit10();
	afx_msg void OnIncbread10();
	afx_msg void OnInccheese10();
	afx_msg void OnIncmeat100();
	afx_msg void OnIncfruit100();
	afx_msg void OnIncbread100();
	afx_msg void OnInccheese100();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRANARYPAGE_H__85DFCB22_2DF5_4711_BC7C_36C0865A49C1__INCLUDED_)
