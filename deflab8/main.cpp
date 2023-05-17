#include <windows.h>
#include <stdlib.h>

#define ID_EDIT_DECIMAL 101
#define ID_EDIT_BINARY 102
#define ID_BUTTON_CONVERT 103

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASS wc = {0};
    HWND hwnd;
    MSG Msg;

    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszClassName = "WinAPI Калькулятор";

    RegisterClass(&wc);

    hwnd = CreateWindow(
        wc.lpszClassName,
        "Калькулятор перевода из 10сс в 2сс",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 400, 200,
        NULL, NULL, hInstance, NULL
    );

    if(hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while(GetMessage(&Msg, NULL, 0, 0)) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    static HWND hwndDecimal, hwndBinary, hwndConvert;
    char buffer[256];



    switch(msg) {
        case WM_CREATE:
            hwndDecimal = CreateWindow(//создания поля для ввода числа
                "EDIT",
                "",
                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_NUMBER,
                20, 20, 300, 25,
                hwnd,
                (HMENU)ID_EDIT_DECIMAL,
                GetModuleHandle(NULL),
                NULL
            );

            hwndBinary = CreateWindow(//создание поля результата
                "EDIT",
                "Результат",
                WS_CHILD | WS_VISIBLE | WS_BORDER | ES_READONLY | ES_NUMBER,
                20, 60, 300, 25,
                hwnd,
                (HMENU)ID_EDIT_BINARY,
                GetModuleHandle(NULL),
                NULL
            );

            hwndConvert = CreateWindow( //Создание кнопки перевода
                "BUTTON",
                "Перевод в двоичную сс",
                WS_CHILD | WS_VISIBLE | WS_BORDER ,
                20, 100, 300, 25,
                hwnd,
                (HMENU)ID_BUTTON_CONVERT,
                GetModuleHandle(NULL),
                NULL
            );

            break;

        case WM_COMMAND:
            if(LOWORD(wParam) == ID_BUTTON_CONVERT) {
                GetWindowText(hwndDecimal, buffer, sizeof(buffer));
                double decimal = atof(buffer);//приводим строку в числовой вид

                int integerPart = (int)decimal;
                double fractionalPart = decimal - integerPart;
                int binaryInt[32], binaryFrac[32];
                int i, j;



                for(i=0; integerPart>0; i++) {
                    binaryInt[i] = integerPart % 2;
                    integerPart /= 2;
                }

                for(j=0; j<15; j++) {
                    fractionalPart *= 2;
                    binaryFrac[j] = (int)fractionalPart;
                    fractionalPart -= (int)fractionalPart;
                }

                int k = i-1;
                for(j=0; j<i; j++, k--) {
                    buffer[j] = binaryInt[k] + '0';
                }

                buffer[j++] = '.';

                for(k=0; k<15; k++, j++) {
                    buffer[j] = binaryFrac[k] + '0';
                }



                SetWindowText(hwndBinary, buffer);
            }

            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

    switch(msg){
    case WH_CHAR:
    if (LOWORD(wParam) != VK_BACK && (LOWORD(wParam) < '0' || LOWORD(wParam) ))
        MessageBox(hwndDecimal, "error", 0);
        return 0;
    }
        break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }

    return 0;
}
