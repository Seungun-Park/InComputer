#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "Game2D.h"
#include "MonsterDot.h"
#include "Character.h"
#include "RandomNumberGenerator.h"

namespace su {
	using namespace jm;

	class Monster
	{
	protected:
		float speed = MONSTER_SPEED;
		bool state = 1; // 0: die, 1:live
		Timer time;
		Timer time2;
		Timer time3;
		float max_hp = 100.0f;
		float hp;
		bool move_direction = 0; // 0 : left, 1 : right
		bool move_state = 1;
		RandomNumberGenerator rand;

	public:
		float demage = 5.0f;
		float left_x;
		float right_x;
		float base_y;

		vec2 center = vec2(0.0f, 0.0f);
		MonsterDot *monsterdot;

	public:
		Monster() {}
		~Monster()
		{
			if (monsterdot != nullptr) delete monsterdot;
		}

	public:
		void process(Character *character);
		virtual void hitcheck(Character *character);
		void move();
		void draw();
		void charhit(Character *chracter);
		virtual void init(const float &x_left, const float &x_right, const float &y_base);
	};

	class Gold_box : public Monster
	{
	public:
		Gold_box(const float &x_left, const float &x_right, const float &y_base)
		{
			init(x_left, x_right, y_base);
		}
		void init(const float &x_left, const float &x_right, const float &y_base) override;
		void hitcheck(Character *character) override;
	};

	class Blue_box : public Monster
	{
	public:
		Blue_box(const float &x_left, const float &x_right, const float &y_base)
		{
			init(x_left, x_right, y_base);
		}
		void init(const float &x_left, const float &x_right, const float &y_base) override;
		void hitcheck(Character *character) override;
	};

	class Black_box : public Monster
	{
		float speed = MONSTER_SPEED * 4;
		float max_hp = 100.0f;
	public:
		float demage = 20.0f;
	public:
		Black_box(const float &x_left, const float &x_right, const float &y_base)
		{
			init(x_left, x_right, y_base);
		}
		void init(const float &x_left, const float &x_right, const float &y_base) override;
		void hitcheck(Character *character) override;
	};
}

#endif