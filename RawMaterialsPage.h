#if !defined(AFX_RAWMATERIALSPAGE_H__D87BC2F4_5F82_4E27_9BE4_F742A0E7F2F9__INCLUDED_)
#define AFX_RAWMATERIALSPAGE_H__D87BC2F4_5F82_4E27_9BE4_F742A0E7F2F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RawMaterialsPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRawMaterialsPage dialog

class CRawMaterialsPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CRawMaterialsPage)

// Construction
public:
	void SetValues( );
	CRawMaterialsPage();
	~CRawMaterialsPage();
	CToolTipCtrl m_ctlToolTip;

// Dialog Data
	//{{AFX_DATA(CRawMaterialsPage)
	enum { IDD = IDD_RAWMATERIALS_PAGE };
	int		m_iAniSkinsVal;
	int		m_iFlourVal;
	int		m_iHopsVal;
	int		m_iWheatVal;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CRawMaterialsPage)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnSetActive();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CRawMaterialsPage)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSetflourzero();
	afx_msg void OnSetwheatzero();
	afx_msg void OnSethopszero();
	afx_msg void OnSetaniskinszero();
	afx_msg void OnIncflour10();
	afx_msg void OnIncwheat10();
	afx_msg void OnInchops10();
	afx_msg void OnIncaniskins10();
	afx_msg void OnIncflour100();
	afx_msg void OnIncwheat100();
	afx_msg void OnInchops100();
	afx_msg void OnIncaniskins100();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RAWMATERIALSPAGE_H__D87BC2F4_5F82_4E27_9BE4_F742A0E7F2F9__INCLUDED_)
