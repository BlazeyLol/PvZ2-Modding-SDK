//
// Point.h
//

#ifndef __Point__
#define __Point__


namespace Sexy
{

	template<typename T>
	class TPoint
	{
	public:

		T mX;
		T mY;


		TPoint() :
			mX(0),
			mY(0)
		{}

		TPoint(int theX, int theY) :
			mX(theX),
			mY(theY)
		{}

		TPoint(const TPoint<T>& theTPoint) :
			mX(theTPoint.mX),
			mY(theTPoint.mY)
		{}


		TPoint operator+(const TPoint& p) const
		{
			return TPoint(mX + p.mX, mY + p.mY);
		}

		TPoint operator-(const TPoint& p) const
		{
			return TPoint(mX - p.mX, mY - p.mY);
		}

		TPoint operator*(const TPoint& p) const
		{
			return TPoint(mX * p.mX, mY * p.mY);
		}

		TPoint operator/(const TPoint& p) const
		{
			return TPoint(mX / p.mX, mY / p.mY);
		}

		TPoint& operator+=(const TPoint& p)
		{
			mX += p.mX; mY += p.mY; return *this;
		}

		TPoint& operator-=(const TPoint& p)
		{
			mX -= p.mX; mY -= p.mY; return *this;
		}

		TPoint& operator*=(const TPoint& p)
		{
			mX *= p.mX; mY *= p.mY; return *this;
		}

		TPoint& operator/=(const TPoint& p)
		{
			mX /= p.mX; mY /= p.mY; return *this;
		}

		TPoint operator*(T s) const
		{
			return TPoint(mX * s, mY * s);
		}

		TPoint operator/(T s) const
		{
			return TPoint(mX / s, mY / s);
		}

		inline bool operator==(const TPoint& p)
		{
			return ((p.mX == mX) && (p.mY == mY));
		}

		inline bool operator!=(const TPoint& p)
		{
			return ((p.mX != mX) || (p.mY != mY));
		}

	};

	using Point = TPoint<int>;
	using FPoint = TPoint<float>;

} // Sexy

#endif // __Point__