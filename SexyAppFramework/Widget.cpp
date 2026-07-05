//
// Widget.cpp
//

#include "Widget.h"
#include "WidgetManager.h"

//

RT_CLASS_IMPLEMENT(Widget);
void Sexy::Widget::StaticClassInit()
{

}

Sexy::Widget::Widget()
{

}

Sexy::Widget::~Widget()
{

}


void Sexy::Widget::WidgetRemovedHelper()
{

}


void Sexy::Widget::OrderInManagerChanged()
{}

void Sexy::Widget::Function43()
{}

void Sexy::Widget::Function44()
{}

void Sexy::Widget::Function45()
{}

void Sexy::Widget::Function46()
{}

void Sexy::Widget::Function47()
{}

void Sexy::Widget::Function48()
{}

void Sexy::Widget::Function49()
{}

void Sexy::Widget::SetDisabled(bool isDisabled)
{
	if (mDisabled == isDisabled)
		return;

	mDisabled = isDisabled;

	MarkDirty();

	if (isDisabled && mWidgetManager)
		mWidgetManager->DisableWidget(this);
	else if (mWidgetManager)
		mWidgetManager->DisableAllWidgets(this);
}

void Sexy::Widget::Function51()
{}

void Sexy::Widget::Function52()
{}

void Sexy::Widget::Function53()
{}

void Sexy::Widget::Function54()
{}

void Sexy::Widget::Function55()
{}

void Sexy::Widget::Function56()
{}

void Sexy::Widget::Function57()
{}

void Sexy::Widget::Function58()
{}

void Sexy::Widget::Function59()
{}

void Sexy::Widget::Function60()
{}

void Sexy::Widget::Function61()
{}

void Sexy::Widget::Function62()
{}

void Sexy::Widget::Function63()
{}

void Sexy::Widget::Function64()
{}

void Sexy::Widget::Function65()
{}

void Sexy::Widget::Function66()
{}

void Sexy::Widget::Function67()
{}

void Sexy::Widget::Function68()
{}

void Sexy::Widget::Function69()
{}

void Sexy::Widget::Function70()
{}

void Sexy::Widget::Function71()
{}

void Sexy::Widget::Function72()
{}

void Sexy::Widget::Function73()
{}

void Sexy::Widget::Function74()
{}

bool Sexy::Widget::IsPointVisible(int x, int y)
{
	return true;
}

void Sexy::Widget::Function76()
{}

void Sexy::Widget::Function77()
{}

void Sexy::Widget::Function78()
{}

void Sexy::Widget::Function79()
{}

void Sexy::Widget::Function80()
{}

void Sexy::Widget::Function81()
{}

void Sexy::Widget::Function82()
{}

void Sexy::Widget::Function83()
{}

void Sexy::Widget::Function84()
{}

void Sexy::Widget::Function85()
{}

void Sexy::Widget::Function86()
{}

void Sexy::Widget::Function87()
{}

void Sexy::Widget::Function88()
{}

void Sexy::Widget::Function89()
{}

bool Sexy::Widget::Contains(int theX, int theY)
{
	return ((theX >= mX) && (theX < mX + mWidth) &&
			(theY >= mY) && (theY < mY + mHeight));
}

Sexy::Rect Sexy::Widget::GetInsetRect()
{
	return Rect(mX + mMouseInsets.mLeft, mY + mMouseInsets.mTop,
						 mWidth - mMouseInsets.mLeft - mMouseInsets.mRight,
						 mHeight - mMouseInsets.mTop - mMouseInsets.mBottom);
}