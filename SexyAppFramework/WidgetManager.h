//
// WidgetManager.h
//

#ifndef __WidgetManager__
#define __WidgetManager__

#include "WidgetContainer.h"
#include "Flags.h"
#include "MemoryImage.h"

//

namespace Sexy
{

	class Graphics;
	class SexyAppBase;

	//

	enum
	{
		WIDGETFLAGS_UPDATE = 1,
		WIDGETFLAGS_MARK_DIRTY = 2,
		WIDGETFLAGS_DRAW = 4,
		WIDGETFLAGS_CLIP = 8,
		WIDGETFLAGS_ALLOW_MOUSE = 16,
		WIDGETFLAGS_ALLOW_FOCUS = 32,
	};

	//

	using DeferredOverlayVector = std::vector<std::pair<Widget*, int> >;

	class WidgetManager : public WidgetContainer
	{
	public:

		int field20;
		Graphics* mCurG;
		SexyAppBase* mApp;
		MemoryImage* mImage;
		int field24;
		int field25;
		Widget* mPopupCommandWidget;
		DeferredOverlayVector mDeferredOverlayWidgets;
		int mMinDeferredOverlayPriority;
		int field31;
		Widget* mFocusWidget;
		Widget* mLastDownWidget;
		Widget* mOverWidget;
		Widget* mBaseModalWidget;
		int field36;
		FlagsMod mLostFocusFlagsMod;
		FlagsMod mBelowModalFlagsMod;
		int field41;
		int field42;
		int field43;
		int field44;
		int field45;
		Rect mMouseDestRect;
		int field50;
		int field51;
		int field52;
		int field53;
		int field54;
		int mLastMouseX;
		int mLastMouseY;
		int mDownButtons;
		int field58;
		int field59;
		bool mKeyDown[0xFF];
		int field124;
		int field125;
		int mWidgetFlags;


		WidgetManager(SexyAppBase* theApp);
		virtual ~WidgetManager() override;

		void RehupMouse();
		void FlushDeferredOverlayWidgets(int theMaxPriority);

	};

} // Sexy

#endif // __WidgetManager__