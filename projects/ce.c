#include <windows.h>

HINSTANCE g_hInst = NULL;     // Handle to the application instance
HWND g_hwndMain = NULL;       // Handle to the application main window
TCHAR g_szTitle[80] = TEXT ("Main Window"),    
                              // Application main window name
      g_szClassName[80] = TEXT ("Main window class");  
                              // Main window class name
                
/***********************************************************************

FUNCTION: 
  WndProc

PURPOSE: 
  The callback function for the main window. It processes messages that
  are sent to the main window.

***********************************************************************/
LRESULT CALLBACK WndProc (HWND hwnd, UINT umsg, WPARAM wParam, 
                          LPARAM lParam)
{
  switch (umsg)
  {
    // Add cases such as WM_CREATE, WM_COMMAND, WM_PAINT if you don't 
    // want to pass these messages along for default processing.

    case WM_CLOSE:
      DestroyWindow (hwnd);
      return 0;

    case WM_DESTROY:
      PostQuitMessage (0);
      return 0;
  }

  return DefWindowProc (hwnd, umsg, wParam, lParam);
}

/***********************************************************************

FUNCTION: 
  InitInstance

PURPOSE: 
  Create and display the main window.

***********************************************************************/
BOOL InitInstance (HINSTANCE hInstance, int iCmdShow)
{

  g_hInst = hInstance;
  
  g_hwndMain = CreateWindow (
                  g_szClassName,  // Registered class name         
                  g_szTitle,      // Application window name
                  WS_OVERLAPPED,  // Window style
                  CW_USEDEFAULT,  // Horizontal position of the window
                  CW_USEDEFAULT,  // Vertical position of the window
                  CW_USEDEFAULT,  // Window width
                  CW_USEDEFAULT,  // Window height
                  NULL,           // Handle to the parent window
                  NULL,           // Handle to the menu the identifier
                  hInstance,      // Handle to the application instance
                  NULL);          // Pointer to the window-creation data

  // If it failed to create the window, return FALSE.
  if (!g_hwndMain)
    return FALSE;

  ShowWindow (g_hwndMain, iCmdShow);
  UpdateWindow (g_hwndMain);
  return TRUE;
}

/***********************************************************************

FUNCTION: 
  InitApplication

PURPOSE:
  Declare the window class structure, assign values to the window class
  structure members, and register the window class.

***********************************************************************/
BOOL InitApplication (HINSTANCE hInstance)
{
  WNDCLASS wndclass;

  wndclass.style = CS_HREDRAW | CS_VREDRAW;
  wndclass.lpfnWndProc = (WNDPROC)WndProc;
  wndclass.cbClsExtra = 0;
  wndclass.cbWndExtra = 0;
  wndclass.hIcon = NULL;
  wndclass.hInstance = hInstance;
  wndclass.hCursor = NULL;
  wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH);
  wndclass.lpszMenuName = NULL;
  wndclass.lpszClassName = g_szClassName;
  
  return RegisterClass (&wndclass);
}

/***********************************************************************

FUNCTION: 
  WinMain

PURPOSE: 
  The WinMain function of the application. It is called by the system as
  the initial entry point for this Windows CE-based application.

***********************************************************************/
int WINAPI WinMain (
               HINSTANCE hInstance,     // Handle to the current instance
               HINSTANCE hPrevInstance, // Handle to the previous instance
               LPWSTR lpCmdLine,        // Pointer to the command line
               int iCmdShow)            // Shows the state of the window
{
  MSG msg;                             // Message structure
  HACCEL hAccel;                       // Handle of the accelerator 
                                      // table
    

// Use this code to prevent your application from starting twice
// assuming that your application has not changed its window text
if (FindWindow(g_szClassName, g_szTitle)){
   SetForegroundWindow(FindWindow(g_szClassName, g_szTitle));
   return FALSE;
}
  

  if (!hPrevInstance)
  {
    if (!InitApplication (hInstance))
      return FALSE; 
  }

  if (!InitInstance (hInstance, iCmdShow))
    return FALSE;
  
  // Insert code here to load the accelerator table.
  // hAccel = LoadAccelerators (...);
  
  while (GetMessage (&msg, NULL, 0, 0))
  {
    if (!TranslateAccelerator (
                    g_hwndMain,     // Handle to the destination window
                    hAccel,         // Handle to the accelerator table
                    &msg))          // Address of the message data
    {
      TranslateMessage (&msg);
      DispatchMessage (&msg);
    }
  }
  
  return msg.wParam;
}

