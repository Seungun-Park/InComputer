#ifndef __MAINCONTROL_H__
#define __MAINCONTROL_H__

#include "fmod.hpp"
#include "Game2D.h"
#include "Character.h"
#include "Floor.h"
#include "Minimap.h"
#include "Monster.h"
#include "DrawAlphabet.h"
#include "Dialogue.h"
#include "NPC.h"
#include <list>
#include <vector>

namespace su
{
	using namespace jm;
	class MainControl : public Game2D
	{
		float time = 0.0f;

	//object create
	private:
		char Keytmp = 0;
		float left_size = 1.7f;
		float right_size = 1.7f;
		int Map = 0;
		enum JOB {none, mage, warrior};
		JOB job;
		Character * character;
		MainFloor mainfloor;
		list<Floor*> floor;
		//Minimap *minimap;
		list<Monster *> monster;
		string nametmp;
		FMOD::Channel *channel1, *channel2;
		list<NPC*> npclist;
		list<Dialogue> dial;

	public:
		MainControl(FMOD::Channel *channel1, FMOD::Channel *channel2)
			: Game2D("InComputer", 1366, 768, false), job(none), channel1(channel1), channel2(channel2)
		{
			character = new Character(0);
			mainfloor.center = vec2(0.0f, -0.5f);
			//minimap = new Minimap;
			nametmp = "";
		}
		~MainControl()
		{
			if (character != nullptr) delete character;
			//if (minimap != nullptr) delete minimap;
			//if (floor != nullptr) delete[] floor;
			//if (monster != nullptr) delete[] monster;
		}

		void update() override;
		void map1_init();
		void map1();
		void map0();
		void map2_init();
		void map2();
		void map3_init();
		void map3();
		void map4();
		void map4_init();
		void map5();
		void map_die();
		char KeyCheck();
	};
}

#endif