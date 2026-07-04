//
// RenderDevice.h
//

#ifndef __RenderDevice__
#define __RenderDevice__

#include "GameCommon.h"
#include "Rect.h"
#include "Color.h"
#include "Image.h"
#include "TriVertex.h"
#include "SexyMatrix.h"

//

namespace Sexy
{

	class RenderDevice
	{
	public:

		virtual ~RenderDevice() {}
		virtual void Function2() {}
		virtual bool CanFillPoly() {}
		virtual void Function4() {}
		virtual void Function5() {}
		virtual void SetRenderContext(void* theContext) {}
		virtual void* GetRenderContext() {}
		virtual void PushState() {}
		virtual void PopState() {}
		virtual void ClearRect(const Rect& theRect) {}
		virtual void FillRect(const Rect& theRect, const Color& theColor, int theDrawMode) {}
		virtual void Function12() {}
		virtual void PolyFill3D(const Point theVertices[], int theNumVertices, const Rect* theClipRect, const Color& theColor, int theDrawMode, int tx, int ty, bool convex) {}
		virtual void DrawLine(double theStartX, double theStartY, double theEndX, double theEndY, const Color& theColor, int theDrawMode, bool isAA) {}
		virtual void Blt(Image* theImage, int theX, int theY, const Rect& theSrcRect, const Color& theColor, int theDrawMode) {}
		virtual void BltF(Image* theImage, float theX, float theY, const Rect& theSrcRect, const Rect& theClipRect, const Color& theColor, int theDrawMode) {}
		virtual void BltRotated(Image* theImage, float theX, float theY, const Rect& theSrcRect, const Rect& theClipRect, const Color& theColor, int theDrawMode, double theRot, float theRotCenterX, float theRotCenterY) {}
		virtual void BltMatrix(Image* theImage, float x, float y, const SexyMatrix3& theMatrix, const Rect& theClipRect, const Color& theColor, int theDrawMode, const Rect& theSrcRect, bool blend) {}
		virtual void BltTrianglesTex(Image* theTexture, const TriVertex theVertices[][3], int theNumTriangles, const Rect& theClipRect, const Color& theColor, int theDrawMode, float tx, float ty, bool blend) {}
		virtual void BltMirror(Image* theImage, int theX, int theY, const Rect& theSrcRect, const Color& theColor, int theDrawMode) {}
		virtual void StretchBlt(Image* theImage, const Rect& theDestRect, const Rect& theSrcRect, const Rect& theClipRect, const Color& theColor, int theDrawMode, bool fastStretch) {}
		virtual void Function22() {}
		virtual void Function23() {}
		virtual void DrawRect(const Rect& theRect, const Color& theColor, int theDrawMode) {}
		virtual void FillScanLines(Span* theSpans, int theSpanCount, const Color& theColor, int theDrawMode) {}

	};

} // Sexy

#endif // __RenderDevice__