//
// RtDbTable.cpp
//

#include "RtDbTable.h"
#include "RtObject.h"
#include "RtWeakPtr.h"

//

Sexy::RtWeakPtr<Sexy::RtObject>* Sexy::RtDbTable::AddObject(RtObject* theObject, int a4, int a5, int a6)
{
	return CallFunc<RtWeakPtr<RtObject>*, RtDbTable*, RtObject*, int, int, int>(0x10DB7B4, this, theObject, a4, a5, a6);
}

Sexy::RtObject* Sexy::RtDbTable::GetObject(const RtWeakPtr<RtObject>& theObjectPtr)
{
	return CallFunc<RtObject*, RtDbTable*, const RtWeakPtr<RtObject>&>(0x10DB9C0, this, theObjectPtr);
}

bool Sexy::RtDbTable::EraseObject(const RtWeakPtr<RtObject>& theObjectPtr)
{
	return CallFunc<bool, RtDbTable*, const RtWeakPtr<RtObject>&>(0x10DA870, this, theObjectPtr);
}