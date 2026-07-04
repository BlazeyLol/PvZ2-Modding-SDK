//
// TriVertex.h
//

#ifndef __TriVertex__
#define __TriVertex__


namespace Sexy
{

	class TriVertex
	{
	public:

		float x, y, u, v;
		int color; //ARGB (0 = use color specified in function call)


		TriVertex() { color = 0; }
		TriVertex(float theX, float theY) : x(theX), y(theY) { color = 0; }
		TriVertex(float theX, float theY, float theU, float theV) : x(theX), y(theY), u(theU), v(theV) { color = 0; }
		TriVertex(float theX, float theY, float theU, float theV, int theColor) : x(theX), y(theY), u(theU), v(theV), color(theColor) {}

	};

} // Sexy

#endif // __TriVertex__