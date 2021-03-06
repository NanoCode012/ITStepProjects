// LoginForm.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "LoginForm.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
BOOL CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK    WndProc2(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, WndProc);
}

BOOL CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_LOGIN:
		{
			TCHAR *t = new TCHAR[30];
			GetWindowText(GetDlgItem(hWnd, IDC_USERNAME), t, 30);
			if (_tccmp(t, TEXT("ApplePie")) == 0)
			{
				GetWindowText(GetDlgItem(hWnd, IDC_PASSWORD), t, 30);
				if (_tccmp(t, TEXT("Banana")) == 0)
				{
					MessageBox(hWnd, TEXT("Success"), TEXT("Login Info"), MB_OK);
					EndDialog(hWnd, 0);
					DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), NULL, WndProc2);
				}
				else MessageBox(hWnd, TEXT("Failed"), TEXT("Login Info"), MB_OK);
			}
			else MessageBox(hWnd, TEXT("Failed"), TEXT("Login Info"), MB_OK);
		}
		break;
		case IDCANCEL:
		{
			EndDialog(hWnd, 0);
		}
		break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		}
	}
	break;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
	}
    return 0;
}

BOOL CALLBACK WndProc2(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case ID_QUIT:
		{
			EndDialog(hWnd, 0);
			break;
		}
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		}
		break;
	}
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
