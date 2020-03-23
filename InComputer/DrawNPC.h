#ifndef __DRAWNPC_H__
#define __DRAWNPC_H__

#include "DrawDot.h"

namespace su
{
	using namespace jm;

	class NPCDot : public DrawDot
	{
	protected:
		float dot_size = 0.5 / (float)CHARACTER_DOT_X_SIZE;
		int m_dot[CHARACTER_DOT_Y_SIZE][CHARACTER_DOT_X_SIZE] = { 0 };

	public:
		NPCDot()
		{
			//std::cout << "CharacterDot Difault Constructer" << std::endl;
		}
		NPCDot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			//std::cout << "CharacterDot Constructer" << std::endl;
			for (int i = 0; i < CHARACTER_DOT_Y_SIZE / 2; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::pink;
				}
			}
			dot_color[4][12] = Colors::black;
			dot_color[5][12] = Colors::black;
			dot_color[6][12] = Colors::black;
			dot_color[4][3] = Colors::black;
			dot_color[5][3] = Colors::black;
			dot_color[6][3] = Colors::black;
			dot_color[10][6] = Colors::black;
			dot_color[10][7] = Colors::black;
			dot_color[10][8] = Colors::black;
			dot_color[10][9] = Colors::black;
			for (int i = CHARACTER_DOT_Y_SIZE / 2; i < CHARACTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::blue;
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
		virtual ~NPCDot()
		{
			//std::cout << "CharacterDot Destructor" << std::endl;
		}

		void drawDot() override;
	};

	class RegisterDot : public NPCDot
	{

	public:
		RegisterDot()
		{
			//std::cout << "CharacterDot Difault Constructer" << std::endl;
		}
		RegisterDot(const float &size_x, const float &size_y)
		{
			x_size = size_x;
			y_size = size_y;
			//std::cout << "CharacterDot Constructer" << std::endl;
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
			dot_color[4][3] = Colors::black;
			dot_color[5][3] = Colors::black;
			dot_color[6][3] = Colors::black;
			dot_color[10][6] = Colors::black;
			dot_color[10][7] = Colors::black;
			dot_color[10][8] = Colors::black;
			dot_color[10][9] = Colors::black;
			for (int i = CHARACTER_DOT_Y_SIZE / 2; i < CHARACTER_DOT_Y_SIZE; i++)
			{
				for (int j = 0; j < CHARACTER_DOT_X_SIZE; j++)
				{
					m_dot[i][j] = 1;
					dot_color[i][j] = Colors::yellow;
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
		virtual ~RegisterDot()
		{
			//std::cout << "CharacterDot Destructor" << std::endl;
		}
	};
}

#endif