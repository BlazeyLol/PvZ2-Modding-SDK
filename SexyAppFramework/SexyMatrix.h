//
// SexyMatrix.h
//

#ifndef __SexyMatrix__
#define __SexyMatrix__

#include "SexyVector.h"

//

namespace Sexy
{

	class SexyMatrix3
	{
	public:

		union
		{
			float m[3][3];
			struct
			{
				float m00, m01, m02;
				float m10, m11, m12;
				float m20, m21, m22;
			};
		};


		SexyMatrix3();

		void ZeroMatrix();
		void LoadIdentity();

		SexyVector2 operator*(const SexyVector2& theVec) const;
		SexyVector3 operator*(const SexyVector3& theVec) const;
		SexyMatrix3 operator*(const SexyMatrix3& theMat) const;
		const SexyMatrix3& operator*=(const SexyMatrix3& theMat);

	};

	//

	class SexyTransform2D : public SexyMatrix3
	{
	public:

		SexyTransform2D();
		SexyTransform2D(bool loadIdentity);

		void Translate(float tx, float ty);

		// Rotate has been replaced by RotateRad.
		// NOTE:  If you had Rotate(angle) you should now use RotateRad(-angle).
		// This is to make positive rotations go counter-clockwise when using screen coordinates.
		void RotateRad(float rot);
		void RotateDeg(float rot);
		void Scale(float sx, float sy);

		SexyTransform2D& operator=(const SexyMatrix3& theMat);

	};

} // Sexy

#endif // __SexyMatrix__