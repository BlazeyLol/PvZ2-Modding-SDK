//
// RtObject.cpp
//

#include "RtObject.h"

//

Sexy::RtObject::RtObject()
{
}


Sexy::RtClass* Sexy::RtObject::s_rtClass = nullptr;

Sexy::RtClass* Sexy::RtObject::StaticGetType()
{
    return nullptr;
    // if (!s_rtClass)
    // {
    //     Sexy::RtClass* rtClass = new Sexy::RtClass();
    //     s_rtClass = rtClass;
    //     rtClass->RegisterClass("RtObject", nullptr, reinterpret_cast<void* (*)>(Construct));
    // }
    // return s_rtClass;
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

bool Sexy::RtObject::IsRelated(Sexy::RtClass* theClass) const
{
    return true;
	// auto* thisType = GetType();
	// thisType->CompareTypes(theClass);
}

// what the fuck is even the point of this method
bool Sexy::RtObject::Function5() const
{
	return true;
}

bool Sexy::RtObject::Serialize(const RtSerializeContext& serializeContext)
{
    return false;
    // LOGI("Serializing RtObject...");
    // auto* parentType = GetType();
    // Reflection::RClass* rclass = nullptr;

    // while (true)
    // {
    //     rclass = parentType->m_rclass;
    //     if (rclass)
    //         break;
    //     parentType = parentType->m_super;
    //     if (!parentType)
    //         return false;
    // }
	
    // // Reflection::RClass::Func1238558
    // // Perhaps it's serializing Reflection Class from json
    // LOGI("unk2 (SexyString): %s", serializeContext.unk2.c_str());
    // for (auto& str : serializeContext.unk3)
    // {
    //     LOGI("unk3 (std::vector<SexyString>): %s", str.c_str());
    // }
    // return CallFunc<bool, Reflection::RClass*, RtObject*, void*, const SexyString&, const std::vector<SexyString>& >(
    //     0x1238558, rclass, this, serializeContext.unk, serializeContext.unk2, serializeContext.unk3
    // );
}