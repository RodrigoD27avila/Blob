#include <windows.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);

void CreateDialogBox(HWND);
void RegisterDialogClass(HWND);

HINSTANCE ghInstance;

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    LPSTR lpCmdLine, int nCmdShow )
{
  MSG  msg ;    
  HWND hwnd;

  WNDCLASS wc = {0};
    
  wc.lpszClassName = TEXT( "Window" );
  wc.hInstance     = hInstance ;
  wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
  wc.lpfnWndProc   = WndProc;
  
  RegisterClass(&wc);
  hwnd = CreateWindow( wc.lpszClassName, TEXT("Window"),
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                100, 100, 250, 150, NULL, NULL, hInstance, NULL);  

  ghInstance = hInstance;

  while( GetMessage(&msg, NULL, 0, 0)) {
    DispatchMessage(&msg);
  }
  return (int) msg.wParam;
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
  switch(msg)  
  {
      case WM_CREATE:
          RegisterDialogClass(hwnd);
          CreateWindow(TEXT("button"), TEXT("Show dialog"),    
              WS_VISIBLE | WS_CHILD ,
              20, 50, 95, 25,        
              hwnd, (HMENU) 1, NULL, NULL);  
          break;

      case WM_COMMAND:
          CreateDialogBox(hwnd);
          break;

      case WM_DESTROY:
      {
          PostQuitMessage(0);
          return 0;
      }
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}

LRESULT CALLBACK DialogProc( HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam )
{

  switch(msg)  
  {
    case WM_CREATE:
    CreateWindow(TEXT("button"), TEXT("Ok"),    
          WS_VISIBLE | WS_CHILD ,
          50, 50, 80, 25,        
          hwnd, (HMENU) 1, NULL, NULL);  
    break;

    case WM_COMMAND:
    DestroyWindow(hwnd);
    break;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;       

  }
  return (DefWindowProc(hwnd, msg, wParam, lParam));

}


void RegisterDialogClass(HWND hwnd) 
{
  WNDCLASSEX wc = {0};
  wc.cbSize           = sizeof(WNDCLASSEX);
  wc.lpfnWndProc      = (WNDPROC) DialogProc;
  wc.hInstance        = ghInstance;
  wc.hbrBackground    = GetSysColorBrush(COLOR_3DFACE);
  wc.lpszClassName    = TEXT("DialogClass");
  RegisterClassEx(&wc);

}

void CreateDialogBox(HWND hwnd)
{
  CreateWindowEx(WS_EX_DLGMODALFRAME | WS_EX_TOPMOST,  TEXT("DialogClass"), TEXT("Dialog Box"), 
        WS_VISIBLE | WS_SYSMENU | WS_CAPTION , 100, 100, 200, 150, 
        NULL, NULL, ghInstance,  NULL);
}
