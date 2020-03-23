#ifndef __FLOORDOT_H__
#define __FLOORDOT_H__

#include "DrawDot.h"

namespace su
{
	using namespace jm;

	class FloorDot : public DrawDot
	{
	public:
		FloorDot()
		{
			//std::cout << "FloorDot Difault Constructer" << std::endl;
		}
		FloorDot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			//std::cout << "FloorDot Constructer" << std::endl;
			
			for (int i = 8; i < DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::gray;
				}
			}
		}
		~FloorDot()
		{
		//	std::cout << "FloorDot Destructor" << std::endl;
		}

		//void drawDot() override;
	};
}

#endif