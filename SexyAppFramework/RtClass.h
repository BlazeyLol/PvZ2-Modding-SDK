//
// RtClass.h
//

#ifndef __RtClass__
#define __RtClass__

#include "RtObject.h"
#include "RtWeakPtr.h"
#include "Reflection.h"

//


#define RT_CLASS_DEFINE(classType, ancestorType, rtClassType) \
    static Sexy::RtClass* s_rtClass; \
    static rtClassType* StaticGetType() \
    { \
        if (!s_rtClass) \
        { \
            auto* rtClass = new rtClassType(); \
            s_rtClass = rtClass; \
            auto* ancestorClass = ancestorType::StaticGetType(); \
            rtClass->RegisterClass(#classType, ancestorClass, reinterpret_cast<Sexy::RtClassConstruct>(Construct)); \
            StaticClassInit(); \
        } \
        return s_rtClass; \
    } \
    rtClassType* GetType() const override { return StaticGetType(); } \
    bool Function1() const override { return false; } \
    static void StaticClassInit();\
    static classType* Construct() \
    { \
        return new classType(); \
    } \


#define RT_CLASS_IMPLEMENT(classType) \
    Sexy::RtClass* classType::s_rtClass = nullptr; \


namespace Sexy
{

	class RtIdProtocol;

	using RtClassConstruct = void* (*)();


	class RtClass : public RtObject
	{
	public:
		RT_CLASS_DEFINE(RtClass, RtObject, RtClass);

		const char* m_name;
		RtClass* m_super;
		RtClassConstruct m_constructor;
		RtWeakPtr<RtClass> m_thisPtr;
		RtIdProtocol* m_protocol1;
		RtIdProtocol* m_protocol2;
		RtIdProtocol* m_protocol3;
		Reflection::RClass* m_rclass;


		RtClass();
		virtual ~RtClass() override;

		void BindRClass(Reflection::RClass* theRClass);
		RtWeakPtr<RtClass> GetClassRef();

		virtual bool Serialize(const RtSerializeContext& serializeContext) override;

		virtual bool CompareTypes(RtClass* theClass) const;
		virtual void RegisterClass(const char* theName, RtClass* theSuper, RtClassConstruct theConstructor);

	};

} // Sexy

#endif // __RtClass__