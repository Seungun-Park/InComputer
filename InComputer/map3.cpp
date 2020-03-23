#include "MainControl.h"

void su::MainControl::map3_init()
{
	channel1->setPaused(true);
	channel2->setPaused(false);
	while (!floor.empty()) floor.pop_back();
	floor.push_back(new Floor(0.0f, -0.1f, 0.7f, 0.2f));
	floor.push_back(new Floor(4.2f, -0.1f, 2.0f, 0.2f));
	//floor[0].init(0.0f, -0.1f, 0.7f, 0.2f);
	while (!monster.empty()) monster.pop_back();
	monster.push_back(new Black_box(-1.7f, 5.0f, 0.00f));
	while (!npclist.empty()) npclist.pop_back();
	Map = 3;
}

void su::MainControl::map3()
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
			if (!tmp.empty())	dial = tmp;
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
	}
	endTransformation();

	character->process(left_size, right_size);
	//minimap->process();

	if (!dial.empty()) dial.begin()->draw();

	if (character->quest[2] == 1) map4_init();
}