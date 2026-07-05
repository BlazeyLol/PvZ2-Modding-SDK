//
// Insets.cpp
//

#include "Insets.h"

//

Sexy::Insets::Insets() :
	mLeft(0),
	mTop(0),
	mRight(0),
	mBottom(0)
{}

Sexy::Insets::Insets(int theLeft, int theTop, int theRight, int theBottom) :
	mLeft(theLeft),
	mTop(theTop),
	mRight(theRight),
	mBottom(theBottom)
{}

Sexy::Insets::Insets(const Insets& theInsets) :
	mLeft(theInsets.mLeft),
	mTop(theInsets.mTop),
	mRight(theInsets.mRight),
	mBottom(theInsets.mBottom)
{}