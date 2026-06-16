//
// PvZ2Mod.cpp
//

#include "GameCommon.h"
#include "Debug.h"


__attribute__((constructor))
static void LibInit()
{
	Sexy::OutputDebugStr("Hello");
}