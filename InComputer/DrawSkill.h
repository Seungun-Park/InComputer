#ifndef __DRAWSKILL_H__
#define __DRAWSKILL_H__

#include "DrawDot.h"

namespace su
{
	using namespace jm;

	class SkillDot : public DrawDot
	{
	protected:

	public:
		SkillDot() {}
		virtual ~SkillDot() {}
	};

	class AttackDot : public SkillDot
	{
	public:
		AttackDot()
		{
			x_size = 0.4f;
			y_size = 0.2f;
			for (int i = 8; i < 15; i++)
			{
				m_dot[7][i] = 1;
				dot_color[7][i] = Colors::silver;
				m_dot[8][i] = 1;
				dot_color[8][i] = Colors::silver;
			}
		}
		~AttackDot() {}

	};
}

#endif