// MiniBus Simulator.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "MiniBus Simulator.h"

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
    LoadStringW(hInstance, IDC_MINIBUSSIMULATOR, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MINIBUSSIMULATOR));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MINIBUSSIMULATOR));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MINIBUSSIMULATOR);
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
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   CreateWindow(TEXT("BUTTON"), TEXT("MOVE"), WS_VISIBLE | WS_CHILD, 20, 20, 70, 30, hWnd, (HMENU)1, hInst, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

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
const int amountOfBusStops = 5;
const int amountOfBus = 5;

int maximumCapacityAtBusStop = 20;
Time timeBetweenPassengerArrival(0, 10);
Time timeBetweenBusArrival(0, 45);

int maximumCapacityOfBus = 15;

BusStop busStops[amountOfBusStops];
Bus bus[amountOfBus];

Time currentTime(6, 0);
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_CREATE:
	{
		for (int i = 0; i < amountOfBusStops; i++)
		{
			busStops[i].SetCapacity(maximumCapacityAtBusStop);
			busStops[i].SetIntervalBusArriveAt(timeBetweenBusArrival);
			busStops[i].SetIntervalPassengerArriveAt(timeBetweenPassengerArrival);

			bus[i].SetCapacity(maximumCapacityOfBus);
			bus[i].SetMaxStops(amountOfBusStops);
		}
	}
		break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
			case 1:
			{
				Time temp = currentTime;

				currentTime = currentTime + timeBetweenBusArrival;
				bool oneLeftForFirstStop = false;

				for (int i = 0; i < amountOfBus; i++)
				{
					if (bus[i].GetStopNumber() == 0)
					{
						if (!oneLeftForFirstStop)
						{
							bus[i].MoveToNextStop();

							oneLeftForFirstStop = true;
						}
						else continue;
					}
					else
					{
						bus[i].MoveToNextStop();
					}
				}

				for (int i = 0; i < amountOfBusStops; i++)
				{
					busStops[i].ShiftForward(temp);
				}

				for (int i = 0; i < amountOfBus; i++)
				{
					int indexBusStop = bus[i].GetStopNumber();
					
					if (indexBusStop > 0)
					{
						indexBusStop--;//To use 0-based numbering

						int freeSeats = bus[i].GetFreeSeats();
						int waitingAmount = busStops[indexBusStop].GetAmountOfPassengers();

						if (waitingAmount >= freeSeats)
						{
							busStops[indexBusStop].RemovePassengers(currentTime, freeSeats);
						}
						else
						{
							busStops[indexBusStop].RemovePassengers(currentTime, waitingAmount);
						}
					}
				}

				InvalidateRect(hWnd, NULL, true);
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
		MoveToEx(hdc, 50, 100, NULL);
		LineTo(hdc, amountOfBusStops * 100 + 50, 100);

		int busCount[amountOfBusStops + 1];
		for (int i = 0; i <= amountOfBusStops; i++) busCount[i] = 0;

		for (int i = 0; i < amountOfBus; i++)
		{
			int temp = bus[i].GetStopNumber();
			if (temp >= 1 && temp <= amountOfBusStops)
			{
				busCount[temp]++;
			}
		}

		for (int i = 0; i < amountOfBusStops; i++)
		{
			int x = 100 * (i + 1);
			MoveToEx(hdc, x, 75, NULL);
			LineTo(hdc, x, 125);

			TCHAR *t = new TCHAR[20];

			_stprintf_s(t, 20, TEXT("Bus : %d"), busCount[i + 1]);
			TextOut(hdc, x, 140, t, _tcslen(t));

			_stprintf_s(t, 20, TEXT("Passenger : %d"), busStops[i].GetAmountOfPassengers());
			TextOut(hdc, x, 170, t, _tcslen(t));
		}

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
