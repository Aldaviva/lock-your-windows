#include <Windows.h>
#include <WtsApi32.h>
#include <VersionHelpers.h>
#include "winlock.h"

#pragma comment(lib, "WtsApi32.lib")
#pragma comment(lib, "user32.lib")

bool isWorkstationLocked(){
    LPWSTR sessionInfoBuffer;
    DWORD bytesReturned = 0;

    WTSQuerySessionInformation(WTS_CURRENT_SERVER_HANDLE, WTS_CURRENT_SESSION, WTSSessionInfoEx, &sessionInfoBuffer, &bytesReturned);

    WTSINFOEXW* info = (WTSINFOEXW*)sessionInfoBuffer;
    WTSINFOEX_LEVEL1_W* level1Data = (WTSINFOEX_LEVEL1_W*)&info->Data;
    bool isLocked = level1Data->SessionFlags == WTS_SESSIONSTATE_LOCK;

    // https://msdn.microsoft.com/en-us/library/windows/desktop/ee621019(v=vs.85).aspx
    if (IsWindows7OrGreater() && !IsWindows8OrGreater()) {
        isLocked = !isLocked;
    }

    WTSFreeMemory(sessionInfoBuffer);

    return isLocked;
}

void lockWorkstation(){
    LockWorkStation();
}

