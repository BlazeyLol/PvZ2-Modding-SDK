//
// RtClass.h
//

#ifndef __RtClass__
#define __RtClass__

#include "RtObject.h"
#include "RtWeakPtr.h"
#include "Reflection.h"

//

namespace Sexy
{

	using RtClassConstruct = void* (*)();


	class RtClass : public RtObject
	{
	public:

		const char* m_name;
		RtClass* m_super;
		RtClassConstruct m_constructor;
		RtWeakPtr<RtClass> m_thisPtr;
		void* m_protocol1;
		void* m_protocol2;
		void* m_protocol3;
		Reflection::RClass* m_rclass;


		RtClass();
		virtual ~RtClass() override;

		static RtClass* s_rtClass;
		static RtClass* StaticGetType();
		static RtClass* Construct();
		static void StaticClassInit();

		void BindRClass(Reflection::RClass* theRClass);
		RtWeakPtr<RtClass> GetClassRef();

		virtual RtClass* GetType() const override;
		virtual bool Function1() const override;
		virtual bool Serialize(const RtSerializeContext& serializeContext) override;

		virtual bool CompareTypes(RtClass* theClass) const;
		virtual void RegisterClass(const char* theName, RtClass* theSuper, RtClassConstruct theConstructor);

	};

} // Sexy

#endif // __RtClass__