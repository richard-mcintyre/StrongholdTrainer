#if !defined(AFX_STOCKPILEPAGE_H__53D44E5C_92C4_4284_87A3_F62778D19C50__INCLUDED_)
#define AFX_STOCKPILEPAGE_H__53D44E5C_92C4_4284_87A3_F62778D19C50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StockpilePage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStockpilePage dialog

class CStockpilePage : public CPropertyPage
{
	DECLARE_DYNCREATE(CStockpilePage)

// Construction
public:
	void SetValues( );
	CStockpilePage();
	~CStockpilePage();
	CToolTipCtrl m_ctlToolTip;

// Dialog Data
	//{{AFX_DATA(CStockpilePage)
	enum { IDD = IDD_STOCKPILE_PAGE };
	int		m_iAleVal;
	int		m_iStoneVal;
	int		m_iWoodVal;
	int		m_iIronVal;
	int		m_iPitchVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CStockpilePage)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CStockpilePage)
	afx_msg void OnSetwoodzero();
	afx_msg void OnSetstonezero();
	afx_msg void OnSetironzero();
	afx_msg void OnSetpitchzero();
	afx_msg void OnSetalezero();
	afx_msg void OnIncwood10();
	afx_msg void OnIncstone10();
	afx_msg void OnInciron10();
	afx_msg void OnIncpitch10();
	afx_msg void OnIncale10();
	afx_msg void OnIncwood100();
	afx_msg void OnIncstone100();
	afx_msg void OnInciron100();
	afx_msg void OnIncpitch100();
	afx_msg void OnIncale100();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STOCKPILEPAGE_H__53D44E5C_92C4_4284_87A3_F62778D19C50__INCLUDED_)
