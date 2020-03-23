#ifndef __CHARACTERDOT_H__
#define __CHARACTERDOT_H__

#include "DrawDot.h"

namespace su
{
	using namespace jm;

	class CharacterDot : public DrawDot
	{
	protected:
		float dot_size = 0.5 / (float)CHARACTER_DOT_X_SIZE;
		int m_dot[CHARACTER_DOT_Y_SIZE][CHARACTER_DOT_X_SIZE] = { 0 };
		/*RGB dot_color[CHARACTER_DOT_Y_SIZE][CHARACTER_DOT_X_SIZE] = { { RGB(0, 0, 0), RGB(0, 0, 113), RGB(255, 255, 210), RGB(0, 0, 113), RGB(255, 255, 210), RGB(0, 0, 113), RGB(255, 255, 210), RGB(0, 0, 113), RGB(255, 255, 210), RGB(0, 0, 113), RGB(255, 255, 210), RGB(0, 0, 113), RGB(255, 255, 210), RGB(0, 0, 113), RGB(255, 255, 210), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(0, 0, 0) },
		{ RGB(0, 0, 0), RGB(0, 0, 0), RGB(0, 0, 79), RGB(0, 0, 0), RGB(0, 0, 79), RGB(0, 0, 0), RGB(0, 0, 79), RGB(0, 0, 0), RGB(0, 0, 79), RGB(0, 0, 0), RGB(0, 0, 79), RGB(0, 0, 0), RGB(0, 0, 79), RGB(0, 0, 0), RGB(0, 0, 79), RGB(0, 0, 0) } };
		*/
	public:
		CharacterDot()
		{
			//std::cout << "CharacterDot Difault Constructer" << std::endl;
		}
		CharacterDot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			//std::cout << "CharacterDot Constructer" << std::endl;
			for (int i = 0; i < CHARACTER_DOT_Y_SIZE / 2; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::red;
				}
			}
			dot_color[4][11] = Colors::black;
			dot_color[5][11] = Colors::black;
			dot_color[6][11] = Colors::black;
			dot_color[10][12] = Colors::black;
			dot_color[10][13] = Colors::black;
			dot_color[10][14] = Colors::black;
			for (int i = CHARACTER_DOT_Y_SIZE / 2; i < CHARACTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::green;
				}
			}
			for (int i = 0; i < CHARACTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
				}
			}
		}
		virtual ~CharacterDot()
		{
			//std::cout << "CharacterDot Destructor" << std::endl;
		}

		void drawDot() override;
	};

	class MageDot : public CharacterDot
	{
	public:
		MageDot()
		{
			//std::cout << "MageDot Difault Constructer" << std::endl;
		}
		MageDot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			//std::cout << "MageDot Constructer" << std::endl;
			for (int i = 0; i < CHARACTER_DOT_Y_SIZE / 2; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::blue;
				}
			}
			dot_color[4][12] = Colors::black;
			dot_color[5][12] = Colors::black;
			dot_color[6][12] = Colors::black;
			dot_color[10][13] = Colors::black;
			dot_color[10][14] = Colors::black;
			dot_color[10][15] = Colors::black;
			for (int i = CHARACTER_DOT_Y_SIZE / 2; i < CHARACTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::green;
				}
			}
		}

		virtual ~MageDot()
		{
			//std::cout << "MageDot Destructor" << std::endl;
		}
	};

	class WarriorDot : public CharacterDot
	{
	public:
		WarriorDot()
		{
			//std::cout << "WarriorDot Difault Constructer" << std::endl;
		}
		WarriorDot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			//std::cout << "WarriorDot Constructer" << std::endl;
			for (int i = 0; i < CHARACTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::gold;
				}
			}
			dot_color[4][12] = Colors::black;
			dot_color[5][12] = Colors::black;
			dot_color[6][12] = Colors::black;
			dot_color[13][13] = Colors::black;
			dot_color[13][14] = Colors::black;
			dot_color[13][15] = Colors::black;
		}

		virtual ~WarriorDot()
		{
			//std::cout << "WarriorDot Destructor" << std::endl;
		}
	};
}

#endif