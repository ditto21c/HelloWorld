#include <windows.h>

BOOL InitApplication(HINSTANCE hinstance); 
BOOL InitInstance(HINSTANCE hinstance, int nCmdShow);
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

INT __stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PSTR lpCmdLine, INT nCmdShow)
{
	MSG msg; 

	if (!InitApplication(hInstance)) 
        return FALSE; 
 
    if (!InitInstance(hInstance, nCmdShow)) 
        return FALSE; 

	BOOL fGotMessage;
    while ((fGotMessage = GetMessage(&msg, (HWND) NULL, 0, 0)) != 0 && fGotMessage != -1) 
    { 
        TranslateMessage(&msg); 
        DispatchMessage(&msg); 
    } 
    return msg.wParam; 

    return 0;
}

LRESULT CALLBACK MainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		break;
	default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam); 
		break;
	}
	return 0;
}

BOOL InitApplication(HINSTANCE hinstance) 
{ 
    WNDCLASSEX wcx; 
 
    // Fill in the window class structure with parameters 
    // that describe the main window. 
 
    wcx.cbSize = sizeof(wcx);          // size of structure 
    wcx.style = CS_HREDRAW | 
        CS_VREDRAW;                    // redraw if size changes 
    wcx.lpfnWndProc = MainWndProc;     // points to window procedure 
    wcx.cbClsExtra = 0;                // no extra class memory 
    wcx.cbWndExtra = 0;                // no extra window memory 
    wcx.hInstance = hinstance;         // handle to instance 
    wcx.hIcon = LoadIcon(NULL, 
        IDI_APPLICATION);              // predefined app. icon 
	wcx.hCursor = LoadCursor(NULL, 
        IDC_ARROW);                    // predefined arrow 
	wcx.hbrBackground = (HBRUSH)GetStockObject( 
        WHITE_BRUSH);                // white background brush 

    wcx.lpszMenuName =  L"MainMenu";    // name of menu resource 
    wcx.lpszClassName = L"MainWClass";  // name of window class 
    wcx.hIconSm = NULL;
	DWORD dwErr = GetLastError(); 
    // Register the window class. 
 
    return RegisterClassEx(&wcx); 
} 

BOOL InitInstance(HINSTANCE hinstance, int nCmdShow) 
{ 
	DWORD dwStyle = WS_OVERLAPPEDWINDOW;
	HWND hWnd = CreateWindow(L"MainWClass", L"HelloWorld", dwStyle, CW_USEDEFAULT, CW_USEDEFAULT, 1024, 768, NULL, NULL, hinstance, NULL);
	DWORD dwErr = GetLastError();
    if (!hWnd) 
        return FALSE; 
 
    // Show the window and send a WM_PAINT message to the window 
    // procedure. 
    ShowWindow(hWnd, nCmdShow); 
    //UpdateWindow(hWnd); 
    return TRUE; 
 
} 