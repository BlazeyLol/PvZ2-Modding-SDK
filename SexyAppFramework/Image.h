//
// Image.h
//

#ifndef __Image__
#define __Image__

#include "BaseResource.h"

//

namespace Sexy
{

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

		virtual bool Function7();
		virtual bool Function8();

	};

} // Sexy

#endif // __Image__