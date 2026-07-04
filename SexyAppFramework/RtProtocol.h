//
// RtProtocol.h
//

#ifndef __RtProtocol__
#define __RtProtocol__

#include "RtObject.h"
#include "RtClass.h"

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