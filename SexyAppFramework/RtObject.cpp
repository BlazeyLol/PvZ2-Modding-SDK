//
// RtObject.cpp
//

#include "RtObject.h"
#include "RtClass.h"
#include "RtSerializeContext.h"

//

Sexy::RtObject::RtObject()
{
}


Sexy::RtClass* Sexy::RtObject::s_rtClass = nullptr;

Sexy::RtClass* Sexy::RtObject::StaticGetType()
{
    if (!s_rtClass)
    {
        Sexy::RtClass* rtClass = RtClass::Construct();
        s_rtClass = rtClass;
        rtClass->RegisterClass("RtObject", nullptr, reinterpret_cast<RtClassConstruct>(Construct));
    }

    return s_rtClass;
}

Sexy::RtObject* Sexy::RtObject::Construct()
{
	return nullptr;
}


Sexy::RtClass* Sexy::RtObject::GetType() const
{
	return StaticGetType();
}

bool Sexy::RtObject::Function1() const
{
	return true;
}

Sexy::RtObject::~RtObject()
{
}

bool Sexy::RtObject::IsType(Sexy::RtClass* theClass) const
{
	auto* thisType = GetType();
	return thisType->CompareTypes(theClass);
}

// what the fuck is even the point of this method
bool Sexy::RtObject::Function5() const
{
	return true;
}

bool Sexy::RtObject::Serialize(const RtSerializeContext& serializeContext)
{
    auto* parentType = GetType();
    Reflection::RClass* rclass = nullptr;

    while (true)
    {
        rclass = parentType->m_rclass;
        if (rclass) {
            break;
        }

        parentType = parentType->m_super;
        if (!parentType) {
            return false;
        }
    }

    return false;
    // Reflection::RClass::Func1238558
    //return CallFunc<bool, Reflection::RClass*, RtObject*, void*, const SexyString&, const std::vector<SexyString>& >(
    //    0x1238558, rclass, this, serializeContext.unk, serializeContext.unk2, serializeContext.unk3
    //);
}