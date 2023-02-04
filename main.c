#include <stdio.h>

#ifndef __DYNAMICLOADDLL
int main()
{
    int result = add(1, 2);
    printf("Add 1 and 2 is: %d\n", result);
    return 0;
}
#else
#include <windows.h>
int main()
{
    // define functional pointer
    int(*add)(int, int) = NULL;

    // load dll file, require windows.h file
    HMODULE module = LoadLibrary("add.dll");

    if (module != NULL)
    {
        // get function of dll 
        add = (int(*)(int, int))GetProcAddress(module, "add");

        if (add != NULL) 
        {
            int result = add(1, 2);
            printf("Add 1 and 2 is: %d\n", result);
        }
        else
        {
            printf("Fail to get all module!\n");
        }
    }
    else
    {
        printf("Fail to load dll!\n");
    }

    //FreeLibrary(module);
    return 0;
}
#endif