//
// Renderable
//

#ifndef __Renderable__
#define __Renderable__

#include "Graphics.h"

//

class Renderable
{
public:

	virtual ~Renderable() = 0;
	virtual void Draw(Sexy::Graphics* g) = 0;
	virtual int GetRenderLayer() = 0;

};

#endif // __Renderable__