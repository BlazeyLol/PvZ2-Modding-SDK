//
// Image.cpp
//

#include "Image.h"
#include "SexyAppBase.h"
#include "ResourceManager.h"

//

RT_CLASS_IMPLEMENT(Sexy::Image);
void Sexy::Image::StaticClassInit()
{
	CallFunc<void>(0x110E610);
}


Sexy::Image::Image()
{
	mImageFlags = 0;
	mRenderData = nullptr;
	mWidth = 0;
	mHeight = 0;
	mAtlasEndX = 0;
	mAtlasEndY = 0;
	mNumRows = 0;
	mNumCols = 0;
	mDrawn = false;
}

Sexy::Image::~Image()
{
	if ((mImageFlags & 0x400) != 0)
	{
		if (gSexyAppBase && gSexyAppBase->mResourceManager)
		{
			gSexyAppBase->mResourceManager->RemoveUngroupedSharedImage(this);
		}
	}
}


int Sexy::Image::GetWidth() const
{
	return mWidth;
}

int Sexy::Image::GetHeight() const
{
	return mHeight;
}


bool Sexy::Image::Function7()
{}

bool Sexy::Image::Function8()
{}