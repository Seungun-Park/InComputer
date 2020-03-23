#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Skill.h"
#include "Game2D.h"
#include "CharacterDot.h"
#include "DrawAlphabet.h"
#include <iostream>
#include "RandomNumberGenerator.h"

namespace su
{
	using namespace jm;
	using namespace std;

	class Character
	{
	protected:
		RandomNumberGenerator rand;
		float max_exp = 100.0f;
		float recovery_hp = 2.5f;
		float recovery_mp = 10.0f;
		float max_hp = 100.0f;
		float max_mp = 100.0f;
		
		Timer time;
		Timer recovery_timer;
		Timer str_timer;
		Timer shot_timer;

	//dot
	public:
		string name = "character";
		CharacterDot * characterdot;
		Skill * skill;
		DrawString *str_name;

	//value
	public:
		float front_demage = 8.0f;
		float back_demage = 12.0f;
		float demage = 10.0;
		int attack_state = 0; // 0 : none attack, 1 : attack, 2 : can't next attack
		bool fall_state = 1; // 0 : none fall, 1: fall
		bool jump_state = 0; // 0 : none jump, 1: jump
		float x_size = 0.2f;
		float y_size = 0.3f;
		float x_speed = 0;
		float y_speed = 0;
		vec2 center = vec2(0.0f, 0.0f);
		float exp;
		float hp;
		float mp;
		int level;
		int quest[100] = { 0 };

	//constructer, distructer
	public:
		Character() 
		{
			//std::cout << "Character Default Constructer" << std::endl;
		};
		Character(int)
		{
			//std::cout << "Character Constructer" << std::endl;
			characterdot = new CharacterDot(CHARACTER_X_SIZE, CHARACTER_Y_SIZE);
			
			center = vec2(-1.6f, -0.35f);
			level = 1;
			hp = 100.0f;
			mp = 100.0f;
			exp = 0.0f;
			str_name = new DrawString(name, 0.0f, -0.75f, true);
			recovery_timer.start();
			shot_timer.start();
		}
		virtual ~Character()
		{
			//std::cout << "Character Destructor" << std::endl;
			if(characterdot != nullptr) delete characterdot;
			if (str_name != nullptr) delete str_name;
		}

	//function
	public:
		void process(float left_size, float right_size);
		void move();
		void draw();
		void jump();
		void shot();
		void attack_start();
	};

	class Mage : public Character
	{
	public:
		Mage(vec2 &in_center)
		{
			//std::cout << "Mage Constructer" << std::endl;
			characterdot = new MageDot(CHARACTER_X_SIZE, CHARACTER_Y_SIZE);
			center = in_center;
		}
		virtual ~Mage()
		{
			//std::cout << "Mage Destructor" << std::endl;
		}
	};
}

#endif