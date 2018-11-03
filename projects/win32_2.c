#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void CenterWindow(HWND);

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
                LPSTR lpCmdLine, int nCmdShow )
{
  MSG  msg ;    
  WNDCLASS wc = {0};
  wc.lpszClassName = TEXT( "Center" );
  wc.hInstance     = hInstance ;
  wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
  wc.lpfnWndProc   = WndProc ;
  wc.hCursor       = LoadCursor(0,IDC_ARROW);
  
  RegisterClass(&wc);
  CreateWindow( wc.lpszClassName, TEXT("Center"),
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                100, 100, 250, 150, 0, 0, hInstance, 0);  

  while( GetMessage(&msg, NULL, 0, 0)) {
    TranslateMessage(&msg);
    DispatchMessage(&msg);
  }
  return (int) msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
  switch(msg)  
  {
      case WM_CREATE:
      {
          CenterWindow(hwnd);
          return 0;
      }

      case WM_DESTROY:
      {
          PostQuitMessage(0);
          return 0;
      }
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}

void CenterWindow( HWND hwnd )
{
    RECT rc ;
    
    GetWindowRect ( hwnd, &rc ) ;
    
    SetWindowPos( hwnd, 0, 
        (GetSystemMetrics(SM_CXSCREEN) - rc.right)/2,
        (GetSystemMetrics(SM_CYSCREEN) - rc.bottom)/2,
         0, 0, SWP_NOZORDER|SWP_NOSIZE );
}
