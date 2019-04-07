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
//            case VK_CAPITAL:	out << "<CAPLOCK>";		break;
//            case VK_SHIFT:		out << "<SHIFT>";		break;
//            case VK_LCONTROL:	out << "<LCTRL>";		break;
//            case VK_RCONTROL:	out << "<RCTRL>";		break;
//            case VK_INSERT:		out << "<INSERT>";		break;
//            case VK_END:		out << "<END>";			break;
//            case VK_PRINT:		out << "<PRINT>";		break;
//            case VK_DELETE:		out << "<DEL>";			break;
//            case VK_BACK:		out << "<BK>";			break;
//            case VK_LEFT:		out << "<LEFT>";		break;
//            case VK_RIGHT:		out << "<RIGHT>";		break;
//            case VK_UP:			out << "<UP>";			break;
//            case VK_DOWN:		out << "<DOWN>";		break;
                // Visible keys
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
//    stealth();
    HHOOK keyboardHook = SetWindowsHookEx(
            WH_KEYBOARD_LL,
            keyboardHookProc,
            hInstance,
            0);
    MSG messages;
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }
    return 0;
}