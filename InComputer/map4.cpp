#include "MainControl.h"

void su::MainControl::map4_init()
{
	channel1->setPaused(false);
	channel2->setPaused(true);
	dial.push_back(Dialogue("???", "How did you know it was a lie?"));
	dial.push_back(Dialogue(character->name, "No one is fooled by that."));
	dial.push_back(Dialogue("Cpu", "Thank you for saving us!"));
	dial.push_back(Dialogue("register", "you are our hero!"));
	dial.push_back(Dialogue(character->name, "huh?!"));
	Map = 4;
}

void su::MainControl::map4()
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

	if (dial.empty()) Map=5;
}