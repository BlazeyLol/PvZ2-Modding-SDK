//
// WidgetContainer.h
//

#ifndef __WidgetContainer__
#define __WidgetContainer__

#include "GameCommon.h"
#include "RtObject.h"
#include "RtClass.h"
#include "Rect.h"
#include "Flags.h"

//

namespace Sexy
{

	class Widget;
	class WidgetManager;
	class Graphics;

	//

	using WidgetList = std::list<Widget*>;

	class WidgetContainer : public RtObject
	{
	public:
		RT_CLASS_DEFINE(WidgetContainer, RtObject, RtClass);

		WidgetList mWidgets;
		WidgetManager* mWidgetManager;
		WidgetContainer* mParent;
		WidgetList::iterator mUpdateIterator;
		int mLastWMUpdateCount;
		int mUpdateCnt;
		int mX;
		int mY;
		int mWidth;
		int mHeight;
		FlagsMod mWidgetFlagsMod;
		int mPriority;
		int mZOrder;
		bool mHasAlpha;
		bool mClip;
		bool mClearClip;
		bool mDirty;
		bool mUpdateIteratorModified;
		bool boolean6;
		bool boolean7;
		int field19;


		WidgetContainer();
		virtual ~WidgetContainer() override;

		bool IsBelowHelper(Widget* theWidget1, Widget* theWidget2, bool* found);
		void InsertWidgetHelper(const WidgetList::iterator& where, Widget* theWidget);

		virtual int Function7();
		virtual Rect GetRect();
		virtual Rect GetClipRect();
		virtual bool Intersects(WidgetContainer* theWidget);
		virtual void AddWidget(Widget* theWidget);
		virtual void RemoveWidget(Widget* theWidget);
		virtual bool HasWidget(Widget* theWidget);
		virtual void DisableWidget(Widget* theWidget);
		virtual void Function15();
		virtual void RemoveAllWidgets(bool doDelete, bool recursive);
		virtual void DisableAllWidgets(Widget* theWidget);
		virtual void Function18();
		virtual void Function19();
		virtual bool IsBelow(Widget* theWidget1, Widget* theWidget2);
		virtual void MarkAllDirty();
		virtual void BringToFront(Widget* theWidget);
		virtual void BringToBack(Widget* theWidget);
		virtual void PutBehind(Widget* theWidget, Widget* theRefWidget);
		virtual void PutInfront(Widget* theWidget, Widget* theRefWidget);
		virtual Point GetAbsPos();
		virtual void MarkDirty();
		virtual void MarkDirtyFull();
		virtual void MarkDirtyFull(WidgetContainer* theWidget);
		virtual void MarkDirty(WidgetContainer* theWidget);
		virtual void AddedToManager(WidgetManager* theWidgetManager);
		virtual void RemovedFromManager(WidgetManager* theWidgetManager);
		virtual void Update();
		virtual void UpdateAll(ModalFlags* theFlags);
		virtual void UpdateF(float theFrac);
		virtual void UpdateFAll(ModalFlags* theFlags, float theFrac);
		virtual void Draw(Graphics* g);
		virtual void DrawAll(ModalFlags* theFlags, Graphics* g);
		virtual void SysColorChangedAll();
		virtual void SysColorChanged();
		virtual void Function41();
		virtual void Function42();

	};

} // Sexy

#endif // __WidgetContainer__