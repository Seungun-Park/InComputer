#include "MainControl.h"

void su::MainControl::map_die()
{
	channel1->setPaused(true);
	beginTransformation();
	{
		translate(0.0f, 0.0f);
		drawFilledBox(Colors::skyblue, 4.0f, 2.0f);
		drawFilledBox(Colors::hotpink, 1.0f, 0.6f);
	}
	endTransformation();
	DrawString("you died", 0.0f, 0.6f, 0.1f, true).draw();
	DrawString("sorry...", 0.0f, 0.2f, true).draw();
	beginTransformation();
	{
		translate(0.0f, -0.17f);
		drawFilledBox(Colors::green, 0.4f, 0.17f);
		translate(0.0f, +0.19f);
		drawFilledBox(Colors::green, 0.4f, 0.17f);
	}
	endTransformation();
	DrawString("revive", 0.0, 0.02f, true).draw();
	DrawString("exit", 0.0, -0.17f, true).draw();

	if (isMouseButtonPressedAndReleased(GLFW_MOUSE_BUTTON_LEFT))
	{
		if (getCursorPos(true).x > -0.2f && getCursorPos(true).x < 0.2f && getCursorPos(true).y > -0.065f && getCursorPos(true).y < 0.105f)
		{
			channel1->setPaused(false);
			character->hp = 10;
			character->center = vec2(-1.6f, -0.35f);
			Map = 1;
		}
		if (getCursorPos(true).x > -0.2f && getCursorPos(true).x < 0.2f && getCursorPos(true).y > -0.255f && getCursorPos(true).y < -0.085f)
		{
			exit(1);
		}
	}
}