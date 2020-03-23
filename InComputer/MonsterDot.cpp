#include "MonsterDot.h"

void su::MonsterDot::drawDot()
{
	beginTransformation();
	{
		scale(x_size*2.0f, y_size*2.0f);
		drawFilledSquare(Colors::white, 0.01f);
		translate(-((float)MONSTER_DOT_X_SIZE / 2.0f * dot_size) + dot_size / 2, +((float)MONSTER_DOT_Y_SIZE / 2.0f * dot_size) - dot_size / 2);
		for (int i = 0; i < MONSTER_DOT_Y_SIZE; i++)
		{
			for (int j = 0; j < MONSTER_DOT_X_SIZE; j++)
			{
				if (m_dot[i][j])
				{
					drawFilledSquare(dot_color[i][j], dot_size);
				}
				translate(dot_size, 0.0f);
			}
			translate(-(float)MONSTER_DOT_X_SIZE * dot_size, -dot_size);
		}
	}
	endTransformation();
}