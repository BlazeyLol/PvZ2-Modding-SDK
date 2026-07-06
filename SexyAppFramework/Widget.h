//
// Widget.h
//

#ifndef __Widget__
#define __Widget__

#include "WidgetContainer.h"
#include "Insets.h"

//

namespace Sexy
{

	class Widget : public WidgetContainer
	{
	public:
		RT_CLASS_DEFINE(Widget, WidgetContainer, RtClass);

		bool mVisible;
		bool mMouseVisible;
		bool mHasFocus;
		bool mIsDown;
		bool boolean8;
		bool mHasTransparencies;
		bool boolean9;
		bool boolean10;
		int field22;
		int field23;
		int field24;
		Insets mMouseInsets;
		int field29;
		int field30;
		int field31;
		bool mDisabled;


		Widget();
		virtual ~Widget() override;

		void WidgetRemovedHelper();

		virtual void OrderInManagerChanged();
		virtual void Function43();
		virtual void Function44();
		virtual void Function45();
		virtual void Function46();
		virtual void Function47();
		virtual void Function48();
		virtual void Function49();
		virtual void SetDisabled(bool isDisabled);
		virtual void Function51();
		virtual void Function52();
		virtual void Function53();
		virtual void Function54();
		virtual void Function55();
		virtual void Function56();
		virtual void DrawOverlay(Graphics* g);
		virtual void DrawOverlay(Graphics* g, int thePriority);
		virtual void GotFocus();
		virtual void LostFocus();
		virtual void Function61();
		virtual void Function62();
		virtual void Function63();
		virtual void Function64();
		virtual void MouseEnter();
		virtual void MouseLeave();
		virtual void MouseLeave(int x, int y);
		virtual void Function68();
		virtual void Function69();
		virtual void MouseUp(int x, int y);
		virtual void MouseUp(int x, int y, int theClickCount);
		virtual void MouseUp(int x, int y, int theBtnNum, int theClickCount);
		virtual void Function73();
		virtual void Function74();
		virtual bool IsPointVisible(int x, int y);
		virtual void Function76();
		virtual void Function77();
		virtual void Function78();
		virtual void Function79();
		virtual void Function80();
		virtual void Function81();
		virtual void Function82();
		virtual void Function83();
		virtual void Function84();
		virtual void Function85();
		virtual void Function86();
		virtual void Function87();
		virtual void Function88();
		virtual void Function89();
		virtual bool Contains(int theX, int theY);
		virtual Rect GetInsetRect();

	};

} // Sexy

#endif // __Widget__