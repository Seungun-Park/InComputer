#include "MainControl.h"

void su::MainControl::map0()
{
	beginTransformation();
	{
		translate(0.0f, 0.0f);
		drawFilledBox(Colors::skyblue, 4.0f, 2.0f);
		drawFilledBox(Colors::hotpink, 1.0f, 0.6f);
	}
	endTransformation();
	DrawString("InComputer", 0.0f, 0.6f, 0.1f, true).draw();
	DrawString("Write your name", 0.0f, 0.2f, true).draw();
	if (nametmp != "")
	{
		DrawString(nametmp, -0.18f, 0.0f).draw();
		if (isKeyPressedAndReleased(GLFW_KEY_BACKSPACE)) nametmp.pop_back();
	}
	beginTransformation();
	{
		translate(0.0f, -0.17f);
		drawFilledBox(Colors::green, 0.4f, 0.17f);
	}
	endTransformation();
	DrawString("OK", 0.0, -0.17f, true).draw();

	Keytmp = KeyCheck();
	if (nametmp.length() < 10 && Keytmp)
	{
		nametmp += Keytmp;
	}

	if (isMouseButtonPressedAndReleased(GLFW_MOUSE_BUTTON_LEFT))
	{
		if (getCursorPos(true).x > -0.2f && getCursorPos(true).x < 0.2f && getCursorPos(true).y > -0.255f && getCursorPos(true).y < -0.085f)
		{
			if (nametmp != "")
			{
				if (character->str_name != nullptr) delete character->str_name;
				character->name = nametmp;
				character->str_name = new DrawString(nametmp, 0.0f, -0.75f, true);
			}
			map1_init();
		}
	}
}