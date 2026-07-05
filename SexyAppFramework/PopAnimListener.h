//
// PopAnimListener.h
//

#ifndef __PopAnimListener__
#define __PopAnimListener__

#include "GameCommon.h"


namespace Sexy
{

	class PopAnimListener
	{
	public:

		virtual ~PopAnimListener() {}
		virtual void PopAnimPlaySample(const std::string& theSampleName, int thePan, double theVolume, double theNumSteps) {}
		virtual void PopAnimStopped(int theId) {}
		virtual void PopAnimCommand(int theId, const std::string& theCommand, const std::string& theParam) {}
		virtual bool PopAnimCommand(int theId, void* theSpriteInst, const std::string& theCommand, const std::string& theParam) {}

	};

} // Sexy

#endif // __PopAnimListener__