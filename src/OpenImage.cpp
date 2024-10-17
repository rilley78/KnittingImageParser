#include <string>
#include <nfd.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

bool OpenImage(std::string* link)
{
    
    NFD_Init();

    std::string cancel = "User pressed cancel";
    bool show_window = false;
    nfdu8char_t* outPath;
    nfdu8filteritem_t filters[1] = { { "Images", "png, jpg" } };
    nfdopendialogu8args_t args = { 0 };
    args.filterList = filters;
    args.filterCount = 1;
    nfdresult_t result = NFD_OpenDialogU8_With(&outPath, &args);
    if (result == NFD_OKAY)
    {
        //puts("Success!");
        //puts(outPath);
        *link = outPath;
        //std::cout << *link << std::endl;
        show_window = true;
        NFD_FreePathU8(outPath);
    }
    else if (result == NFD_CANCEL)
    {
        //puts("User pressed cancel.");
        *link = cancel;
    }
    else
    {
        printf("Error: %s\n", NFD_GetError());
    }

    NFD_Quit();
    return show_window;
}