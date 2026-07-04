//
// Image.h
//

#ifndef __Image__
#define __Image__

#include "BaseResource.h"
#include "Rect.h"

//

namespace Sexy
{

	struct Span
	{
		int	mY;
		int	mX;
		int	mWidth;
	};

	//

	class Image : public BaseResource
	{
	public:
		RT_CLASS_DEFINE(Image, BaseResource, ResourceClass);

		int mImageFlags;
		void* mRenderData;
		bool mDrawn;
		std::string mFilePath;
		int mWidth;
		int mHeight;

		// for image strips
		int mNumRows;
		int mNumCols;

		RtWeakPtr<Image> mAtlasImage;
		int mAtlasStartX;
		int mAtlasStartY;
		int mAtlasEndX;
		int mAtlasEndY;


		Image();
		virtual ~Image() override;

		int GetWidth() const;
		int GetHeight() const;
		int	GetCelWidth() const; // returns the width of just 1 cel in a strip of images
		int	GetCelHeight() const;	// like above but for vertical strips
		Rect GetCelRect(int theCel) const; // Gets the rectangle for the given cel at the specified row/col 
		Rect GetCelRect(int theCol, int theRow) const; // Same as above, but for an image with both multiple rows and cols
		int	GetAnimCel(int theTime);
		Rect GetAnimCelRect(int theTime);

		virtual bool Function7();
		virtual bool Function8();

	};

} // Sexy

#endif // __Image__