//
// RtDb.cpp
//

#include "RtDb.h"
#include "RtDbTable.h"
#include "GameCommon.h"
#include "RtWeakPtr.h"

//

Sexy::RtDb::RtDb()
{
	CallFunc<RtDb*, RtDb*>(0x10DF458, this);
}


Sexy::RtDb* s_instance = nullptr;

Sexy::RtDb* Sexy::RtDb::GetInstance()
{
	auto* rtDb = s_instance;

	if (!s_instance)
	{
		rtDb = new RtDb();
		*reinterpret_cast<RtDb**>(GetProcAddress(0x1D96DE4)) = rtDb;
		s_instance = rtDb;
	}

	return rtDb;
}


Sexy::RtWeakPtr<Sexy::RtObject> Sexy::RtDb::ResolveRtId(RtWeakPtr<RtObject>* theObjectPtr)
{
	RtWeakPtr<RtObject> handler;
	CallFunc<void, RtWeakPtr<RtObject>*, void*, RtWeakPtr<RtObject>*>(0x10DFA5C, &handler, this, theObjectPtr);
	return handler;
}

Sexy::RtDbTable* Sexy::RtDb::GetTableForType(int theObjectType)
{

}