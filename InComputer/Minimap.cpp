#include "Minimap.h"

void su::Minimap::process()
{
	draw();
}

void su::Minimap::draw()
{
	setLineWidth(1.0f);
	translate(-1.375f, 0.8f);
	beginTransformation();
	{
		drawWiredBox(Colors::black, 0.8f, 0.4f);
	}
	endTransformation();
}