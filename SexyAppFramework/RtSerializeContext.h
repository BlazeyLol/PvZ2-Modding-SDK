//
// RtSerializeContext.h
//

#ifndef __RtSerializeContext__
#define __RtSerializeContext__

#include "GameCommon.h"

//

namespace Sexy
{

	class RtSerializeContext
	{
	public:

		char pad_0000[4];
		void* unk;
		std::string unk2;
		std::vector<std::string> unk3;

	};

} // Sexy

#endif // __RtSerializeContext__