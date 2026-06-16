//
// RTONDB.cpp
//

#include "RTONDB.h"
#include "GameCommon.h"

//

Sexy::RTONDB::RTONDB()
{}


Sexy::RTONDB* Sexy::RTONDB::s_instance = nullptr;

Sexy::RTONDB* Sexy::RTONDB::GetInstance()
{
	auto* rtonDb = s_instance;

	if (!s_instance)
	{
		rtonDb = new RTONDB();
		*reinterpret_cast<RTONDB**>(GetProcAddress(0x1CF6C34)) = rtonDb;
		s_instance = rtonDb;
	}

	return rtonDb;
}


void Sexy::RTONDB::IncInstanceCount(int theRefCount)
{
	CallFunc<void, RTONDB*, int>(0x10C8830, this, theRefCount);
}

void Sexy::RTONDB::DecInstanceCount(int theRefCount)
{
	CallFunc<void, RTONDB*, int>(0x10C8858, this, theRefCount);
}

const char* Sexy::RTONDB::GetEntryName(int theRefCount)
{
	return CallFunc<const char*, RTONDB*, int>(0x10C87E0, this, theRefCount);
}

int Sexy::RTONDB::GetRefCount(const char* theName)
{
	return CallFunc<int, RTONDB*, const char*>(0x10C87A4, this, theName);
}