#ifndef __MONSTERDOT_H__
#define __MONSTERDOT_H__

#include "DrawDot.h"

namespace su
{
	using namespace jm;

	class MonsterDot : public DrawDot
	{
	protected:
		float dot_size = 0.5 / (float)MONSTER_DOT_X_SIZE;
		int m_dot[MONSTER_DOT_Y_SIZE][MONSTER_DOT_X_SIZE] = { 0 };
		RGB dot_color[MONSTER_DOT_Y_SIZE][MONSTER_DOT_X_SIZE];

	public:
		MonsterDot() {}
		MonsterDot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			for (int i = 0; i < MONSTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < MONSTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::gold;
				}
			}
		}
		virtual ~MonsterDot() {}

		void drawDot() override;
	};

	class Gold_box_dot : public MonsterDot
	{
	public:
		Gold_box_dot() {}
		Gold_box_dot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			for (int i = 0; i < MONSTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < MONSTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::gold;
				}
			}
		}
		virtual ~Gold_box_dot() {}
	};

	class Blue_box_dot : public MonsterDot
	{
	public:
		Blue_box_dot() {}
		Blue_box_dot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			for (int i = 0; i < MONSTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < MONSTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::blue;
				}
			}
		}
		virtual ~Blue_box_dot() {}
	};

	class Black_box_dot : public MonsterDot
	{
	public:
		Black_box_dot() {}
		Black_box_dot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			for (int i = 0; i < MONSTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < MONSTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::black;
				}
			}
		}
		virtual ~Black_box_dot() {}
	};
}

#endif