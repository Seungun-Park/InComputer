#ifndef __MINIMAP_H__
#define __MINIMAP_H__

#include "Game2D.h"
#include "DrawFunctions.h"

namespace su {
	using namespace jm;

	class Minimap
	{
	public:
		Minimap() {}
		~Minimap() {}

	public:
		void process();
		void draw();
	};
}

#endif