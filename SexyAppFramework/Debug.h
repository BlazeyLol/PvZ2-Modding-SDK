//
// Debug.h
//

#ifndef __Debug__
#define __Debug__

#include "GameCommon.h"


namespace Sexy
{

    void OutputDebugStr(const std::string& fmt);
    void OutputDebugStrI(const std::string& fmt, int i);
    void OutputDebugStrF(const std::string& fmt, float f);

} // Sexy

#endif // __Debug__