#ifndef __DRAWDOT_H__
#define __DRAWDOT_H__

#include "Game2D.h"
#include <iostream>

namespace su
{
	using namespace jm;

	class DrawDot
	{
	public:
		float x_size, y_size;

	protected:
		float dot_size = 0.5 / (float)ALPHABET_DOT_X_SIZE;
		int m_dot[ALPHABET_DOT_Y_SIZE][ALPHABET_DOT_X_SIZE] = { 0 };
		RGB dot_color[ALPHABET_DOT_Y_SIZE][ALPHABET_DOT_X_SIZE];
	public:
		DrawDot()
		{
			//std::cout << "DrawDot Difault Constructer" << std::endl;
		}
		DrawDot(const float &size_x, const float &size_y)
			:x_size(size_x), y_size(size_y)
		{
			//std::cout << "DrawDot Constructer" << std::endl;
		}

		virtual ~DrawDot()
		{
			//std::cout << "DrawDot Destructor" << std::endl;
		}

		virtual void drawDot();
	};
}

#endif