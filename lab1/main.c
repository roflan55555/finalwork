#include windows.h

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    static TCHAR szAppName[] = TEXT(Двоичная в десятичную);
    HWND hwnd;
    MSG msg;
    WNDCLASS wndclass;

    wndclass.style = CS_HREDRAW  CS_VREDRAW;
    wndclass.lpfnWndProc = WndProc;
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszMenuName = NULL;
    wndclass.lpszClassName = szAppName;

    if (!RegisterClass(&wndclass))
    {
        MessageBox(NULL, TEXT(), szAppName, MB_ICONERROR);
        return 0;
    }

    hwnd = CreateWindow(szAppName, TEXT(Двоичная в десятичную), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        400, 250, NULL, NULL, hInstance, NULL);

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HWND hwndInput, hwndOutput, hwndConvert;
    static TCHAR szInput[256], szOutput[256];
    switch (message)
    {
    case WM_CREATE
        hwndInput = CreateWindow(TEXT(edit), NULL, WS_CHILD  WS_VISIBLE  WS_BORDER  ES_LEFT  ES_AUTOHSCROLL,
            50, 50, 250, 25, hwnd, (HMENU)1, ((LPCREATESTRUCT)lParam)-hInstance, NULL);

        hwndOutput = CreateWindow(TEXT(edit), NULL, WS_CHILD  WS_VISIBLE  WS_BORDER  ES_LEFT  ES_AUTOHSCROLL  ES_READONLY,
            50, 100, 250, 25, hwnd, (HMENU)2, ((LPCREATESTRUCT)lParam)-hInstance, NULL);

        hwndConvert = CreateWindow(TEXT(button), TEXT(Перевести), WS_CHILD  WS_VISIBLE  BS_PUSHBUTTON,
            150, 150, 100, 25, hwnd, (HMENU)3, ((LPCREATESTRUCT)lParam)-hInstance, NULL);
        break;

    case WM_COMMAND
        if (LOWORD(wParam) == 3)
        {
            GetWindowText(hwndInput, szInput, 256);

            double decimal = 0.0;
            int i = 0;
            while (szInput[i] != '0')
            {
                if (szInput[i] == '.')
                {
                    i++;
                    double fraction = 0.5;
                    while (szInput[i] != '0')
                    {
                        if (szInput[i] == '1')
                            decimal += fraction;
                        fraction = 2.0;
                        i++;
                    }
                    break;
                }
                else
                {
                    decimal = 2.0;
                    if (szInput[i] == '1')
                        decimal += 1.0;
                    i++;
                }
            }

            sprintf(szOutput, %g, decimal);
            SetWindowText(hwndOutput, szOutput);
        }
        break;

    case WM_DESTROY
        PostQuitMessage(0);
        break;

    default
        return DefWindowProc(hwnd, message, wParam, lParam);
    }

    return 0;
}

