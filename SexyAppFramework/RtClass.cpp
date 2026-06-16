//
// RtClass.cpp
//

#include "RtClass.h"

//

Sexy::RtClass::RtClass()
{
	m_name = nullptr;
	m_super = nullptr;
	m_constructor = nullptr;

	m_protocol1 = nullptr;
	m_protocol2 = nullptr;
	m_protocol3 = nullptr;
	m_rclass = nullptr;

	//auto* rtDb = Sexy::RtDb::GetInstance();
	//auto* table = rtDb->GetTable(0x2002);

	//if (!table)
	//{

	//}

	
}

Sexy::RtClass::~RtClass()
{

}


Sexy::RtClass* Sexy::RtClass::s_rtClass = nullptr;

Sexy::RtClass* Sexy::RtClass::StaticGetType()
{
	if (!s_rtClass)
	{
		Sexy::RtClass* rtClass = RtClass::Construct();
		s_rtClass = rtClass;

		RtClass* super = RtObject::StaticGetType();
		rtClass->RegisterClass("RtClass", super, reinterpret_cast<RtClassConstruct>(Construct));
		StaticClassInit();
	}

	return s_rtClass;
}

Sexy::RtClass* Sexy::RtClass::Construct()
{
	return new RtClass();
}

void Sexy::RtClass::StaticClassInit()
{

}


void Sexy::RtClass::BindRClass(Reflection::RClass* theRClass)
{
	m_rclass = theRClass;
}

Sexy::RtWeakPtr<Sexy::RtClass> Sexy::RtClass::GetClassRef()
{
	if (this && IsType(RtClass::StaticGetType()))
	{
		return m_thisPtr;
	}

	return RtWeakPtr<RtClass>();
}


Sexy::RtClass* Sexy::RtClass::GetType() const
{
	return StaticGetType();
}

bool Sexy::RtClass::Function1() const
{
	return false;
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