//
// Debug.cpp
//

#include "Debug.h"
#include <android/log.h>

//

constexpr const char LOGCAT_TAG[] = "PvZ2Mod";

void Sexy::OutputDebugStr(const std::string& fmt)
{
    __android_log_print(ANDROID_LOG_INFO, LOGCAT_TAG, fmt.c_str());
}

void Sexy::OutputDebugStrI(const std::string& fmt, int i)
{
    __android_log_print(ANDROID_LOG_INFO, LOGCAT_TAG, fmt.c_str(), i);
}

void Sexy::OutputDebugStrF(const std::string& fmt, float f)
{
    __android_log_print(ANDROID_LOG_INFO, LOGCAT_TAG, fmt.c_str(), f);
}