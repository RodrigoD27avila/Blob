#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

#define TITLE_MAX 256
BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lparam);

int WINAPI WinMain(HINSTANCE hIntance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    EnumWindows(&EnumWindowsProc, (LPARAM)NULL);
    return 0;
}


BOOL CALLBACK EnumWindowsProc(HWND hwnd,LPARAM lparam)
{
    HWND window;
    char title[TITLE_MAX];

    window = GetWindow(hwnd, GW_HWNDFIRST);
    GetWindowText(window, (LPSTR)&title, TITLE_MAX-1);

    printf ("%s", title);

    return TRUE;

}

