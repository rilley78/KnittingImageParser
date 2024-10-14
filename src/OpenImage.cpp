#include <string>
#include <nfd.h>
#include <stdio.h>
#include <stdlib.h>

const char* OpenImage(void)
{
    const char* out = "User pressed cancel";
    NFD_Init();

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
        out = outPath;
        NFD_FreePathU8(outPath);
    }
    else if (result == NFD_CANCEL)
    {
        //puts("User pressed cancel.");
    }
    else
    {
        printf("Error: %s\n", NFD_GetError());
    }

    NFD_Quit();
    return out;
}