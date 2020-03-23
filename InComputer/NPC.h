#ifndef __NPC_H__
#define __NPC_H__

#include "Game2D.h"
#include "Character.h"
#include "Dialogue.h"
#include "DrawNPC.h"
#include <list>


namespace su
{
	class NPC
	{
	protected:
		int quest = 0;
		string Name;
		vec2 pos;
		NPCDot * npcdot = nullptr;

	public:
		NPC() {};
		~NPC()
		{
			if (npcdot != nullptr) delete npcdot;
		};

		virtual void process(Character *character);
		void draw();
		virtual std::list<su::Dialogue> space_check(Character *character);
	};

	//CPU
	class CPU : public NPC
	{
	public:
		CPU(vec2 &&center)
		{
			quest = 0;
			Name = "CPU";
			pos = center;
			npcdot = new NPCDot(CHARACTER_X_SIZE, CHARACTER_Y_SIZE);
		}

	public:
		void process(Character *character) override;
		virtual std::list<su::Dialogue> space_check(Character *character) override;
	};

	//CPU
	class Register : public NPC
	{
	public:
		Register(vec2 &&center)
		{
			quest = 0;
			Name = "register";
			pos = center;
			npcdot = new NPCDot(CHARACTER_X_SIZE, CHARACTER_Y_SIZE);
		}

	public:
		void process(Character *character) override;
		virtual std::list<su::Dialogue> space_check(Character *character) override;
	};
}

#endif