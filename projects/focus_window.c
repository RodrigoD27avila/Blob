#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstace,
        LPSTR lpCmdLine, int nCmdShow)
{

    if (__argc <= 1)
    {
        fprintf(stderr, "Fail!!");
        return EXIT_FAILURE;
    }

    MSG msg;
    WNDCLASS wc = {0};

    wc.lpszClassName = TEXT(__argv[1]);
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(0, IDC_ARROW);

    RegisterClass(&wc);
    CreateWindow(wc.lpszClassName, TEXT(__argv[1]),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 330, 270, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    char *text = __argv[1];

    switch (msg)
    {
        case WM_CREATE:
            CreateWindow(TEXT("STATIC"), text,
                WS_CHILD | WS_VISIBLE | SS_LEFT,
                20, 20, 300, 230,
                hwnd, (HMENU)1, NULL, NULL);
            return 0;

        case WM_DESTROY:
            PostQuitMessage(WM_QUIT);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}
