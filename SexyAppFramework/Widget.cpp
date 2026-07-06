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
	field22 = 0;
	field23 = 0;
	field24 = 0;
	mWidgetManager = nullptr;
	mVisible = true;
	mMouseVisible = true;
	boolean8 = 0;
	field29 = 0;
	field30 = 0;
	field31 = 0xFFFFFFFF;
	mDisabled = 0;
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

void Sexy::Widget::DrawOverlay(Graphics* g)
{}

void Sexy::Widget::DrawOverlay(Graphics* g, int thePriority)
{
	DrawOverlay(g);
}

void Sexy::Widget::GotFocus()
{
	mHasFocus = true;
}

void Sexy::Widget::LostFocus()
{
	mHasFocus = false;
}

void Sexy::Widget::Function61()
{}

void Sexy::Widget::Function62()
{}

void Sexy::Widget::Function63()
{}

void Sexy::Widget::Function64()
{}

void Sexy::Widget::MouseEnter()
{

}

void Sexy::Widget::MouseLeave()
{}

void Sexy::Widget::MouseLeave(int x, int y)
{

}

void Sexy::Widget::Function68()
{}

void Sexy::Widget::Function69()
{}

void Sexy::Widget::MouseUp(int x, int y)
{}

void Sexy::Widget::MouseUp(int x, int y, int theLastDownButtonId)
{
	MouseUp(x, y);

	if (theLastDownButtonId == 3)
		MouseUp(x, y, 2, 1);
	else if (theLastDownButtonId >= 0)
		MouseUp(x, y, 0, theLastDownButtonId);
	else
		MouseUp(x, y, 1, -theLastDownButtonId);
}

void Sexy::Widget::MouseUp(int x, int y, int theBtnNum, int theClickCount)
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