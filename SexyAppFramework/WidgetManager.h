//
// WidgetManager.h
//

#ifndef __WidgetManager__
#define __WidgetManager__

#include "WidgetContainer.h"

//

namespace Sexy
{

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

	class WidgetManager : public WidgetContainer
	{
	public:

		int field20;
		int field21;
		SexyAppBase* mApp;
		int field23;
		int field24;
		int field25;
		Widget* mPopupCommandWidget;
		int field27;
		int field28;
		int field29;
		int mMinDeferredOverlayPriority;
		int field31;
		int field32;
		int field33;
		int field34;
		Widget* mBaseModalWidget;
		int field36;
		int field37;
		int field38;
		int field39;
		int field40;
		int field41;
		int field42;
		int field43;
		int field44;
		int field45;
		int field46;
		int field47;
		int field48;
		int field49;
		int field50;
		int field51;
		int field52;
		int field53;
		int field54;
		int field55;
		int field56;
		int field57;
		int field58;
		int field59;
		bool mKeyDown[0xFF];
		int field124;
		int field125;
		int mWidgetFlags;


		WidgetManager(SexyAppBase* theApp);
		virtual ~WidgetManager() override;

		void RehupMouse();

	};

} // Sexy

#endif // __WidgetManager__