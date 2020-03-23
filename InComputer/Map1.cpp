#include "MainControl.h"

void su::MainControl::map1_init()
{
	channel1->setPaused(false);
	Map = 1;
	floor.push_back(new Floor(0.0f, -0.1f, 0.7f, 0.2f));
	floor.push_back(new Floor(4.2f, -0.1f, 2.0f, 0.2f));
	//floor[0].init(0.0f, -0.1f, 0.7f, 0.2f);
	monster.push_back(new Gold_box(-0.3f, 0.3f, 0.00f));
	monster.push_back(new Blue_box(3.4f, 3.9f, 0.00f));
	monster.push_back(new Blue_box(3.6f, 4.6f, 0.00f));
	monster.push_back(new Blue_box(3.4f, 4.6f, 0.00f));
	monster.push_back(new Blue_box(3.7f, 4.6f, -0.4f));
	monster.push_back(new Gold_box(3.4f, 4.8f, -0.4f));
	//monster.begin()->init(-0.3f, 0.3f, 0.00f);
	npclist.push_back(new CPU(vec2(-1.0f, -0.35f)));
	npclist.push_back(new Register(vec2(3.0f, -0.35f)));
	left_size = 1.7f;
	right_size = 5.0f;
}


void su::MainControl::map1()
{
	//move character
	if (isKeyPressed(GLFW_KEY_LEFT) && !isKeyPressed(GLFW_KEY_RIGHT) && dial.empty())
	{
		character->characterdot->x_size = -CHARACTER_X_SIZE;
		if (!(character->fall_state)) character->x_speed = -(CHARACTER_SPEED * getTimeStep());
	}
	else if (isKeyPressed(GLFW_KEY_RIGHT) && !isKeyPressed(GLFW_KEY_LEFT) && dial.empty())
	{
		character->characterdot->x_size = CHARACTER_X_SIZE;
		if (!(character->fall_state)) character->x_speed = CHARACTER_SPEED * getTimeStep();
	}
	else if (!(character->fall_state))
	{
		character->x_speed = 0.0f;
	}
	else if (character->fall_state && !(character->jump_state))
	{
		character->x_speed = 0.0f;
	}

	if (!(character->jump_state) && !(character->fall_state) && isKeyPressed(GLFW_KEY_LEFT_ALT) && dial.empty())
	{
		character->jump();
	}

	if (!(character->attack_state) && (character->mp >= 10) && isKeyPressed(GLFW_KEY_LEFT_CONTROL) && dial.empty())
	{
		character->attack_start();
		character->attack_state = 1;
		character->skill->hitbox();

		//hit_check
		/*for (int i = 0; i < monsterNum; i++)
		{
			monster[i].hitcheck(character);
		}*/
		for (auto &e : monster)
		{
			e->hitcheck(character);
		}
	}
	//Dialogue
	if (isKeyPressedAndReleased(GLFW_KEY_SPACE) && dial.empty())
	{
		for (auto &e : npclist)
		{
			list<Dialogue> tmp = e->space_check(character);
			if(!tmp.empty())	dial = tmp;
		}
	}
	//Dialogue
	if (isKeyPressedAndReleased(GLFW_KEY_ENTER) && !dial.empty())
	{
		dial.pop_front();
	}

	beginTransformation();
	{
		translate(-(character->center));
		//processing
		mainfloor.process(character);
		/*for (int i = 0; i < floorNum; i++)
		{
			floor[i].process(character);
		}*/
		for (auto &e : floor)
		{
			e->process(character);
		}

		/*for (int i = 0; i < monsterNum; i++)
		{
			monster[i].process(character);
		}*/
		for (auto &e : monster)
		{
			e->process(character);
		}
		for (auto &e : npclist)
		{
			e->process(character);
		}
	}
	endTransformation();

	character->process(left_size, right_size);
	//minimap->process();

	if (!dial.empty()) dial.begin()->draw();

	if (character->quest[1] >= 4)
	{
		map2_init();
	}
}

