//
// ResourceClass.h
//

#ifndef __ResourceClass__
#define __ResourceClass__

#include "Core.h"

//

namespace Sexy
{

	class ResourceClass : public RtClass
	{
	public:
		RT_CLASS_DEFINE(ResourceClass, RtClass, RtClass);

		void* m_resInfoType;


		ResourceClass();
		virtual ~ResourceClass() override;

	};

} // Sexy

#endif // __ResourceClass__