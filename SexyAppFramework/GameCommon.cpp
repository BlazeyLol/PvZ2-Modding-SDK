//
// GameCommon.cpp
//

#include "GameCommon.h"
#include <SubstrateHook.h>

//

uintptr_t g_libraryOffset = 0;

std::string Sexy::StrFormat(const char* fmt ...)
{
	return std::string();
}

uintptr_t Sexy::LoadLibrary(const char* libName)
{
    FILE* fp = fopen("/proc/self/maps", "rt");
    if (fp == NULL) {
        perror("fopen");
        return 0;
    }

    uintptr_t addr = 0;
    char line[1024];

    while (fgets(line, sizeof(line), fp) != NULL) {
        if (strstr(line, libName) != NULL) {
            addr = strtoul(line, NULL, 16);
            break;
        }
    }

    fclose(fp);
    return addr;
}

uintptr_t Sexy::GetProcAddress(uintptr_t offset)
{
    if (g_libraryOffset == 0)
    {
        g_libraryOffset = LoadLibrary("PVZ2.so");
    }

    return g_libraryOffset + offset;
}

void Sexy::HookFunc(uintptr_t offset, void* replacement, void** original)
{
    uintptr_t functionOffset = GetProcAddress(offset);
    MSHookFunction(reinterpret_cast<void*>(functionOffset), replacement, original);
}