//
// Font.cpp
//

#include "Font.h"

//

Sexy::RtClass* Sexy::Font::s_rtClass = nullptr;

Sexy::ResourceClass* Sexy::Font::StaticGetType()
{
	if (!s_rtClass)
	{
		auto* rtClass = new ResourceClass();
		s_rtClass = rtClass;
		auto* ancestorClass = RtObject::StaticGetType();
		rtClass->RegisterClass("BaseResource", ancestorClass, reinterpret_cast<Sexy::RtClassConstruct>(Construct));
		rtClass->m_resInfoType = CallFunc<void*>(0x12569E8);
	}
	
	return reinterpret_cast<ResourceClass*>(s_rtClass);
}

Sexy::BaseResource* Sexy::Font::Construct()
{
	return nullptr;
}

Sexy::ResourceClass* Sexy::Font::GetType() const
{
	return StaticGetType();
}

bool Sexy::Font::Function1() const
{
	return 1;
}


Sexy::Font::Font()
{
	mAscent = 0;
	mHeight = 0;
	mAscentPadding = 0;
	mLineSpacingOffset = 0;
}

Sexy::Font::~Font()
{
}


int Sexy::Font::Function7()
{
	return 0;
}

int Sexy::Font::GetAscent() const
{
	return mAscent;
}

int Sexy::Font::GetAscentPadding() const
{
	return mAscentPadding;
}

int Sexy::Font::GetDescent() const
{
	return mHeight - mAscent;
}

int Sexy::Font::GetHeight() const
{
	return mHeight;
}

int Sexy::Font::GetLineSpacingOffset() const
{
	return mLineSpacingOffset;
}

int Sexy::Font::GetLineSpacing() const
{
	return mHeight + mLineSpacingOffset;
}

int Sexy::Font::StringWidth(const std::string& theString) const
{
	return 0;
}

int Sexy::Font::CharWidth(char theChar) const
{
	SexyString aString(1, theChar);
	return StringWidth(aString);
}

int Sexy::Font::CharWidthKern(char theChar, char thePrevChar) const
{
	return CharWidth(theChar);
}

void Sexy::Font::DrawString(Graphics* g, int theX, int theY, const std::string& theString, const Color& theColor, const Rect& theClipRect)
{}