//
// SexyVector.h
//

#ifndef __SexyVector__
#define __SexyVector__


namespace Sexy
{

    class SexyVector2
    {
    public:

        float x;
        float y;


        SexyVector2();
        SexyVector2(int theX, int theY);

        float Dot(const SexyVector2& v) const;
        float Magnitude() const;
        float MagnitudeSquared() const;
        SexyVector2 Normalize() const;
        SexyVector2 Perp() const;

        SexyVector2 operator+(const SexyVector2& v) const;
        SexyVector2 operator-(const SexyVector2& v) const;
        SexyVector2 operator-() const;
        SexyVector2 operator*(float t) const;
        SexyVector2 operator/(float t) const;
        SexyVector2 operator+=(const SexyVector2& v);
        SexyVector2 operator-=(const SexyVector2& v);
        SexyVector2 operator*=(float t);
        SexyVector2 operator/=(float t);
        bool operator==(const SexyVector2& v) const;
        bool operator!=(const SexyVector2& v) const;

    };

    //

    class SexyVector3
    {
    public:

        float x;
        float y;
        float z;


        SexyVector3();
        SexyVector3(int theX, int theY, int theZ);

        float Dot(const SexyVector3& v) const;
        float Magnitude() const;
        float MagnitudeSquared() const;
        SexyVector3 Normalize() const;
        SexyVector3 Cross(const SexyVector3& v) const;

        SexyVector3 operator+(const SexyVector3& v) const;
        SexyVector3 operator-(const SexyVector3& v) const;
        SexyVector3 operator-() const;
        SexyVector3 operator*(float t) const;
        SexyVector3 operator/(float t) const;
        SexyVector3 operator+=(const SexyVector3& v);
        SexyVector3 operator-=(const SexyVector3& v);
        SexyVector3 operator*=(float t);
        SexyVector3 operator/=(float t);
        bool operator==(const SexyVector3& v) const;
        bool operator!=(const SexyVector3& v) const;

    };

} // Sexy

#endif // __SexyVector__