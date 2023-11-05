// StrongholdTrainer.h : main header file for the STRONGHOLDTRAINER application
//

#if !defined(AFX_STRONGHOLDTRAINER_H__D6BD0FB7_A7B1_4CD5_8285_CFEBA79A14CF__INCLUDED_)
#define AFX_STRONGHOLDTRAINER_H__D6BD0FB7_A7B1_4CD5_8285_CFEBA79A14CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

extern DWORD gdwPlayerOffset;

/////////////////////////////////////////////////////////////////////////////
// CTrainerApp:
// See StrongholdTrainer.cpp for the implementation of this class
//

class CTrainerApp : public CWinApp
{
public:
	CTrainerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrainerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTrainerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STRONGHOLDTRAINER_H__D6BD0FB7_A7B1_4CD5_8285_CFEBA79A14CF__INCLUDED_)
