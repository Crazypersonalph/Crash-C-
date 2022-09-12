#include <windows.h>
#include <iostream>

#pragma comment(lib, "ntdll.lib")


EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);

int main(void)
{
     int counter = 15;
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