//
// BaseResource.h
//

#ifndef __BaseResource__
#define __BaseResource__

#include "Core.h"
#include "ResourceClass.h"

//

namespace Sexy
{

	class BaseResource : public RtObject
	{
	public:
		RT_CLASS_DEFINE(BaseResource, RtObject, ResourceClass);

		char pad_0004[4];
		RtWeakPtr<BaseResource> m_thisPtr;
		RtWeakPtr<void> m_resInfo;


		BaseResource();
		virtual ~BaseResource() override;

		static RtWeakPtr<BaseResource> GetThisPtr(BaseResource* self);

	};

} // Sexy

#endif // __BaseResource__