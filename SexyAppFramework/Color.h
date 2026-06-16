//
// Color.h
//

#ifndef __Color__
#define __Color__

namespace Sexy
{

	class Color
	{
	public:

		int mRed = 0;
		int mGreen = 0;
		int mBlue = 0;
		int mAlpha = 255;


		static Color Black;
		static Color White;

		Color();
		Color(int theRed, int theGreen, int theBlue);
		Color(int theRed, int theGreen, int theBlue, int theAlpha);

		int	GetRed() const;
		int	GetGreen() const;
		int	GetBlue() const;
		int	GetAlpha() const;
		unsigned long ToInt() const;

		bool operator==(const Color& other) const;
		bool operator!=(const Color& other) const;

	};

} // Sexy

#endif // __Color__