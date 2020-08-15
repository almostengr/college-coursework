

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// THIS IS THE FIRST FILE, save it in main.cpp
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <afxwin.h>
#include "menuIDs.h"

class CMenuWindow : public CFrameWnd {
public:
	CMenuWindow();
	~CMenuWindow();
	afx_msg void OnPaint();
	afx_msg void OnExit();
	afx_msg void OnAbout();
	afx_msg void OnInstructions();
	afx_msg void OnColor(UINT);
	afx_msg void OnLButtonDown(UINT, CPoint);
	afx_msg void OnLButtonUp(UINT, CPoint);
	afx_msg void OnRButtonDown(UINT, CPoint);
	afx_msg void OnRButtonUp(UINT, CPoint);
	afx_msg void OnPaint2();
private:
	int color;
	DECLARE_MESSAGE_MAP()
	CPoint location;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

CMenuWindow::CMenuWindow() {
	Create(NULL, "Project 6 Program", WS_OVERLAPPEDWINDOW, CRect(100,100,500,500), NULL, "Example" );
	color = 0;
}

CMenuWindow::~CMenuWindow() { }


afx_msg void CMenuWindow::OnExit() {
	SendMessage( WM_CLOSE );
}

afx_msg void CMenuWindow::OnAbout() {
	MessageBox("\n\nCS 124-002\nProject 6", "Project Information");
}

afx_msg void CMenuWindow::OnInstructions(){
	MessageBox("Change the color from the Color menu. Then click inside the window and watch it change.","Instructions");
}

afx_msg void CMenuWindow::OnColor(UINT e) {
	switch (e) {
		case IDM_GREEN: color = 1; break;
		case IDM_BLUE: color = 2; break;
		case IDM_RED: color = 3; break;
		case IDM_BLACK: color = 4; break;
		//case IDM_WHITE: color = 5; break;
	}
	InvalidateRect(NULL, false);
}

afx_msg void CMenuWindow::OnPaint() {
	CPaintDC dc(this);
	CBrush brush;
	switch (color) {
		case 1: brush.CreateSolidBrush( RGB(0, 255, 0) ); break;
		case 2: brush.CreateSolidBrush( RGB(0, 0, 255) ); break;
		case 3: brush.CreateSolidBrush( RGB(255, 0, 0) ); break;
		case 4: brush.CreateSolidBrush( RGB(0, 0, 0) ); break;
	//	case 5: brush.CreateSolidBrush( RGB(255,255,255) ); break;
	}
	dc.SelectObject( &brush );
	CRect rect;
	GetClientRect ( &rect );
	dc.Rectangle( rect );
}



afx_msg void CMenuWindow::OnLButtonDown(UINT a, CPoint p) { color = 6; location = p; InvalidateRect(NULL, false); }

afx_msg void CMenuWindow::OnLButtonUp(UINT a, CPoint p) { color = 7; location = p; InvalidateRect(NULL, false); }

afx_msg void CMenuWindow::OnRButtonDown(UINT a, CPoint p) { color = 8; location = p; InvalidateRect(NULL, false); }

afx_msg void CMenuWindow::OnRButtonUp(UINT a, CPoint p) { color = 9; location = p; InvalidateRect(NULL, false); }

afx_msg void CMenuWindow::OnPaint2() {
	CPaintDC deviceContext(this);
	CBrush brush;
	switch (color) {
		case 6: brush.CreateSolidBrush( RGB(255, 0, 0) ); break;
		case 7: brush.CreateSolidBrush( RGB(0, 255, 0) ); break;
		case 8: brush.CreateSolidBrush( RGB(0, 0, 255) ); break;
		case 9: brush.CreateSolidBrush( RGB(128, 128, 128) ); break;
	}
	deviceContext.SelectObject( &brush );
	if (color == 6 || color == 7)
		deviceContext.Rectangle(location.x - 10, location.y - 10, location.x + 10, location.y + 10);
	else
		deviceContext.Ellipse(location.x - 10, location.y - 10, location.x + 10, location.y + 10);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP (CMenuWindow, CFrameWnd)
	ON_COMMAND(IDM_ABOUT, OnAbout)
	ON_COMMAND(IDM_EXIT, OnExit)
	ON_COMMAND(IDM_INSTRUCTIONS, OnInstructions)
	ON_COMMAND_RANGE(IDM_GREEN, IDM_BLACK, OnColor)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class CMenuApp : public CWinApp {
public:
	BOOL InitInstance() {
		m_pMainWnd = new CMenuWindow();
		m_pMainWnd->ShowWindow(m_nCmdShow);
		m_pMainWnd->UpdateWindow();
		return TRUE;
	}
} menuApp;
