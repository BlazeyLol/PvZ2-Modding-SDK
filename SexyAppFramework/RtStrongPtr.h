//
// RtStrongPtr.h
//

#ifndef __RtStrongPtr__
#define __RtStrongPtr__

#include "RtWeakPtr.h"

//

namespace Sexy
{

	template<typename _T>
	class RtStrongPtr : public RtWeakPtr<_T>
	{
	public:

		RtStrongPtr()
		{
			mRtId = NULL_RTID;
		}

		RtStrongPtr(RtId theId)
		{
			SetToken(theId);
		}

		~RtStrongPtr()
		{
			SetToken(NULL_RTID);


			// TODO: complete the logic to deallocate the object once the ref count hits zero
			if (false)
			{

			}
		}
	};

} // Sexy

#endif // __RtStrongPtr__