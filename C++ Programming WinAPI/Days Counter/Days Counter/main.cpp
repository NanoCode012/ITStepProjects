// main.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Resource.h"
#include "Date.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

												// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

HWND hDay1, hMon1, hYear1;
HWND hDay2, hMon2, hYear2;
HWND hDaysToAdd;
HWND hRes;
HWND hButtonGetDifference, hButtonGetNewDate;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_DAYSCOUNTER, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DAYSCOUNTER));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DAYSCOUNTER));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_DAYSCOUNTER);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	CreateWindowEx(0, TEXT("STATIC"), TEXT("DAY"), WS_CHILD | WS_VISIBLE, 20, 30, 50, 20, hWnd, NULL, hInst, NULL);
	CreateWindowEx(0, TEXT("STATIC"), TEXT("MONTH"), WS_CHILD | WS_VISIBLE, 20, 50, 50, 20, hWnd, NULL, hInst, NULL);
	CreateWindowEx(0, TEXT("STATIC"), TEXT("YEAR"), WS_CHILD | WS_VISIBLE, 20, 70, 50, 20, hWnd, NULL, hInst, NULL);

	CreateWindowEx(0, TEXT("STATIC"), TEXT("FROM"), WS_CHILD | WS_VISIBLE, 80, 10, 50, 20, hWnd, NULL, hInst, NULL);
	CreateWindowEx(0, TEXT("STATIC"), TEXT("TO"), WS_CHILD | WS_VISIBLE, 140, 10, 50, 20, hWnd, NULL, hInst, NULL);

	hDay1 = CreateWindowEx(0, TEXT("EDIT"), TEXT("--"), WS_CHILD | WS_VISIBLE | WS_BORDER, 80, 30, 50, 20, hWnd, NULL, hInst, NULL);
	hMon1 = CreateWindowEx(0, TEXT("EDIT"), TEXT("--"), WS_CHILD | WS_VISIBLE | WS_BORDER, 80, 50, 50, 20, hWnd, NULL, hInst, NULL);
	hYear1 = CreateWindowEx(0, TEXT("EDIT"), TEXT("--"), WS_CHILD | WS_VISIBLE | WS_BORDER, 80, 70, 50, 20, hWnd, NULL, hInst, NULL);

	hDay2 = CreateWindowEx(0, TEXT("EDIT"), TEXT("--"), WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 30, 50, 20, hWnd, NULL, hInst, NULL);
	hMon2 = CreateWindowEx(0, TEXT("EDIT"), TEXT("--"), WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 50, 50, 20, hWnd, NULL, hInst, NULL);
	hYear2 = CreateWindowEx(0, TEXT("EDIT"), TEXT("--"), WS_CHILD | WS_VISIBLE | WS_BORDER, 140, 70, 50, 20, hWnd, NULL, hInst, NULL);

	CreateWindowEx(0, TEXT("STATIC"), TEXT("+ DAYS"), WS_CHILD | WS_VISIBLE, 20, 100, 50, 20, hWnd, NULL, hInst, NULL);
	hDaysToAdd = CreateWindowEx(0, TEXT("EDIT"), TEXT("--"), WS_CHILD | WS_VISIBLE | WS_BORDER, 80, 100, 50, 20, hWnd, NULL, hInst, NULL);

	CreateWindowEx(0, TEXT("STATIC"), TEXT("ANS"), WS_CHILD | WS_VISIBLE, 20, 130, 50, 20, hWnd, NULL, hInst, NULL);
	hRes = CreateWindowEx(0, TEXT("EDIT"), TEXT("=="), WS_CHILD | WS_VISIBLE | WS_BORDER, 80, 130, 75, 20, hWnd, NULL, hInst, NULL);

	hButtonGetDifference = CreateWindowEx(0, TEXT("BUTTON"), TEXT("SHOW ME THE MAGIC!"), WS_CHILD | WS_VISIBLE, 200, 200, 160, 50, hWnd, (HMENU)1, hInst, NULL);
	hButtonGetNewDate = CreateWindowEx(0, TEXT("BUTTON"), TEXT("WAZZAM!"), WS_CHILD | WS_VISIBLE, 200, 300, 150, 50, hWnd, (HMENU)2, hInst, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int length = 100;
	int day0, month0, year0;
	int day1, month1, year1;
	int daysToAdd;

	TCHAR* wcs = new TCHAR[length];

	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case 1: {
			GetWindowText(hDay1, wcs, length);
			day0 = _wtoi(wcs);

			GetWindowText(hMon1, wcs, length);
			month0 = _wtoi(wcs);

			GetWindowText(hYear1, wcs, length);
			year0 = _wtoi(wcs);

			GetWindowText(hDay2, wcs, length);
			day1 = _wtoi(wcs);

			GetWindowText(hMon2, wcs, length);
			month1 = _wtoi(wcs);

			GetWindowText(hYear2, wcs, length);
			year1 = _wtoi(wcs);

			Date d0(day0, month0, year0);
			Date d1(day1, month1, year1);

			int days = d1 - d0;

			wsprintf(wcs, TEXT("%d"), days);
			SetWindowText(hRes, wcs);
		}
			break;
		case 2: {
			GetWindowText(hDay1, wcs, length);
			day0 = _wtoi(wcs);

			GetWindowText(hMon1, wcs, length);
			month0 = _wtoi(wcs);

			GetWindowText(hYear1, wcs, length);
			year0 = _wtoi(wcs);

			GetWindowText(hDaysToAdd, wcs, length);
			daysToAdd = _wtoi(wcs);

			Date d0(day0, month0, year0);
			
			d0 += daysToAdd;

			wsprintf(wcs, TEXT("%d-%d-%d"), d0.GetDay(), d0.GetMonth(), d0.GetYear());
			SetWindowText(hRes, wcs);
		}
			break;
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code that uses hdc here...
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
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
