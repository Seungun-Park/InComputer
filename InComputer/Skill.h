#ifndef __SKILL_H__
#define __SKILL_H__

#include "DrawSkill.h"

namespace su
{
	using namespace jm;

	class Skill
	{
	public:
		bool direction; // 0 : left, 1 : right;
		float degree;
		vec2 center = vec2(0.0f, 0.0f);
		vec2 hit[4];
		float dem_per = 1.00f;
		SkillDot * skilldot;

	public:
		Skill() {}
		Skill(const float &x, const float &y)
		{
			center.x = x;
			center.y = y;
		}
		virtual ~Skill()
		{
			if (skilldot != nullptr) delete skilldot;
		}

		virtual bool process();
		virtual bool draw();
		virtual void hitbox();
	};

	class Attack : public Skill
	{

	public:
		Attack() {}
		Attack(const float &x, const float &y)
		{
			center.x = x;
			center.y = y;
			skilldot = new AttackDot;

			dem_per = 1.00f;
		}
		~Attack() {}

		bool process() override;
		bool draw() override;
		void hitbox() override;
	};
}


#endif