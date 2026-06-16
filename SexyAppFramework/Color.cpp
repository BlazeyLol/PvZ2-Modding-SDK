//
// Color.cpp
//

#include "Color.h"

//

Sexy::Color Sexy::Color::Black(0, 0, 0);
Sexy::Color Sexy::Color::White(255, 255, 255);


Sexy::Color::Color() :
	mRed(0),
	mGreen(0),
	mBlue(0),
	mAlpha(255)
{}

Sexy::Color::Color(int theRed, int theGreen, int theBlue) :
	mRed(theRed),
	mGreen(theGreen),
	mBlue(theBlue),
	mAlpha(255)
{}

Sexy::Color::Color(int theRed, int theGreen, int theBlue, int theAlpha) :
	mRed(theRed),
	mGreen(theGreen),
	mBlue(theBlue),
	mAlpha(theAlpha)
{}


int Sexy::Color::GetRed() const
{
	return mRed;
}

int Sexy::Color::GetGreen() const
{
	return mGreen;
}

int Sexy::Color::GetBlue() const
{
	return mBlue;
}

int Sexy::Color::GetAlpha() const
{
	return mAlpha;
}

unsigned long Sexy::Color::ToInt() const
{
	return (mAlpha << 24) | (mRed << 16) | (mGreen << 8) | (mBlue);
}


bool Sexy::Color::operator==(const Color& other) const
{
	return
		(mRed == other.mRed) &&
		(mGreen == other.mGreen) &&
		(mBlue == other.mBlue) &&
		(mAlpha == other.mAlpha);
}

bool Sexy::Color::operator!=(const Color& other) const
{
	return
		(mRed != other.mRed) ||
		(mGreen != other.mGreen) ||
		(mBlue != other.mBlue) ||
		(mAlpha != other.mAlpha);
}