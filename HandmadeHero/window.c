#include<Windows.h>
#include<stdio.h>

typedef struct tagWNDCLASSA {
	UINT      style;
	WNDPROC   lpfnWndProc;
	int       cbClsExtra;
	int       cbWndExtra;
	HINSTANCE hInstance;
	HICON     hIcon;
	HCURSOR   hCursor;
	HBRUSH    hbrBackground;
	LPCSTR    lpszMenuName;
	LPCSTR    lpszClassName;
} WNDCLASSA, * PWNDCLASSA, * NPWNDCLASSA, * LPWNDCLASSA;


LRESULT Wndproc(
	HWND unnamedParam1,
	UINT unnamedParam2,
	WPARAM unnamedParam3,
	LPARAM unnamedParam4
)

int main() {
	WNDCLASSA winclass;
	winclass.style = CS_OWNDC;
	winclass.lpfnWndProc = Wndproc(GetModuleHandle())
	return 0;
}