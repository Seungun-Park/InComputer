#include "MainControl.h"

void su::MainControl::map2_init()
{
	channel1->setPaused(true);
	channel2->setPaused(false);
	dial.push_back(Dialogue("???", "son..."));
	dial.push_back(Dialogue(character->name, "?!"));
	dial.push_back(Dialogue("???", "Why do you kill your brothers?"));
	dial.push_back(Dialogue(character->name, "what?"));
	dial.push_back(Dialogue("???", "you are a box!", "Remember!"));
	dial.push_back(Dialogue(character->name, "huh?!"));

	Map = 2;
}

void su::MainControl::map2()
{
	beginTransformation();
	{
		translate(0.0f, 0.0f);
		drawFilledBox(Colors::black, 4.0f, 2.0f);
	}
	endTransformation();

	if (isKeyPressedAndReleased(GLFW_KEY_ENTER) && !dial.empty())
	{
		dial.pop_front();
	}

	if (!dial.empty()) dial.begin()->draw();

	if (dial.empty()) map3_init();
}