//
// AudioMgr.h
//

#ifndef __AudioMgr__
#define __AudioMgr__

#include "LazySingleton.h"
#include "drivers/audio/wwise/WwiseInteractiveAudioDriver.h"

//

class AudioMgr : public Sexy::LazySingleton<AudioMgr>
{

};

#endif // __AudioMgr__