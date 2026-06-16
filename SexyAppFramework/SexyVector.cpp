//
// SexyVector.cpp
//

#include "SexyVector.h"
#include <cmath>

//

Sexy::SexyVector2::SexyVector2() :
    x(0),
    y(0)
{}

Sexy::SexyVector2::SexyVector2(int theX, int theY) :
    x(theX),
    y(theY)
{}


float Sexy::SexyVector2::Dot(const SexyVector2& v) const
{
    return x * v.x + y * v.y;
}

float Sexy::SexyVector2::Magnitude() const
{
    return sqrtf(x * x + y * y);
}

float Sexy::SexyVector2::MagnitudeSquared() const
{
    return x * x + y * y;
}

Sexy::SexyVector2 Sexy::SexyVector2::Normalize() const
{
    float aMag = Magnitude();
    return aMag != 0 ? (*this) / aMag : *this;
}

Sexy::SexyVector2 Sexy::SexyVector2::Perp() const
{
    return SexyVector2(-y, x);
}


Sexy::SexyVector2 Sexy::SexyVector2::operator+(const SexyVector2& v) const
{
    return SexyVector2(x + v.x, y + v.y);
}

Sexy::SexyVector2 Sexy::SexyVector2::operator-(const SexyVector2& v) const
{
    return SexyVector2(x - v.x, y - v.y);
}

Sexy::SexyVector2 Sexy::SexyVector2::operator-() const
{
    return SexyVector2(-x, -y);
}

Sexy::SexyVector2 Sexy::SexyVector2::operator*(float t) const
{
    return SexyVector2(x * t, y * t);
}

Sexy::SexyVector2 Sexy::SexyVector2::operator/(float t) const
{
    return SexyVector2(x / t, y / t);
}

Sexy::SexyVector2 Sexy::SexyVector2::operator+=(const SexyVector2& v)
{
    return SexyVector2(x += v.x, y += v.y);
}

Sexy::SexyVector2 Sexy::SexyVector2::operator-=(const SexyVector2& v)
{
    return SexyVector2(x -= v.x, y -= v.y);
}

Sexy::SexyVector2 Sexy::SexyVector2::operator*=(float t)
{
    return SexyVector2(x *= t, y *= t);
}

Sexy::SexyVector2 Sexy::SexyVector2::operator/=(float t)
{
    return SexyVector2(x /= t, y /= t);
}

bool Sexy::SexyVector2::operator==(const SexyVector2& v) const
{
    return x == v.x && y == v.y;
}
bool Sexy::SexyVector2::operator!=(const SexyVector2& v) const
{
    return x != v.x || y != v.y;
}

//

Sexy::SexyVector3::SexyVector3() :
    x(0),
    y(0),
    z(0)
{}

Sexy::SexyVector3::SexyVector3(int theX, int theY, int theZ) :
    x(theX),
    y(theY),
    z(theZ)
{}


float Sexy::SexyVector3::Dot(const SexyVector3& v) const
{
    return x * v.x + y * v.y + z * v.z;
}

float Sexy::SexyVector3::Magnitude() const
{
    return std::sqrtf(x * x + y * y + z * z);
}

float Sexy::SexyVector3::MagnitudeSquared() const
{
    return x * x + y * y + z * z;
}

Sexy::SexyVector3 Sexy::SexyVector3::Normalize() const
{
    float aMag = Magnitude();
    return aMag != 0 ? (*this) / aMag : *this;
}

Sexy::SexyVector3 Sexy::SexyVector3::Cross(const SexyVector3& v) const
{
    return SexyVector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}


Sexy::SexyVector3 Sexy::SexyVector3::operator+(const SexyVector3& v) const
{
    return SexyVector3(x + v.x, y + v.y, z + v.z);
}

Sexy::SexyVector3 Sexy::SexyVector3::operator-(const SexyVector3& v) const
{
    return SexyVector3(x - v.x, y - v.y, z - v.z);
}

Sexy::SexyVector3 Sexy::SexyVector3::operator-() const
{
    return SexyVector3(-x, -y, -z);
}

Sexy::SexyVector3 Sexy::SexyVector3::operator*(float t) const
{
    return SexyVector3(x * t, y * t, z * t);
}

Sexy::SexyVector3 Sexy::SexyVector3::operator/(float t) const
{
    return SexyVector3(x / t, y / t, z / t);
}

Sexy::SexyVector3 Sexy::SexyVector3::operator+=(const SexyVector3& v)
{
    return SexyVector3(x += v.x, y += v.y, z += v.z);
}

Sexy::SexyVector3 Sexy::SexyVector3::operator-=(const SexyVector3& v)
{
    return SexyVector3(x -= v.x, y -= v.y, z -= v.z);
}

Sexy::SexyVector3 Sexy::SexyVector3::operator*=(float t)
{
    return SexyVector3(x *= t, y *= t, y *= t);
}

Sexy::SexyVector3 Sexy::SexyVector3::operator/=(float t)
{
    return SexyVector3(x /= t, y /= t, z /= t);
}

bool Sexy::SexyVector3::operator==(const SexyVector3& v) const
{
    return x == v.x && y == v.y;
}
bool Sexy::SexyVector3::operator!=(const SexyVector3& v) const
{
    return x != v.x || y != v.y;
}