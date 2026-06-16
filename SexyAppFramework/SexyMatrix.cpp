//
// SexyMatrix.cpp
//

#include "SexyMatrix.h"
#include <cmath>

//

Sexy::SexyMatrix3::SexyMatrix3()
{}


void Sexy::SexyMatrix3::ZeroMatrix()
{
	m00 = m01 = m02 =
		m10 = m11 = m12 =
		m20 = m21 = m22 = 0;
}

void Sexy::SexyMatrix3::LoadIdentity()
{
	m01 = m02 = m10 = m12 = m20 = m21 = 0;
	m00 = m11 = m22 = 1;
}


Sexy::SexyMatrix3 Sexy::SexyMatrix3::operator*(const SexyMatrix3& theMat) const
{
	SexyMatrix3 aResult;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			float x = 0;
			for (int k = 0; k < 3; k++)
				x += m[i][k] * theMat.m[k][j];

			aResult.m[i][j] = x;
		}
	}

	return aResult;
}

Sexy::SexyVector2 Sexy::SexyMatrix3::operator*(const SexyVector2& theVec) const
{
	return SexyVector2(
		m00 * theVec.x + m01 * theVec.y + m02,
		m10 * theVec.x + m11 * theVec.y + m12);
}

Sexy::SexyVector3 Sexy::SexyMatrix3::operator*(const SexyVector3& theVec) const
{
	return SexyVector3(
		m00 * theVec.x + m01 * theVec.y + m02 * theVec.z,
		m10 * theVec.x + m11 * theVec.y + m12 * theVec.z,
		m20 * theVec.x + m21 * theVec.y + m22 * theVec.z);
}

const Sexy::SexyMatrix3& Sexy::SexyMatrix3::operator*=(const SexyMatrix3& theMat)
{
	return operator=(operator*(theMat));
}

//

Sexy::SexyTransform2D::SexyTransform2D()
{
	LoadIdentity();
}

Sexy::SexyTransform2D::SexyTransform2D(bool loadIdentity)
{
	if (loadIdentity)
		LoadIdentity();
}


void Sexy::SexyTransform2D::Translate(float tx, float ty)
{
	SexyMatrix3 aMat;
	aMat.LoadIdentity();
	aMat.m02 = tx;
	aMat.m12 = ty;
	aMat.m22 = 1;

	*this = aMat * (*this);
}

void Sexy::SexyTransform2D::RotateRad(float rot)
{
	SexyMatrix3 aMat;
	aMat.LoadIdentity();

	float sinRot = -std::sinf(rot);
	float cosRot = std::cosf(rot);

	aMat.m00 = cosRot;
	aMat.m01 = -sinRot;
	aMat.m10 = sinRot;
	aMat.m11 = cosRot;

	*this = aMat * (*this);
}

void Sexy::SexyTransform2D::RotateDeg(float rot)
{
	RotateRad(M_PI * rot / 180.0f);
}

void Sexy::SexyTransform2D::Scale(float sx, float sy)
{
	SexyMatrix3 aMat;
	aMat.LoadIdentity();
	aMat.m00 = sx;
	aMat.m11 = sy;

	*this = aMat * (*this);
}


Sexy::SexyTransform2D& Sexy::SexyTransform2D::operator=(const SexyMatrix3& theMat)
{
	SexyMatrix3::operator=(theMat);
	return *this;
}