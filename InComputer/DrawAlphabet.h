#ifndef __DRAWALPHABET_H__
#define __DRAWALPHABET_H__

#include "Game2D.h"
#include "DrawDot.h"
#include <string>

namespace su
{
	using namespace jm;
	class Alphabet
	{
	public:
		float x_size = 0.04f;
		float y_size = 0.04f;

	protected:
		float dot_size = 0.5 / (float)ALPHABET_DOT_X_SIZE;
		int m_dot[ALPHABET_DOT_Y_SIZE][ALPHABET_DOT_X_SIZE] = { 0 };
		RGB dot_color[ALPHABET_DOT_Y_SIZE][ALPHABET_DOT_X_SIZE] = { Colors::black, };

	public:
		Alphabet() {}
		~Alphabet() {}

		void drawDot();
		void reverse_copy(); // y_reverse_copy
		void reverse_copy2(); // x_reverse_copy
		void reverse(); // y_reverse
		void reverse2(); //x_reverse
	};

	/*
	class A : public Alphabet
	{
	public:
		A()
		{
			x_size = size_x;
			y_size = size_y;
			m_dot[2][6] = 1; m_dot[2][7] = 1; m_dot[2][8] = 1; m_dot[2][9] = 1;
			m_dot[3][5] = 1; m_dot[3][10] = 1;
			m_dot[4][5] = 1; m_dot[4][10] = 1;
			m_dot[5][4] = 1; m_dot[5][11] = 1;
			m_dot[6][4] = 1; m_dot[6][11] = 1;
			m_dot[7][4] = 1; m_dot[7][11] = 1;
			m_dot[8][4] = 1; m_dot[8][11] = 1;
			m_dot[9][3] = 1; m_dot[9][12] = 1;
			m_dot[10][3] = 1; m_dot[10][12] = 1;
			m_dot[11][3] = 1; m_dot[11][12] = 1;
			for (int i = 3; i < 13; i++)
				m_dot[12][i] = 1;
			m_dot[13][2] = 1; m_dot[13][13] = 1;
			m_dot[14][2] = 1; m_dot[14][13] = 1;
			m_dot[15][2] = 1; m_dot[15][13] = 1;
			m_dot[16][2] = 1; m_dot[16][13] = 1;
			m_dot[17][1] = 1; m_dot[17][14] = 1;
			m_dot[18][1] = 1; m_dot[18][14] = 1;
			m_dot[19][1] = 1; m_dot[19][14] = 1;
			m_dot[20][1] = 1; m_dot[20][14] = 1;
			m_dot[21][1] = 1; m_dot[21][14] = 1;
		}
	};
	*/

	class A : public Alphabet
	{
	public:
		A()
		{
			for (int i = 5; i < 11; i++) m_dot[2][i] = 1;
			for (int i = 5; i < 11; i++) m_dot[3][i] = 1;
			for (int i = 3; i < 13; i++) m_dot[11][i] = 1;
			for (int i = 2; i < 14; i++) m_dot[12][i] = 1;
			for (int i = 4; i < 12; i++)
			{
				m_dot[i][3] = 1;
				m_dot[i][4] = 1;
				m_dot[i][11] = 1;
				m_dot[i][12] = 1;
			}
			for (int i = 12; i < 21; i++)
			{
				m_dot[i][3] = 1;
				m_dot[i][2] = 1;
				m_dot[i][13] = 1;
				m_dot[i][12] = 1;
			}
		}
	};

	class B : public Alphabet
	{
	public:
		B()
		{
			for (int i = 3; i < 21; i++)
			{
				m_dot[i][2] = 1;
			}
			for (int i = 2; i < 22; i++)
			{
				m_dot[i][3] = 1;
			}
			for (int i = 4; i < 10; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[11][i] = 1;
				m_dot[12][i] = 1;
				m_dot[20][i] = 1;
				m_dot[21][i] = 1;
			}
			m_dot[3][10] = 1; m_dot[3][11] = 1;
			m_dot[4][10] = 1; m_dot[4][11] = 1; m_dot[4][12] = 1;
			for (int i = 5; i < 9; i++)
			{
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
			m_dot[9][11] = 1; m_dot[9][12] = 1;
			m_dot[10][10] = 1; m_dot[10][11] = 1;
			m_dot[11][10] = 1;
			reverse_copy();
		}
	};

	class C : public Alphabet
	{
	public:
		C()
		{
			for (int i = 6; i < 10; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
			}
			m_dot[4][4] = 1; m_dot[4][5] = 1;
			m_dot[5][4] = 1; m_dot[5][5] = 1;
			m_dot[4][10] = 1; m_dot[4][11] = 1;
			m_dot[5][10] = 1; m_dot[5][11] = 1;
			m_dot[6][12] = 1; m_dot[6][13] = 1;
			m_dot[7][12] = 1; m_dot[7][13] = 1;
			for (int i = 6; i < 13; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			m_dot[3][5] = 1; m_dot[4][6] = 1;
			m_dot[5][3] = 1; m_dot[6][4] = 1;
			m_dot[3][10] = 1; m_dot[4][9] = 1;
			m_dot[5][12] = 1; m_dot[6][11] = 1;
			reverse_copy();
		}
	};

	class D : public Alphabet
	{
	public:
		D()
		{
			for (int i = 3; i < 8; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
			}
			for (int i = 8; i < 11; i++)
			{
				m_dot[4][i] = 1;
				m_dot[5][i] = 1;
			}
			m_dot[6][11] = 1;
			m_dot[7][11] = 1; m_dot[7][12] = 1;
			for (int i = 3; i < 13; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			for (int i = 8; i < 13; i++)
			{
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
			reverse_copy();
		}
	};

	class E : public Alphabet
	{
	public:
		E()
		{
			for (int i = 4; i < 14; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[11][i] = 1;
			}
			m_dot[3][3] = 1;
			for (int i = 4; i < 12; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			reverse_copy();
		}
	};

	class F : public Alphabet
	{
	public:
		F()
		{
			for (int i = 4; i < 14; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[9][i] = 1;
				m_dot[10][i] = 1;
			}
			for (int i = 4; i < 22; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			m_dot[3][3] = 1;
		}
	};

	class G : public Alphabet
	{
	public:
		G()
		{
			for (int i = 6; i < 10; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
			}
			m_dot[4][4] = 1; m_dot[4][5] = 1;
			m_dot[5][4] = 1; m_dot[5][5] = 1;
			m_dot[4][10] = 1; m_dot[4][11] = 1;
			m_dot[5][10] = 1; m_dot[5][11] = 1;
			m_dot[6][12] = 1; m_dot[6][13] = 1;
			m_dot[7][12] = 1; m_dot[7][13] = 1;
			for (int i = 6; i < 13; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			m_dot[3][5] = 1; m_dot[4][6] = 1;
			m_dot[5][3] = 1; m_dot[6][4] = 1;
			m_dot[3][10] = 1; m_dot[4][9] = 1;
			m_dot[5][12] = 1; m_dot[6][11] = 1;
			reverse_copy();
			m_dot[14][12] = 1; m_dot[14][13] = 1;
			m_dot[15][12] = 1; m_dot[15][13] = 1;
			m_dot[13][12] = 1;
			for (int i = 7; i < 12; i++)
			{
				m_dot[12][i] = 1;
				m_dot[13][i] = 1;
			}
			m_dot[13][12] = 1; m_dot[14][11] = 1;
		}
	};

	class H : public Alphabet
	{
	public:
		H()
		{
			for (int i = 2; i < 22; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
			for (int i = 4; i < 12; i++)
			{
				m_dot[11][i] = 1;
				m_dot[12][i] = 1;
			}
		}
	};

	class I : public Alphabet
	{
	public:
		I()
		{
			for (int i = 2; i < 14; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[20][i] = 1;
				m_dot[21][i] = 1;
			}
			for (int i = 4; i < 20; i++)
			{
				m_dot[i][7] = 1;
				m_dot[i][8] = 1;
			}
		}
	};

	class J : public Alphabet
	{
	public:
		J()
		{

			for (int i = 2; i < 14; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
			}
			for (int i = 4; i < 19; i++)
			{
				m_dot[i][7] = 1;
				m_dot[i][8] = 1;
			}
			m_dot[19][7] = 1;
			m_dot[19][5] = 1; m_dot[19][6] = 1;
			m_dot[20][3] = 1; m_dot[20][4] = 1;
			m_dot[20][5] = 1; m_dot[20][5] = 1;
			m_dot[21][3] = 1; m_dot[21][4] = 1;
			for (int i = 15; i < 20; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
		}
	};

	class K : public Alphabet
	{
	public:
		K()
		{
			for (int i = 2; i < 12; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			int j = 3;
			for (int i = 11; i > 2; i--)
			{
				m_dot[i][j] = 1;
				m_dot[i + 1][j] = 1;
				m_dot[i + 2][j] = 1;
				j++;
			}
			m_dot[3][12] = 1;
			m_dot[4][12] = 1;
			reverse_copy();
		}
	};

	class L : public Alphabet
	{
	public:
		L()
		{
			for (int i = 2; i < 21; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			for (int i = 3; i < 14; i++)
			{
				m_dot[20][i] = 1;
				m_dot[21][i] = 1;
			}
		}
	};

	class M : public Alphabet
	{
	public:
		M()
		{
			for (int i = 6; i < 22; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
				m_dot[i][7] = 1;
			}
			m_dot[4][3] = 1; m_dot[4][4] = 1;
			m_dot[5][3] = 1; m_dot[5][4] = 1;
			m_dot[2][4] = 1; m_dot[2][5] = 1; m_dot[2][6] = 1;
			m_dot[3][4] = 1; m_dot[3][5] = 1; m_dot[3][6] = 1;
			m_dot[4][6] = 1; m_dot[4][7] = 1;
			m_dot[5][6] = 1; m_dot[5][7] = 1;

			reverse_copy2();
		}
	};

	class N : public Alphabet
	{
	public:
		N()
		{
			for (int i = 3; i < 21; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
			int j = 3;
			for (int i = 4; i < 12; i++)
			{
				m_dot[j][i] = 1;
				m_dot[j + 1][i] = 1;
				m_dot[j + 2][i] = 1;
				m_dot[j + 3][i] = 1;
				j += 2;
			}
		}
	};

	class O : public Alphabet
	{
	public:
		O()
		{
			for (int i = 4; i < 12; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[20][i] = 1;
				m_dot[21][i] = 1;
			}
			for (int i = 4; i < 20; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
			m_dot[3][3] = 1; m_dot[4][4] = 1;
			m_dot[3][12] = 1; m_dot[4][11] = 1;
			m_dot[20][3] = 1; m_dot[19][4] = 1;
			m_dot[20][12] = 1; m_dot[20][11] = 1;
		}
	};

	class P : public Alphabet
	{
	public:
		P()
		{
			for (int i = 3; i < 22; i++)
			{
				m_dot[i][3] = 1;
				m_dot[i][4] = 1;
			}
			for (int i = 4; i < 10; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[10][i] = 1;
				m_dot[11][i] = 1;
			}
			for (int i = 5; i < 9; i++)
			{
				m_dot[i][11] = 1;
				m_dot[i][12] = 1;
			}
			m_dot[3][10] = 1;
			m_dot[4][9] = 1; m_dot[4][10] = 1; m_dot[4][11] = 1;
			m_dot[5][10] = 1;

			m_dot[8][10] = 1;
			m_dot[9][9] = 1;
			m_dot[9][10] = 1;
			m_dot[9][11] = 1;
			m_dot[10][10] = 1;
		}
	};

	class Q : public Alphabet
	{
	public:
		Q()
		{
			for (int i = 4; i < 12; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[20][i] = 1;
				m_dot[21][i] = 1;
			}
			for (int i = 4; i < 20; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
			m_dot[3][3] = 1; m_dot[4][4] = 1;
			m_dot[3][12] = 1; m_dot[4][11] = 1;
			m_dot[20][3] = 1; m_dot[19][4] = 1;
			m_dot[20][12] = 1; m_dot[20][11] = 1;

			int j = 7;
			for (int i = 13; i < 24; i++)
			{
				m_dot[i][j] = 1;
				m_dot[i + 1][j] = 1;
				m_dot[i + 2][j] = 1;
				j++;
			}
		}
	};

	class R : public Alphabet
	{
	public:
		R()
		{/*
			for (int i = 3; i < 22; i++)
			{
				m_dot[i][3] = 1;
				m_dot[i][4] = 1;
			}
			for (int i = 4; i < 10; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[10][i] = 1;
				m_dot[11][i] = 1;
			}
			for (int i = 5; i < 9; i++)
			{
				m_dot[i][11] = 1;
				m_dot[i][12] = 1;
			}
			m_dot[3][10] = 1;
			m_dot[4][9] = 1; m_dot[4][10] = 1; m_dot[4][11] = 1;
			m_dot[5][10] = 1;

			m_dot[8][10] = 1;
			m_dot[9][9] = 1;
			m_dot[9][10] = 1;
			m_dot[9][11] = 1;
			m_dot[10][10] = 1;

			int j = 5;
			for (int i = 12; i < 20; i++)
			{
				m_dot[i][j] = 1;
				m_dot[i + 1][j] = 1;
				m_dot[i + 2][j] = 1;
				j++;
			}
			*/

			for (int i = 2; i < 22; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			for (int i = 4; i < 10; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[11][i] = 1;
				m_dot[12][i] = 1;
			}
			for (int i = 14; i<22; i++)
			{
				m_dot[i][11] = 1;
				m_dot[i][12] = 1;
			}
			int j = 9;
			for (int i = 2; i < 7; i++)
			{
				m_dot[i][j] = 1;
				m_dot[i + 1][j] = 1;
				m_dot[i + 2][j] = 1;
				j++;
			}
			j = 9;
			for (int i = 11; i < 15; i++)
			{
				m_dot[i][j] = 1;
				m_dot[i + 1][j] = 1;
				m_dot[i + 2][j] = 1;
				j++;
			}
			j = 9;
			for (int i = 10; i > 6; i--)
			{
				m_dot[i][j] = 1;
				m_dot[i + 1][j] = 1;
				m_dot[i + 2][j] = 1;
				j++;
			}
		}
	};

	class S : public Alphabet
	{
	public:
		S()
		{
			for (int i = 4; i < 12; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[11][i] = 1;
				m_dot[12][i] = 1;
				m_dot[20][i] = 1;
				m_dot[21][i] = 1;
			}
			for (int i = 4; i < 11; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			for (int i = 16; i < 20; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
			}
			for (int i = 4; i < 8; i++)
			{
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
			for (int i = 13; i < 20; i++)
			{
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
		}
	};

	class T : public Alphabet
	{
	public:
		T()
		{
			for (int i = 2; i < 14; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
			}
			for (int i = 4; i < 22; i++)
			{
				m_dot[i][7] = 1;
				m_dot[i][8] = 1;
			}
		}
	};

	class U : public Alphabet
	{
	public:
		U()
		{
			for (int i = 2; i < 20; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
				m_dot[i][12] = 1;
				m_dot[i][13] = 1;
			}
			for (int i = 4; i < 12; i++)
			{
				m_dot[20][i] = 1;
				m_dot[21][i] = 1;
			}
			m_dot[19][4] = 1; m_dot[20][3] = 1;
			m_dot[19][11] = 1; m_dot[20][12] = 1;
		}
	};

	class V : public Alphabet
	{
	public:
		V()
		{
			int j = 2;
			for (int i = 2; i < 8; i++)
			{
				m_dot[j][i] = 1;
				m_dot[j + 1][i] = 1;
				m_dot[j + 2][i] = 1;
				m_dot[j + 3][i] = 1;
				m_dot[j + 4][i] = 1;
				j += 3;
			}
			m_dot[2][1] = 1;
			m_dot[3][1] = 1;
			m_dot[4][1] = 1;

			reverse_copy2();
		}
	};

	class W : public Alphabet
	{
	public:
		W()
		{
			for (int i = 6; i < 22; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][3] = 1;
				m_dot[i][7] = 1;
			}
			m_dot[4][3] = 1; m_dot[4][4] = 1;
			m_dot[5][3] = 1; m_dot[5][4] = 1;
			m_dot[2][4] = 1; m_dot[2][5] = 1; m_dot[2][6] = 1;
			m_dot[3][4] = 1; m_dot[3][5] = 1; m_dot[3][6] = 1;
			m_dot[4][6] = 1; m_dot[4][7] = 1;
			m_dot[5][6] = 1; m_dot[5][7] = 1;

			reverse_copy2();
			reverse();
		}
	};

	class X : public Alphabet
	{
	public:
		X()
		{
			int j = 2;
			for (int i = 3; i < 8; i++)
			{
				m_dot[j][i] = 1;
				m_dot[j + 1][i] = 1;
				m_dot[j + 2][i] = 1;
				m_dot[j + 3][i] = 1;
				j+=2;
			}

			for (int i = 8; i < 13; i++)
			{
				j-=2;
				m_dot[j][i] = 1;
				m_dot[j + 1][i] = 1;
				m_dot[j + 2][i] = 1;
				m_dot[j + 3][i] = 1;
			}
			m_dot[2][2] = 1; m_dot[3][2] = 1;
			m_dot[2][13] = 1; m_dot[3][13] = 1;
			reverse_copy();
		}
	};

	class Y : public Alphabet
	{
	public:
		Y()
		{
			int j = 2;
			for (int i = 3; i < 8; i++)
			{
				m_dot[j][i] = 1;
				m_dot[j + 1][i] = 1;
				m_dot[j + 2][i] = 1;
				m_dot[j + 3][i] = 1;
				j += 2;
			}

			for (int i = 8; i < 13; i++)
			{
				j -= 2;
				m_dot[j][i] = 1;
				m_dot[j + 1][i] = 1;
				m_dot[j + 2][i] = 1;
				m_dot[j + 3][i] = 1;
			}
			m_dot[2][2] = 1; m_dot[3][2] = 1;
			m_dot[2][13] = 1; m_dot[3][13] = 1;
			for (int i = 14; i < 22; i++)
			{
				m_dot[i][7] = 1;
				m_dot[i][8] = 1;
			}
		}
	};

	class Z : public Alphabet
	{
	public:
		Z()
		{
			for (int i = 1; i < 13; i++)
			{
				m_dot[2][i] = 1;
				m_dot[3][i] = 1;
				m_dot[20][i] = 1;
				m_dot[21][i] = 1;
			}
			int j = 18;
			for (int i = 3; i < 12; i++)
			{
				m_dot[j][i] = 1;
				m_dot[j + 1][i] = 1;
				m_dot[j + 2][i] = 1;
				m_dot[j + 3][i] = 1;
				j -= 2;
			}
		}
	};

	class Dot : public Alphabet
	{
	public:
		Dot()
		{
			m_dot[18][3] = 1;
			m_dot[18][4] = 1;
			m_dot[19][2] = 1;
			m_dot[19][3] = 1;
			m_dot[19][4] = 1;
			m_dot[19][5] = 1;
			m_dot[20][2] = 1;
			m_dot[20][3] = 1;
			m_dot[20][4] = 1;
			m_dot[20][5] = 1;
			m_dot[21][3] = 1;
			m_dot[21][4] = 1;
		}
	};

	class Exclamation : public Alphabet
	{
	public:
		Exclamation()
		{
			m_dot[18][3] = 1;
			m_dot[18][4] = 1;
			m_dot[19][2] = 1;
			m_dot[19][3] = 1;
			m_dot[19][4] = 1;
			m_dot[19][5] = 1;
			m_dot[20][2] = 1;
			m_dot[20][3] = 1;
			m_dot[20][4] = 1;
			m_dot[20][5] = 1;
			m_dot[21][3] = 1;
			m_dot[21][4] = 1;

			for (int i = 2; i < 16; i++)
			{
				m_dot[i][3] = 1;
				m_dot[i][4] = 1;
			}
			/*for (int i = 2; i < 7; i++)
			{
				m_dot[i][2] = 1;
				m_dot[i][5] = 1;
			}*/
		}
	};

	class Question : public Alphabet
	{
	public:
		Question()
		{
			m_dot[18][7] = 1;
			m_dot[18][8] = 1;
			m_dot[19][6] = 1;
			m_dot[19][7] = 1;
			m_dot[19][8] = 1;
			m_dot[19][9] = 1;
			m_dot[20][6] = 1;
			m_dot[20][7] = 1;
			m_dot[20][8] = 1;
			m_dot[20][9] = 1;
			m_dot[21][7] = 1;
			m_dot[21][8] = 1;

			for (int i = 5; i < 11; i++)
			{
				m_dot[2][i] = 1;
			}
			for (int i = 4; i < 12; i++)
			{
				m_dot[3][i] = 1;
			}
			m_dot[4][3] = 1; m_dot[4][4] = 1; m_dot[4][5] = 1;
			m_dot[4][10] = 1; m_dot[4][11] = 1; m_dot[4][12] = 1;
			m_dot[5][3] = 1; m_dot[5][4] = 1; m_dot[5][11] = 1; m_dot[5][12] = 1;
			m_dot[6][3] = 1; m_dot[6][4] = 1; m_dot[6][5] = 1;
			m_dot[7][4] = 1; m_dot[7][5] = 1;
			m_dot[6][11] = 1; m_dot[6][12] = 1;
			m_dot[7][10] = 1; m_dot[7][11] = 1; m_dot[7][12] = 1;
			for (int i = 10; i < 16; i++)
			{
				m_dot[i][7] = 1; m_dot[i][8] = 1;
			}
			m_dot[8][9] = 1; m_dot[8][10] = 1; m_dot[8][11] = 1;
			m_dot[9][8] = 1; m_dot[9][9] = 1; m_dot[9][10] = 1;
		}
	};

	class Space : public Alphabet
	{
	public:
		Space() {}
	};

	using namespace std;
	class DrawString : public Alphabet
	{
	protected:
		bool alignment;
		float start_x, start_y;
		string str;
		Alphabet * str_ptr[100] = { nullptr };
		
	public:
		DrawString(const string &str, const float &x, const float &y, const bool &alignment = false)
			: str(str), start_x(x), start_y(y), alignment(alignment)
		{
			if (alignment)
			{
				start_x -= str.length() / 2 *x_size;
			}
			init();
		}
		DrawString(const string &str, const float &x, const float &y, const float& size, const bool &alignment = false)
			: str(str), start_x(x), start_y(y), alignment(alignment)
		{
			x_size = size;
			y_size = size;
			if (alignment)
			{
				start_x -= str.length() / 2 * x_size;
			}
			init();
		}
		~DrawString()
		{
			for (int i = 0; i < str.length(); i++)
			{
				if (str_ptr[i] != nullptr) delete str_ptr[i];
			}
		}

		void init();
		void draw();
	};
}

#endif