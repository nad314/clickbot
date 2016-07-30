#include <main/main.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR cmd, int nCmdShow) {
	return core::Init()(new clickbot());
}
