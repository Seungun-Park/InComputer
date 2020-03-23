#include "DrawAlphabet.h"

void su::Alphabet::drawDot()
{
	beginTransformation();
	{
		scale(x_size*2.0f, y_size*2.0f);
		drawFilledSquare(Colors::white, 0.0001f);
		translate(-((float)ALPHABET_DOT_X_SIZE / 2.0f * dot_size) + dot_size / 2, +((float)ALPHABET_DOT_Y_SIZE / 2.0f * dot_size) - dot_size / 2);
		for (int i = 0; i < ALPHABET_DOT_Y_SIZE; i++)
		{
			for (int j = 0; j < ALPHABET_DOT_X_SIZE; j++)
			{
				if (m_dot[i][j])
				{
					drawFilledSquare(dot_color[i][j], dot_size);
				}
				translate(dot_size, 0.0f);
			}
			translate(-(float)ALPHABET_DOT_X_SIZE * dot_size, -dot_size);
		}
	}
	endTransformation();
}

void su::Alphabet::reverse_copy()
{
	for (int i = 0; i < ALPHABET_DOT_Y_SIZE / 2; i++)
	{
		for (int j = 0; j < ALPHABET_DOT_X_SIZE; j++)
		{
			m_dot[ALPHABET_DOT_Y_SIZE - i -1][j] = m_dot[i][j];
		}
	}
}

void su::Alphabet::reverse_copy2()
{
	for (int i = 0; i < ALPHABET_DOT_X_SIZE / 2; i++)
	{
		for (int j = 0; j < ALPHABET_DOT_Y_SIZE; j++)
		{
			m_dot[j][ALPHABET_DOT_X_SIZE - i - 1] = m_dot[j][i];
		}
	}
}

void su::Alphabet::reverse()
{
	bool tmp;
	for (int i = 0; i < ALPHABET_DOT_Y_SIZE / 2; i++)
	{
		for (int j = 0; j < ALPHABET_DOT_X_SIZE; j++)
		{
			tmp = m_dot[ALPHABET_DOT_Y_SIZE - i - 1][j];
			m_dot[ALPHABET_DOT_Y_SIZE - i - 1][j] = m_dot[i][j];
			m_dot[i][j] = tmp;
		}
	}
}

void su::Alphabet::reverse2()
{
	bool tmp;
	for (int i = 0; i < ALPHABET_DOT_X_SIZE / 2; i++)
	{
		for (int j = 0; j < ALPHABET_DOT_Y_SIZE; j++)
		{
			tmp = m_dot[j][ALPHABET_DOT_X_SIZE - i - 1];
			m_dot[j][ALPHABET_DOT_X_SIZE - i - 1] = m_dot[j][i];
			m_dot[j][i] = tmp;
		}
	}
}

void su::DrawString::init()
{
	if(str != "")
	{
		for (int i = 0; i < str.length(); i++)
		{
			switch (str[i])
			{
			case 'A':
			case 'a': str_ptr[i] = new A; break;

			case 'B':
			case 'b': str_ptr[i] = new B; break;

			case 'C':
			case 'c': str_ptr[i] = new C; break;

			case 'D':
			case 'd': str_ptr[i] = new D; break;

			case 'E':
			case 'e': str_ptr[i] = new E; break;

			case 'F':
			case 'f': str_ptr[i] = new F; break;

			case 'G':
			case 'g': str_ptr[i] = new G; break;

			case 'H':
			case 'h': str_ptr[i] = new H; break;

			case 'I':
			case 'i': str_ptr[i] = new I; break;

			case 'J':
			case 'j': str_ptr[i] = new J; break;

			case 'K':
			case 'k': str_ptr[i] = new K; break;

			case 'L':
			case 'l': str_ptr[i] = new L; break;

			case 'M':
			case 'm': str_ptr[i] = new M; break;

			case 'N':
			case 'n': str_ptr[i] = new N; break;

			case 'O':
			case 'o': str_ptr[i] = new O; break;

			case 'P':
			case 'p': str_ptr[i] = new P; break;

			case 'Q':
			case 'q': str_ptr[i] = new Q; break;

			case 'R':
			case 'r': str_ptr[i] = new R; break;

			case 'S':
			case 's': str_ptr[i] = new S; break;

			case 'T':
			case 't': str_ptr[i] = new T; break;

			case 'U':
			case 'u': str_ptr[i] = new U; break;

			case 'V':
			case 'v': str_ptr[i] = new V; break;

			case 'W':
			case 'w': str_ptr[i] = new W; break;

			case 'X':
			case 'x': str_ptr[i] = new X; break;

			case 'Y':
			case 'y': str_ptr[i] = new Y; break;

			case 'Z':
			case 'z': str_ptr[i] = new Z; break;

			case '.': str_ptr[i] = new Dot; break;

			case '!': str_ptr[i] = new Exclamation; break;

			case '?': str_ptr[i] = new Question; break;

			case ' ': str_ptr[i] = new Space; break;

			default: str_ptr[i] = new Space; break;
			}
			str_ptr[i]->x_size = x_size;
			str_ptr[i]->y_size = y_size;
		}
	}
}

void su::DrawString::draw()
{
	if (str != "")
	{
		beginTransformation();
		{
			translate(start_x, start_y);
			str_ptr[0]->drawDot();
			for (int i = 1; i < str.length(); i++)
			{
				translate(x_size, 0.0f);
				str_ptr[i]->drawDot();
			}
		}
		endTransformation();
	}
}