//
// Font.h
//

#ifndef __Font__
#define __Font__

#include "BaseResource.h"
#include "Rect.h"
#include "Color.h"

//

namespace Sexy
{

	class Graphics;

	class Font : public BaseResource
	{
	public:

		int	mAscent;
		int mAscentPadding; // How much space is above the avg uppercase char
		int	mHeight;
		int	mLineSpacingOffset; // This plus height should get added between lines


		static RtClass* s_rtClass;
		static ResourceClass* StaticGetType();
		static BaseResource* Construct();
		virtual ResourceClass* GetType() const override;
		virtual bool Function1() const override;

		Font();
		virtual ~Font() override;

		virtual int Function7();
		virtual int GetAscent() const;
		virtual int GetAscentPadding() const;
		virtual int GetDescent() const;
		virtual int GetHeight() const;
		virtual int GetLineSpacingOffset() const;
		virtual int GetLineSpacing() const;
		virtual int StringWidth(const std::string& theString) const;
		virtual int CharWidth(char theChar) const;
		virtual int CharWidthKern(char theChar, char thePrevChar) const;
		virtual void DrawString(Graphics* g, int theX, int theY, const std::string& theString, const Color& theColor, const Rect& theClipRect);
		virtual Font* Duplicate() = 0;

	};

} // Sexy

#endif // __Font__