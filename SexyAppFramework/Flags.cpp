//
// Flags.cpp
//

#include "Flags.h"

//

Sexy::FlagsMod::FlagsMod()
{
	mAddFlags = 0;
	mRemoveFlags = 0;
}

//

void Sexy::ModFlags(int& theFlags, const FlagsMod& theFlagMod)
{
	theFlags = (theFlags | theFlagMod.mAddFlags) & ~theFlagMod.mRemoveFlags;
}

int Sexy::GetModFlags(int theFlags, const FlagsMod& theFlagMod)
{
	return (theFlags | theFlagMod.mAddFlags) & ~theFlagMod.mRemoveFlags;
}

//

Sexy::ModalFlags::ModalFlags()
{
	mOverFlags = 0;
	mUnderFlags = 0;
	mIsOver = false;
}


void Sexy::ModalFlags::ModFlags(const FlagsMod& theFlagsMod)
{
	Sexy::ModFlags(mOverFlags, theFlagsMod);
	Sexy::ModFlags(mUnderFlags, theFlagsMod);
}

int	Sexy::ModalFlags::GetFlags()
{
	return mIsOver ? mOverFlags : mUnderFlags;
}

//

Sexy::AutoModalFlags::AutoModalFlags(ModalFlags* theModalFlags, const FlagsMod& theFlagMod)
{
	mModalFlags = theModalFlags;
	mOldOverFlags = theModalFlags->mOverFlags;
	mOldUnderFlags = theModalFlags->mUnderFlags;
	theModalFlags->ModFlags(theFlagMod);
}

Sexy::AutoModalFlags::~AutoModalFlags()
{
	mModalFlags->mOverFlags = mOldOverFlags;
	mModalFlags->mUnderFlags = mOldUnderFlags;
}