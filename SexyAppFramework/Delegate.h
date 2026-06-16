//
// Delegate.h
//

#ifndef __Delegate__
#define __Delegate__

#include "GameCommon.h"


namespace Sexy
{

	class DelegateBase
	{
	public:

		void* m_callback;
		bool m_useOwnerVFTable;
		void* m_owner;
		bool m_initialized;
		void* m_callbackInvoker;


		DelegateBase();

		virtual int InvokeCallback(uintptr_t a2, uintptr_t a3);
		virtual int Invoke(uintptr_t a2, uintptr_t a3);
		virtual ~DelegateBase();

	};

	//

	template<typename R>
	class DelegateWRetBase : public DelegateBase
	{
	public:

		DelegateWRetBase()
		{
			m_callback = nullptr;
			m_owner = nullptr;
			m_initialized = false;
			m_useOwnerVFTable = false;

			m_callbackInvoker = nullptr;
		}

		DelegateWRetBase(void* theCallback, void* theOwner)
		{
			m_callback = theCallback;
			m_owner = theOwner;
			m_initialized = true;
			m_useOwnerVFTable = false;

			m_callbackInvoker = (void*)StaticCallbackInvoker;
		}


		static R StaticCallbackInvoker(DelegateWRetBase* theDelegate)
		{
			return ((R(*)(void*))theDelegate->m_callback)(theDelegate->m_owner);
		}

		virtual R InvokeWithReturn(DelegateBase* a2) {}

	};

	//

	template<typename R, typename Param1>
	class Delegate1wRet : public DelegateWRetBase<int>
	{
	public:

		Delegate1wRet()
		{
			m_callback = nullptr;
			m_owner = nullptr;
			m_initialized = false;
			m_useOwnerVFTable = false;

			m_callbackInvoker = nullptr;
		}

		Delegate1wRet(void* theCallback, void* theOwner)
		{
			m_callback = theCallback;
			m_owner = theOwner;
			m_initialized = true;
			m_useOwnerVFTable = false;

			m_callbackInvoker = (void*)StaticCallbackInvoker;
		}


		static R StaticCallbackInvoker(Delegate1wRet* theDelegate, Param1 arg1)
		{
			return ((R(*)(void*, Param1))theDelegate->m_callback)(theDelegate->m_owner, arg1);
		}

	};

} // Sexy

#endif // __Delegate__