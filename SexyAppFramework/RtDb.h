//
// RtDb.h
//

#ifndef __RtDb__
#define __RtDb__

#include "RtDbTable.h"

//

namespace Sexy
{

	template<typename _T>
	class RtWeakPtr;
	class RtObject;


	class RtDb
	{
	public:

		RtDb();
		
		static RtDb* s_instance;
		static RtDb* GetInstance();

		RtWeakPtr<RtObject> ResolveRtId(RtWeakPtr<RtObject>* theObjectPtr);
		RtDbTable* GetTableForType(int theObjectType);
		//RtDbTable* MakeNewTable(int theObjectType);


	};

} // Sexy

#endif // __RtDb__