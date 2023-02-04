#include <windows.h>
#include <stdio.h>



#ifdef __cplusplus
extern "C" {
#endif


BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    // Perform actions based on the reason for calling.
    switch( fdwReason ) 
    { 
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
            printf("DLL process attach\n");
            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            printf("DLL thread attach\n");
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            printf("DLL thread detach\n");
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            FreeLibrary(hinstDLL);
            printf("Free dll Library\n");
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}


#ifdef __cplusplus
}
#endif