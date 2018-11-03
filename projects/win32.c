#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow )
{
  MSG  msg ;    
  HWND hwnd;
  WNDCLASS wc;
    
  wc.style         = CS_HREDRAW | CS_VREDRAW;
  wc.cbClsExtra    = 0;
  wc.cbWndExtra    = 0;
  wc.lpszClassName = TEXT( "Window" );
  wc.hInstance     = hInstance ;
  wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
  wc.lpszMenuName  = NULL;
  wc.lpfnWndProc   = WndProc;
  wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
  wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
  
  RegisterClass(&wc);
  hwnd = CreateWindow( wc.lpszClassName, TEXT("Window"),
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                100, 100, 250, 150, NULL, NULL, hInstance, NULL);  

  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  while( GetMessage(&msg, NULL, 0, 0)) {
    DispatchMessage(&msg);
  }
  return (int) msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
  switch(msg)  
  {
    case WM_DESTROY:
      {
        PostQuitMessage(0);
        return 0;
      }
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}
