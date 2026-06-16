//
// BaseResource.cpp
//

#include "BaseResource.h"
#include "RtIdProtocol.h"

//

RT_CLASS_IMPLEMENT(Sexy::BaseResource);
void Sexy::BaseResource::StaticClassInit()
{
	RtIdProtocol* protocol = new RtIdProtocol();
	Delegate1wRet<RtId, RtObject*> delegate = Delegate1wRet<RtId, RtObject*>(reinterpret_cast<void*>(GetThisPtr), nullptr);

	protocol->AssignDelegate(delegate);
	RtClass* type = BaseResource::StaticGetType();
	CallFunc<void, RtClass*, RtIdProtocol*>(0x12504A0, type, protocol);
}


Sexy::BaseResource::BaseResource()
{}

Sexy::BaseResource::~BaseResource()
{}


Sexy::RtWeakPtr<Sexy::BaseResource> Sexy::BaseResource::GetThisPtr(BaseResource* self)
{
	if (self && self->IsType(BaseResource::StaticGetType()))
	{
		return self->m_thisPtr;
	}

	return RtWeakPtr<BaseResource>();
}