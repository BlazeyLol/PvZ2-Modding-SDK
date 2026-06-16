//
// DialogListener.h
//

#ifndef __DialogListener__
#define __DialogListener__


namespace Sexy
{

	class DialogListener
	{
	public:

		virtual ~DialogListener() {}
		virtual void DialogButtonPress(int theDialogId, int theButtonId) {}
		virtual void DialogButtonDepress(int theDialogId, int theButtonId) {}

	};

} // Sexy

#endif // __DialogListener__