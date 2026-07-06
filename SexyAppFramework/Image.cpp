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
	mAtlasStartX = 0;
	mAtlasStartY = 0;
	mAtlasEndX = 0;
	mAtlasEndY = 0;
	mNumRows = 1;
	mNumCols = 1;
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

int Sexy::Image::GetCelHeight() const
{
	return mHeight / mNumRows;
}

int Sexy::Image::GetCelWidth() const
{
	return mWidth / mNumCols;
}

Sexy::Rect Sexy::Image::GetCelRect(int theCel) const
{
	int h = GetCelHeight();
	int w = GetCelWidth();
	int x = (theCel % mNumCols) * w;
	int y = (theCel / mNumCols) * h;

	return Rect(x, y, w, h);
}

Sexy::Rect Sexy::Image::GetCelRect(int theCol, int theRow) const
{
	int h = GetCelHeight();
	int w = GetCelWidth();
	int x = theCol * w;
	int y = theRow * h;

	return Rect(x, y, w, h);
}

int	Sexy::Image::GetAnimCel(int theTime)
{
	if (theTime) {
		return 0;
	}
	
	// This is most likely Sexy::Image::GetCel
	return CallFunc<int, Image*, int>(0x16FD698, this, theTime);
}

Sexy::Rect Sexy::Image::GetAnimCelRect(int theTime)
{
	int aCel = GetAnimCel(theTime);
	int aCelWidth = GetCelWidth();
	int aCelHeight = GetCelHeight();

	if (mNumCols > 1) {
		return Rect(aCel * aCelWidth, 0, aCelWidth, mHeight);
	}

	return Rect(0, aCel * aCelHeight, mWidth, aCelHeight);
}


bool Sexy::Image::Function7()
{}

bool Sexy::Image::Function8()
{}