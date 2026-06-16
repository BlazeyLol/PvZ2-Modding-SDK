//
// GameCommon.h
//

#ifndef __GameCommon__
#define __GameCommon__

#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cstdlib>


#ifdef __arm__
#define IFARM(armV, a64V) armV

#elif defined __aarch64__
#define IFARM(armV, a64V) a64V

#endif


using uchar = unsigned char;
using ushort = unsigned short;
using uint = unsigned int;
using ulong = unsigned long;
using int64 = int64_t;

// deprecated type aliases
using SexyString = std::string;
using SexyChar = SexyString::value_type;
using StringVector = std::vector<SexyString>;
using DefinesMap = std::map<SexyString, SexyString>;


namespace Sexy
{

	std::string StrFormat(const char* fmt ...);
	uintptr_t LoadLibrary(const char* libName);
	uintptr_t GetProcAddress(uintptr_t offset);
	void HookFunc(uintptr_t offset, void* replacement, void** original = nullptr);
	
	template<typename R = void, typename... Args>
	R CallFunc(uintptr_t offset, Args... args)
	{
		using funcDef = R(*)(Args...);
		funcDef function = reinterpret_cast<funcDef>(GetProcAddress(offset));
		return function(args...);
	}

} // Sexy

using namespace Sexy;


#endif // __GameCommon__