// main.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Time.h"

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
    LoadStringW(hInstance, IDC_TIME, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_TIME));

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

    return (int) msg.wParam;
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

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_TIME));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_TIME);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

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
HWND hButtonAMPM;
HWND hAmericanTimeHour, hAmericanTimeMinute;
HWND hGMTTimeHour, hGMTTimeMinute;

HWND hT1Hour, hT1Minute;
HWND hT2Hour, hT2Minute;
HWND hT3Hour, hT3Minute;
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   CreateWindowEx(0, TEXT("STATIC"), TEXT("AMERICAN TIME"), WS_CHILD | WS_VISIBLE, 20, 20, 110, 20, hWnd, 0, hInst, NULL);
   CreateWindowEx(0, TEXT("STATIC"), TEXT("GMT TIME"), WS_CHILD | WS_VISIBLE, 400, 20, 70, 20, hWnd, 0, hInst, NULL);
   
   hAmericanTimeHour = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 20, 50, 20, 20, hWnd, 0, hInst, NULL);
   CreateWindowEx(0, TEXT("STATIC"), TEXT(":"), WS_CHILD | WS_VISIBLE, 42, 50, 4, 20, hWnd, 0, hInst, NULL);
   hAmericanTimeMinute = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 50, 50, 20, 20, hWnd, 0, hInst, NULL);
   hButtonAMPM = CreateWindowEx(0, TEXT("BUTTON"), TEXT("AM"), WS_CHILD | WS_VISIBLE, 80, 50, 30, 20, hWnd, (HMENU)0, hInst, NULL);

   hGMTTimeHour = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 400, 50, 20, 20, hWnd, 0, hInst, NULL);
   CreateWindowEx(0, TEXT("STATIC"), TEXT(":"), WS_CHILD | WS_VISIBLE, 422, 50, 4, 20, hWnd, 0, hInst, NULL);
   hGMTTimeMinute = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 430, 50, 20, 20, hWnd, 0, hInst, NULL);

   CreateWindowEx(0, TEXT("BUTTON"), TEXT("CONVERT->"), WS_CHILD | WS_VISIBLE, 200, 30, 100, 20, hWnd, (HMENU)1, hInst, NULL);
   CreateWindowEx(0, TEXT("BUTTON"), TEXT("<-CONVERT"), WS_CHILD | WS_VISIBLE, 200, 65, 100, 20, hWnd, (HMENU)2, hInst, NULL);
   
   //-----------------------------------//

   CreateWindowEx(0, TEXT("STATIC"), TEXT("T1"), WS_CHILD | WS_VISIBLE, 30, 110, 25, 20, hWnd, 0, hInst, NULL);
   CreateWindowEx(0, TEXT("STATIC"), TEXT("T2"), WS_CHILD | WS_VISIBLE, 30, 170, 25, 20, hWnd, 0, hInst, NULL);
   CreateWindowEx(0, TEXT("STATIC"), TEXT("T3"), WS_CHILD | WS_VISIBLE, 30, 210, 25, 20, hWnd, 0, hInst, NULL);
   
   hT1Hour = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 70, 110, 20, 20, hWnd, 0, hInst, NULL);
   CreateWindowEx(0, TEXT("STATIC"), TEXT(":"), WS_CHILD | WS_VISIBLE, 92, 110, 4, 20, hWnd, 0, hInst, NULL);
   hT1Minute = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 110, 20, 20, hWnd, 0, hInst, NULL);
   
   hT2Hour = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 70, 170, 20, 20, hWnd, 0, hInst, NULL);
   CreateWindowEx(0, TEXT("STATIC"), TEXT(":"), WS_CHILD | WS_VISIBLE, 92, 170, 4, 20, hWnd, 0, hInst, NULL);
   hT2Minute = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 170, 20, 20, hWnd, 0, hInst, NULL);

   CreateWindowEx(0, TEXT("BUTTON"), TEXT("+"), WS_CHILD | WS_VISIBLE, 20, 140, 15, 20, hWnd, (HMENU)3, hInst, NULL);
   CreateWindowEx(0, TEXT("BUTTON"), TEXT("-"), WS_CHILD | WS_VISIBLE, 40, 140, 15, 20, hWnd, (HMENU)4, hInst, NULL);
   
   hT3Hour = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 70, 210, 20, 20, hWnd, 0, hInst, NULL);
   CreateWindowEx(0, TEXT("STATIC"), TEXT(":"), WS_CHILD | WS_VISIBLE, 92, 210, 4, 20, hWnd, 0, hInst, NULL);
   hT3Minute = CreateWindowEx(0, TEXT("EDIT"), TEXT("00"), WS_CHILD | WS_VISIBLE | WS_BORDER, 100, 210, 20, 20, hWnd, 0, hInst, NULL);

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

    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case 0:
			{
				TCHAR *wcs = new TCHAR[5];
				GetWindowText(hButtonAMPM, wcs, 5);
				if (wcscmp(wcs, TEXT("AM")) == 0)
				{
					SetWindowText(hButtonAMPM, TEXT("PM"));
				}
				else SetWindowText(hButtonAMPM, TEXT("AM"));
			}
				break;
			case 1:
			{
				TCHAR *wcs = new TCHAR[5];
				TCHAR *wcs2 = new TCHAR[5];
				TCHAR *wcs3 = new TCHAR[5];

				GetWindowText(hAmericanTimeHour, wcs, 5);
				GetWindowText(hAmericanTimeMinute, wcs2, 5);
				GetWindowText(hButtonAMPM, wcs3, 5);

				Time t(_wtoi(wcs), _wtoi(wcs2), true, (wcscmp(wcs3, TEXT("AM")) == 0));
				Time t2 = Convert(t, true);

				wsprintf(wcs, TEXT("%d"), t2.GetHour());
				wsprintf(wcs2, TEXT("%d"), t2.GetMin());
				
				SetWindowText(hGMTTimeHour, wcs);
				SetWindowText(hGMTTimeMinute, wcs2);
			}
				break;
			case 2:
			{
				TCHAR *wcs = new TCHAR[5];
				TCHAR *wcs2 = new TCHAR[5];
				TCHAR *wcs3 = new TCHAR[5];

				GetWindowText(hGMTTimeHour, wcs, 5);
				GetWindowText(hGMTTimeMinute, wcs2, 5);

				Time t(_wtoi(wcs), _wtoi(wcs2));
				Time t2 = Convert(t, false);

				wsprintf(wcs, TEXT("%d"), t2.GetHour());
				wsprintf(wcs2, TEXT("%d"), t2.GetMin());
				if (t2.IsAM())
				{
					wcscpy_s(wcs3, sizeof(TEXT("AM")),TEXT("AM"));
				}
				else wcscpy_s(wcs3, sizeof(TEXT("PM")), TEXT("PM"));

				SetWindowText(hAmericanTimeHour, wcs);
				SetWindowText(hAmericanTimeMinute, wcs2);
				SetWindowText(hButtonAMPM, wcs3);
			}
				break;
			case 3:
			case 4:
			{
				TCHAR *wcs = new TCHAR[5];
				TCHAR *wcs2 = new TCHAR[5];

				GetWindowText(hT1Hour, wcs, 5);
				GetWindowText(hT1Minute, wcs2, 5);
				
				Time t1(_wtoi(wcs), _wtoi(wcs2));

				GetWindowText(hT2Hour, wcs, 5);
				GetWindowText(hT2Minute, wcs2, 5);

				Time t2(_wtoi(wcs), _wtoi(wcs2));

				Time t3;
				if (wmId == 3) t3 = t1 + t2;
				else t3 = t1 - t2;

				wsprintf(wcs, TEXT("%d"), t3.GetHour());
				wsprintf(wcs2, TEXT("%d"), t3.GetMin());

				SetWindowText(hT3Hour, wcs);
				SetWindowText(hT3Minute, wcs2);
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
			MoveToEx(hdc, 20, 100, NULL);
			LineTo(hdc, 500, 100);

			MoveToEx(hdc, 20, 200, NULL);
			LineTo(hdc, 130, 200);

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
