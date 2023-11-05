#if !defined(AFX_INFOPAGE_H__954D2CA6_DA65_4235_8AEB_C7F1406D98A4__INCLUDED_)
#define AFX_INFOPAGE_H__954D2CA6_DA65_4235_8AEB_C7F1406D98A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InfoPage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfoPage dialog
#include "Hyperlink.h"

class CInfoPage : public CPropertyPage
{
	DECLARE_DYNCREATE(CInfoPage)

// Construction
public:
	CInfoPage();
	~CInfoPage();

public:
	CBitmapButton m_ctlLoadGranary;
	CBitmapButton m_ctlLoadArmory;

// Dialog Data
	//{{AFX_DATA(CInfoPage)
	enum { IDD = IDD_INFO_PAGE };
	CComboBox	m_ctlPlayers;
	CHyperLink	m_ctlEMail;
	CHyperLink	m_ctlURL;
	CStatic	m_ctlGameStatus;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CInfoPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(CInfoPage)
	afx_msg void OnTimer(UINT nIDEvent);
	virtual BOOL OnInitDialog();
	afx_msg void OnLoadArmory();
	afx_msg void OnLoadGranary();
	afx_msg void OnSelchangePlayer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFOPAGE_H__954D2CA6_DA65_4235_8AEB_C7F1406D98A4__INCLUDED_)
