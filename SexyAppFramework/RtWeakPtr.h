//
// RtWeakPtr.h
//

#ifndef __RtWeakPtr__
#define __RtWeakPtr__

#include "GameCommon.h"
#include "RtDb.h"

//

#define NULL_RTID 0LL

namespace Sexy
{

	using RtId = int64_t;


	template<typename _T>
	class RtWeakPtr
	{
	public:

		RtWeakPtr()
		{
			mRtId = NULL_RTID;
		}

		RtWeakPtr(RtId theId)
		{
			SetToken(theId);
		}

		~RtWeakPtr()
		{
			SetToken(NULL_RTID);
		}


		bool IsInvalid()
		{
			return mRtId == NULL_RTID;
		}

		bool IsValid()
		{
			return mRtId != NULL_RTID;
		}

		bool IsFromSheets()
		{
			return mRtId >> 0x1F;
		}

		int GetTypeId()
		{
			return (mRtId >> 0x31) & 0x3FFF;
		}

		int GetRefCount()
		{
			return (mRtId >> 0x1F) & 0x7FFFFFFF;
		}

		RtId GetRtId()
		{
			return mRtId;
		}

		void SetToken(RtId theId)
		{
			CallFunc<void, RtWeakPtr*, RtId>(0x10C88C8, this, theId);
		}

		void Move(RtId& theId)
		{
			if (mRtId) {
				SetToken(NULL_RTID);
			}

			mRtId = theId;
			theId = NULL_RTID;
		}

		void Move(const RtWeakPtr& theOther)
		{
			Move(theOther.mRtId);
		}

		void Move(RtWeakPtr* theOther)
		{
			Move(theOther->mRtId);
		}

		inline _T* Get()
		{
			RtDb* rtDb = RtDb::GetInstance();
			RtWeakPtr<RtObject> objectPtr = rtDb->ResolveRtId(this);

			RtObject* object = nullptr;
			if (!objectPtr.IsInvalid())
			{
				int typeId = objectPtr.GetTypeId();
				RtDbTable* table = rtDb->GetTableForType(typeId);

				if (table)
				{
					object = table->GetObject(objectPtr);
				}
			}

			return reinterpret_cast<_T*>(object);
		}

		template<typename Type>
		inline RtWeakPtr<Type> CastPtr()
		{
			return RtWeakPtr<Type>(mRtId);
		}


		RtWeakPtr& operator=(RtWeakPtr* theOther)
		{
			SetToken(theOther->mRtId);
			return *this;
		}

		_T* operator->()
		{
			return Get();
		}

		bool operator==(RtWeakPtr* theOther)
		{
			return CallFunc<bool, RtWeakPtr*, RtWeakPtr*>(0x24D110, this, theOther);
		}

	private:

		RtId mRtId;

	};
	
} // Sexy

#endif // __RtWeakPtr__