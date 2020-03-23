#include "FloorDot.h"

/*

void su::FloorDot::drawDot()
{
	beginTransformation();
	{
		scale(x_size*2.0f, y_size*2.0f);
		drawFilledSquare(Colors::white, 0.01f);
		translate(-((float)DOT_X_SIZE / 2.0f * dot_size) + dot_size / 2, +((float)DOT_Y_SIZE / 2.0f * dot_size) - dot_size / 2);
		for (int i = 0; i < DOT_Y_SIZE; i++)
		{
			for (int j = 0; j < DOT_X_SIZE; j++)
			{
				if (m_dot[i][j])
				{
					drawFilledSquare(dot_color[i][j], dot_size);
				}
				translate(dot_size, 0.0f);
			}
			translate(-(float)DOT_X_SIZE * dot_size, -dot_size);
		}
	}
	endTransformation();
}

*/