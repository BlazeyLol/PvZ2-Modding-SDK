//
// GameObject.cpp
//

#include "GameObject.h"
#include "GameCommon.h"
//#include "MessageRouter.h"
//#include "RtReflectionDelegate.h"
//#include "ReflectionBuilder.h"

//

RT_CLASS_IMPLEMENT(GameObject);
void GameObject::StaticClassInit()
{
	CallFunc<void>(0x53EAB8);

	//REFLECTION_CLASSBUILDER_BEGIN(RtReflectionDelegateBase);
	//REFLECTION_CLASSBUILDER_RTCLASS_BIND;

	//REFLECTION_CLASSBUILDER_FIELD(RtWeakPtr<RtObject>, m_objectId);
	//REFLECTION_CLASSBUILDER_FIELD(SexyString, m_methodName);

	//REFLECTION_CLASSBUILDER_END(RtReflectionDelegateBase);


	//REFLECTION_CLASSBUILDER_BEGIN(GameObject);
	//REFLECTION_CLASSBUILDER_RTCLASS_BIND;
	//REFLECTION_CLASSBUILDER_ANCESTOR(Sexy::RtObject);

	//REFLECTION_CLASSBUILDER_FIELD(RtWeakPtr<GameObject>, m_thisPtr);
	//REFLECTION_CLASSBUILDER_END(GameObject);
}


GameObject::GameObject()
{}

GameObject::~GameObject()
{
	//MessageRouter::GetInstance()->DeregisterCallbacks(this);
}


void GameObject::EraseObject()
{
	CallFunc<void, GameObject*>(0x53F498, this);
}


bool GameObject::Serialize(const Sexy::RtSerializeContext& serializeContext)
{
	return CallFunc<bool, GameObject*, const Sexy::RtSerializeContext&>(0x53F220, this, serializeContext);
}


void GameObject::RegisterForEvents()
{}

void GameObject::DeregisterForEvents()
{}

void GameObject::OnInitialized()
{}

void GameObject::Function10()
{}

void GameObject::OnLoaded()
{}

void GameObject::OnUnloaded()
{}