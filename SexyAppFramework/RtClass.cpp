//
// RtClass.cpp
//

#include "RtClass.h"
#include "RtIdProtocol.h"
#include "RTONDB.h"

//

RT_CLASS_IMPLEMENT(Sexy::RtClass);
void Sexy::RtClass::StaticClassInit()
{
	CallFunc<>(0x1250344);
}


Sexy::RtClass::RtClass()
{
	m_name = nullptr;
	m_super = nullptr;
	m_constructor = nullptr;

	m_protocol1 = nullptr;
	m_protocol2 = nullptr;
	m_protocol3 = nullptr;
	m_rclass = nullptr;

	RtDb* rtDb = Sexy::RtDb::GetInstance();
	RtDbTable* table = rtDb->GetTableForType(0x2002);
	RtWeakPtr<RtObject> thisPtr;

	if (!table)
	{
		RTONDB* rtonDb = RTONDB::GetInstance();

		rtonDb->DecInstanceCount(0);
		int refCount = rtonDb->GetRefCount("System.RtClasses");

		rtonDb->IncInstanceCount(refCount);
		const char* entryName = rtonDb->GetEntryName(refCount);

		rtDb->MakeNewTable(0x2002, &thisPtr);
		rtonDb->DecInstanceCount(refCount);
	}

	thisPtr = *table->AddObject(this, 2);
	m_thisPtr.Move(thisPtr.CastPtr<RtClass>());

}

Sexy::RtClass::~RtClass()
{
	RtDb* rtDb = Sexy::RtDb::GetInstance();
	RtDbTable* table = rtDb->GetTableForType(0x2002);

	if (table)
	{
		table->EraseObject(m_thisPtr.CastPtr<RtObject>());
	}
}


Sexy::RtWeakPtr<Sexy::RtClass> Sexy::RtClass::GetThisPtr(RtClass* self)
{
	if (self && self->IsType(RtClass::StaticGetType()))
	{
		return self->m_thisPtr;
	}

	return RtWeakPtr<RtClass>();
}


void Sexy::RtClass::BindRClass(Reflection::RClass* theRClass)
{
	m_rclass = theRClass;
}


bool Sexy::RtClass::Serialize(const RtSerializeContext& serializeContext)
{
	return CallFunc<bool, RtClass*, const RtSerializeContext&>(0x1250D40, this, serializeContext);
}


bool Sexy::RtClass::CompareTypes(RtClass* theClass) const
{
	if (!theClass || !this) {
		return false;
	}

	const RtClass* rtClass = this;
	while (rtClass != theClass)
	{
		rtClass = rtClass->m_super;

		if (!rtClass)
		{
			return false;
		}
	}

	return true;
}

void Sexy::RtClass::RegisterClass(const char* theName, RtClass* theSuper, RtClassConstruct theConstructor)
{
	m_name = theName;
	m_super = theSuper;
	m_constructor = theConstructor;

	CallFunc<void, RtClass*, const char*, RtClass*, RtClassConstruct>(0x1250B90, this, theName, theSuper, theConstructor);
}