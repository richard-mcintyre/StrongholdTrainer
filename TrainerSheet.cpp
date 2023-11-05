// TrainerSheet.cpp : implementation file
//

#include "stdafx.h"
#include "StrongholdTrainer.h"
#include "TrainerSheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrainerSheet

IMPLEMENT_DYNAMIC(CTrainerSheet, CPropertySheet)

CTrainerSheet::CTrainerSheet(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CTrainerSheet::CTrainerSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CTrainerSheet::~CTrainerSheet()
{
}


BEGIN_MESSAGE_MAP(CTrainerSheet, CPropertySheet)
	//{{AFX_MSG_MAP(CTrainerSheet)
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrainerSheet message handlers

BOOL CTrainerSheet::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// add the minimize button to the window
	::SetWindowLong( m_hWnd, GWL_STYLE, GetStyle() | WS_MINIMIZEBOX );
	
	// add the minimize command to the system menu
	GetSystemMenu( FALSE )->InsertMenu( 1, MF_BYPOSITION | MF_STRING,
				   SC_ICON, "Minimize" );

// Select "Help" button
	CWnd* pWnd = GetDlgItem(IDHELP);
	ASSERT_VALID(pWnd);
	pWnd->ShowWindow( SW_HIDE );
	CRect rectHelp;
	pWnd->GetWindowRect(&rectHelp);
	ScreenToClient(&rectHelp);

	// Select "Apply" button
	pWnd = GetDlgItem(ID_APPLY_NOW);
	ASSERT_VALID(pWnd);
	pWnd->ShowWindow( SW_HIDE );

	// Select "Cancel" button
	pWnd = GetDlgItem(IDCANCEL);
	ASSERT_VALID(pWnd);
	pWnd->ShowWindow( SW_HIDE );

	//
	pWnd = GetDlgItem(IDOK);
	ASSERT_VALID(pWnd);
	pWnd->MoveWindow( &rectHelp );
	pWnd->SetWindowText( "Close" );

	SetTimer( 1, 1, NULL );
	
	return bResult;
}

void CTrainerSheet::OnTimer(UINT nIDEvent) 
{
	if( nIDEvent == 1 )
		KillTimer( nIDEvent );

	m_oTrainer.OpenProcess( );

	if( nIDEvent != 1000 )
		SetTimer( 1, 1000, NULL );
	
	CPropertySheet::OnTimer(nIDEvent);
}

void CTrainerSheet::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	CBitmap bmp;
	CDC memdc;
	CRect rect;
	
	CString tLogoText = "TheCompWiz.com";

	CFont fontLogo;
	fontLogo.CreateFont( 24, 0, 0, 0, FW_BOLD, TRUE, FALSE,0,0,0,0,0,0, "Arial" );

	CRect rectTabCtrl;
	GetTabControl()->GetWindowRect(rectTabCtrl);
	ScreenToClient(rectTabCtrl);


	CRect rectOk;
	GetDlgItem(IDOK)->GetWindowRect(rectOk);
	ScreenToClient(rectOk);

	dc.SetBkMode(TRANSPARENT);

	CRect rectText;
	rectText.left = rectTabCtrl.left;
	rectText.top = rectOk.top;
	rectText.bottom = rectOk.bottom;
	rectText.right = rectOk.left;

	CFont * OldFont = dc.SelectObject(&fontLogo);

	// draw text in DC
	COLORREF OldColor = dc.SetTextColor( ::GetSysColor( COLOR_3DHILIGHT));

	dc.DrawText(tLogoText, rectText + CPoint(1,1), 
	            DT_SINGLELINE | DT_LEFT | DT_VCENTER);
	dc.SetTextColor( ::GetSysColor( COLOR_3DSHADOW));
	dc.DrawText( tLogoText, rectText, DT_SINGLELINE | DT_LEFT | DT_VCENTER);

	// restore old text color
	dc.SetTextColor( OldColor);

	// restore old font
	dc.SelectObject(OldFont);


	// Do not call CPropertySheet::OnPaint() for painting messages
}
