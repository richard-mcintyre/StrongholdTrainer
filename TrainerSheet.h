#if !defined(AFX_TRAINERSHEET_H__7D0937DC_9851_4B4C_B8AA_77CD077C976F__INCLUDED_)
#define AFX_TRAINERSHEET_H__7D0937DC_9851_4B4C_B8AA_77CD077C976F__INCLUDED_

#include "..\TRAINERTEST\Trainer.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TrainerSheet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTrainerSheet

class CTrainerSheet : public CPropertySheet
{
	DECLARE_DYNAMIC(CTrainerSheet)

// Construction
public:
	CTrainerSheet(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CTrainerSheet(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainerSheet)
	public:
	virtual BOOL OnInitDialog();
	//}}AFX_VIRTUAL

// Implementation
public:
	HICON m_hIcon;
	CTrainer m_oTrainer;
	virtual ~CTrainerSheet();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTrainerSheet)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAINERSHEET_H__7D0937DC_9851_4B4C_B8AA_77CD077C976F__INCLUDED_)
