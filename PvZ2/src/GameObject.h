//
// GameObject.h
//

#ifndef __GameObject__
#define __GameObject__

#include "Core.h"

//

class GameObject : public Sexy::RtObject
{
public:
	RT_CLASS_DEFINE(GameObject, Sexy::RtObject, Sexy::RtClass);

	char pad_0004[4]; // this field fixes the alignment. It doesn't exist in the src
	Sexy::RtWeakPtr<GameObject> m_thisPtr;


	GameObject();
	virtual ~GameObject() override;

	// Destroys the GameObject, deregisters its callbacks and erases it from the DataBase
	void EraseObject();

	virtual bool Serialize(const Sexy::RtSerializeContext& serializeContext) override;

	virtual void RegisterForEvents();
	virtual void DeregisterForEvents();
	virtual void OnInitialized();
	virtual void Function10();
	virtual void OnLoaded();
	virtual void OnUnloaded();

};

#endif // __GameObject__