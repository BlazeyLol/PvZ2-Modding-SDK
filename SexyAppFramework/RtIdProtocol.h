//
// RtIdProtocol.h
//

#ifndef __RtIdProtocol__
#define __RtIdProtocol__

#include "RtProtocol.h"
#include "Delegate.h"

//

namespace Sexy
{

	class RtIdProtocol : public RtProtocol
	{
	public:
		RT_CLASS_DEFINE(RtIdProtocol, RtProtocol, RtClass);

		Delegate1wRet<RtId, RtObject*> m_delegate;


		RtIdProtocol();
		virtual ~RtIdProtocol() override;

		void AssignDelegate(const Delegate1wRet<RtId, RtObject*>& delegate);

	};

} // Sexy

#endif // __RtIdProtocol__