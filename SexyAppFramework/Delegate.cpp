//
// Delegate.cpp
//

#include "Delegate.h"

//

Sexy::DelegateBase::DelegateBase() :
	m_callback(nullptr),
	m_useOwnerVFTable(false),
	m_owner(nullptr),
	m_initialized(false),
	m_callbackInvoker(nullptr)
{}


int Sexy::DelegateBase::InvokeCallback(uintptr_t a2, uintptr_t a3)
{
	int result = ((int(*)(DelegateBase*))m_callbackInvoker)(this);
	if (a2)
	{
		*(int*)(a2 + 8) = 0;
		*((int*)a2) = 1;
		return 1;
	}
	return result;
}

int Sexy::DelegateBase::Invoke(uintptr_t a2, uintptr_t a3)
{
	return InvokeCallback(0, a3);
}

Sexy::DelegateBase::~DelegateBase()
{}