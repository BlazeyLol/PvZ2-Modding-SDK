//
// ButtonListener.h
//

#ifndef __ButtonListener__
#define __ButtonListener__


namespace Sexy
{

	class ButtonListener
	{
	public:

		virtual ~ButtonListener() {}
		virtual void ButtonPress(int theId) {}
		virtual void ButtonPress(int theId, int theClickCount) { ButtonPress(theId); }
		virtual void ButtonDepress(int theId) {}
		virtual void ButtonDownTick(int theId) {}
		virtual void ButtonMouseEnter(int theId) {}
		virtual void ButtonMouseLeave(int theId) {}
		virtual void ButtonMouseMove(int theId, int theX, int theY) {}

	};

} // Sexy

#endif // __ButtonListener__