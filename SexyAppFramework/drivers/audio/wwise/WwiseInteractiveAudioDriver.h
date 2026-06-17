//
// WwiseInteractiveAudioDriver.h
//

#ifndef __WwiseInteractiveAudioDriver__
#define __WwiseInteractiveAudioDriver__

#include "GameCommon.h"
#include "drivers/audio/IInteractiveAudioDriver.h"

//

namespace Sexy
{
	
	class WwiseInteractiveAudioDriver : public IInteractiveAudioDriver
	{
	public:
		
		virtual ~WwiseInteractiveAudioDriver() {}
		virtual void Function2() {}
		virtual void Function3() {}
		virtual void Function4() {}
		virtual void Function5() {}
		virtual void Function6() {}
		virtual int PostEvent(const std::string& eventName, uint64 gameObjectId) {}
		virtual void Function8() {}
		virtual void Function9() {}
		virtual void Function10() {}
		virtual void Function11() {}
		virtual void Function12() {}
		virtual void Function13() {}
		virtual void Function14() {}
		virtual void Function15() {}
		virtual void Function16() {}
		virtual void Function17() {}
		virtual void Function18() {}
		virtual void Function19() {}
		virtual void Function20() {}
		virtual int GetIDFromString(const char* string) {}
		virtual void Function22() {}
		virtual void Function23() {}
		virtual void Function24() {}
		virtual int SetSwitch(const std::string& switchGroup, const std::string& switchState, uint64 gameObjectId) {}
		virtual void Function26() {}
		virtual void Function27() {}
		
	};
	
} // Sexy

#endif // __WwiseInteractiveAudioDriver__