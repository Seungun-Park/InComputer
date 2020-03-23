#include "NPC.h"

void su::NPC::process(Character *character)
{
	draw();
}

void su::NPC::draw()
{
	beginTransformation();
	{
		translate(pos);
		npcdot->drawDot();
	}
	endTransformation();
}

std::list<su::Dialogue> su::NPC::space_check(Character *character)
{
	list<Dialogue> tmp;
	return tmp;
}

void su::CPU::process(Character *character)
{
	draw();
	if(quest==0)LoopScript(vec2(pos.x,pos.y+(CHARACTER_Y_SIZE/2)), "space");
	if(quest==1&&character->quest[0]==2)LoopScript(vec2(pos.x, pos.y + (CHARACTER_Y_SIZE / 2)), "space");
}

std::list<su::Dialogue> su::CPU::space_check(Character *character)
{
	list<Dialogue> tmp;
	if ((pos - (character->center)).getMagnitude() < CHARACTER_X_SIZE)
	{
		if (quest == 0)
		{
			tmp.push_back(Dialogue(Name, "HELLO!", "My name is CPU."));
			tmp.push_back(Dialogue(character->name, "h...hello."));
			tmp.push_back(Dialogue(Name, "You can jump by pressing alt key.", "you can attack by pressing ctrl key."));
			tmp.push_back(Dialogue(Name, "Hunt a gold box.", "then come back to me."));
			character->quest[0] = 1;
			quest = 1;
		}
		else if (quest == 1 && character->quest[0] == 1)
		{
			tmp.push_back(Dialogue(Name, "Go!"));
			tmp.push_back(Dialogue(Name, "Hunt a gold box!"));
		}
		else if (quest == 1 && character->quest[0] == 2)
		{
			tmp.push_back(Dialogue(Name, "good job!", "do you like gold?"));
			tmp.push_back(Dialogue(character->name, "huh?"));
			tmp.push_back(Dialogue(Name, "haha. just joke.", "I give you some gold"));
			tmp.push_back(Dialogue(Name, "Now Go straight to the Right.", "And meet register."));
			quest = 2;
		}
		else if (quest == 2)
		{
			tmp.push_back(Dialogue(Name, "Go straight to the Right.", "And meet register."));
		}
	}
	return tmp;
}

void su::Register::process(Character *character)
{
	draw();
	if(character->quest[0]!=2)LoopScript(vec2(pos.x, pos.y + (CHARACTER_Y_SIZE / 2)), "space");
}

std::list<su::Dialogue> su::Register::space_check(Character *character)
{
	list<Dialogue> tmp;
	if ((pos - (character->center)).getMagnitude() < CHARACTER_X_SIZE)
	{
		if (character->quest[0] != 2)
		{
			tmp.push_back(Dialogue(Name, "Do you know cpu?"));
		}
		if (character->quest[0] == 2 && quest == 0)
		{
			tmp.push_back(Dialogue(Name, "HELLO!", "i am register."));
			tmp.push_back(Dialogue(character->name, "r..register?", "Not the cpu?"));
			tmp.push_back(Dialogue(Name, "yes i am register.", "I do not look like a cpu!"));
			tmp.push_back(Dialogue(character->name, "oh. sorry...", "But I want to ask about..."));
			tmp.push_back(Dialogue(Name, "yes?"));
			tmp.push_back(Dialogue(character->name, "Where is here?"));
			tmp.push_back(Dialogue(Name, "This place is inside the computer.", "boxes are destroying this place."));
			tmp.push_back(Dialogue(Name, "please hunt five blue boxes for me."));
			tmp.push_back(Dialogue(character->name, "what is reward?"));
			tmp.push_back(Dialogue(Name, "gold."));
			tmp.push_back(Dialogue(character->name, "good!"));

			character->quest[1] = 1;
			quest = 1;
		}
		else if (quest == 1 && character->quest[1] >= 1)
		{
			tmp.push_back(Dialogue(Name, "if you hunt five gold boxes", "i will give gold for you"));
		}
	}
	return tmp;
}