#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <iostream>
using namespace std;

bool kill(const char *filename){
	DWORD d;
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, d);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof (pEntry);
    BOOL hRes = Process32First(hSnapShot, &pEntry);
	bool killed=false;
    while (hRes){
        if (strcmp(pEntry.szExeFile, filename) == 0){
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0, (DWORD)pEntry.th32ProcessID);
            if (hProcess != NULL){
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
return true;
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
return false;
    CloseHandle(hSnapShot);
}

int main(){
	kill("timeBeforeCyberpunk2077.exe");
return 0;
}