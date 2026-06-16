//
// RTONDB.h
//

#ifndef __RTONDB__
#define __RTONDB__


namespace Sexy
{

	class RTONDB
	{
	public:

		RTONDB();

		static RTONDB* s_instance;
		static RTONDB* GetInstance();

		void IncInstanceCount(int theRefCount);
		void DecInstanceCount(int theRefCount);
		const char* GetEntryName(int theRefCount);
		int GetRefCount(const char* theName);

	};

} // Sexy

#endif // __RTONDB__