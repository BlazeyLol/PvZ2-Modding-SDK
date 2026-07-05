//
// Flags.h
//

#ifndef __Flags__
#define __Flags__


namespace Sexy
{

	class FlagsMod
	{
	public:

		int	mAddFlags;
		int	mRemoveFlags;


		FlagsMod();

	};

	//

	inline void ModFlags(int& theFlags, const FlagsMod& theFlagMod);
	inline int GetModFlags(int theFlags, const FlagsMod& theFlagMod);

	//

	class ModalFlags
	{
	public:

		int	mOverFlags;
		int	mUnderFlags;
		bool mIsOver;


		ModalFlags();

		void ModFlags(const FlagsMod& theFlagsMod);
		int	GetFlags();

	};

	//

	class AutoModalFlags
	{
	public:

		ModalFlags* mModalFlags;
		int	mOldOverFlags;
		int	mOldUnderFlags;


		AutoModalFlags(ModalFlags* theModalFlags, const FlagsMod& theFlagMod);
		~AutoModalFlags();

	};

} // Sexy

#endif // __Flags__