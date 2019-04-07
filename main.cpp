#define _WIN32_WINNT 0x0500
#include<fstream>
#include<windows.h>
using namespace std;
LRESULT CALLBACK keyboardHookProc(int nCode, WPARAM wParam, LPARAM lParam) {
    PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) (lParam);

    if (wParam == WM_KEYDOWN) {
        switch (p->vkCode) {
            case VK_RETURN:
                PlaySound(TEXT("typewriter_enter.wav"), NULL, SND_ASYNC);
                break;
            default:
                PlaySound(TEXT("typewriter_key.wav"), NULL, SND_ASYNC);
        }

    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void stealth() {
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("consoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    stealth();
    HHOOK keyboardHook = SetWindowsHookEx(
            WH_KEYBOARD_LL,
            keyboardHookProc,
            hInstance,
            0);
    MSG messages;
    while (GetMessage (&messages, NULL, 0, 0)){}
    return 0;
}