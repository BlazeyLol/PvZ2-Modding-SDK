//
// Insets.h
//

#ifndef __Insets__
#define __Insets__


namespace Sexy
{

	class Insets
	{
	public:

		int	mLeft;
		int	mTop;
		int	mRight;
		int	mBottom;


		Insets();
		Insets(int theLeft, int theTop, int theRight, int theBottom);
		Insets(const Insets& theInsets);

	};

} // Sexy

#endif // __Insets__