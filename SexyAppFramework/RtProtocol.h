//
// RtProtocol.h
//

#ifndef __RtProtocol__
#define __RtProtocol__

#include "Core.h"

//

namespace Sexy
{

	class RtProtocol : public RtObject
	{
	public:
		RT_CLASS_DEFINE(RtProtocol, RtObject, RtClass);

		RtProtocol();
		virtual ~RtProtocol() override;

	};

} // Sexy

#endif // __RtProtocol__