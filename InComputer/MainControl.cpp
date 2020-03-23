#include "MainControl.h"

void su::MainControl::update()
{
	switch (Map)
	{
	case -1:map_die(); break;
	case 0: map0(); break;
	case 1: map1(); break;
	case 2: map2(); break;
	case 3: map3(); break;
	case 4: map4(); break;
	case 5: map5(); break;
	}
	if (character->hp <= 0)
	{
		Map = -1;
	}
}

char su::MainControl::KeyCheck()
{
	if (isKeyPressedAndReleased(GLFW_KEY_A)) return 'A';
	if (isKeyPressedAndReleased(GLFW_KEY_B)) return 'B';
	if (isKeyPressedAndReleased(GLFW_KEY_C)) return 'C';
	if (isKeyPressedAndReleased(GLFW_KEY_D)) return 'D';
	if (isKeyPressedAndReleased(GLFW_KEY_E)) return 'E';
	if (isKeyPressedAndReleased(GLFW_KEY_F)) return 'F';
	if (isKeyPressedAndReleased(GLFW_KEY_G)) return 'G';
	if (isKeyPressedAndReleased(GLFW_KEY_H)) return 'H';
	if (isKeyPressedAndReleased(GLFW_KEY_I)) return 'I';
	if (isKeyPressedAndReleased(GLFW_KEY_J)) return 'J';
	if (isKeyPressedAndReleased(GLFW_KEY_K)) return 'K';
	if (isKeyPressedAndReleased(GLFW_KEY_L)) return 'L';
	if (isKeyPressedAndReleased(GLFW_KEY_M)) return 'M';
	if (isKeyPressedAndReleased(GLFW_KEY_N)) return 'N';
	if (isKeyPressedAndReleased(GLFW_KEY_O)) return 'O';
	if (isKeyPressedAndReleased(GLFW_KEY_P)) return 'P';
	if (isKeyPressedAndReleased(GLFW_KEY_Q)) return 'Q';
	if (isKeyPressedAndReleased(GLFW_KEY_R)) return 'R';
	if (isKeyPressedAndReleased(GLFW_KEY_S)) return 'S';
	if (isKeyPressedAndReleased(GLFW_KEY_T)) return 'T';
	if (isKeyPressedAndReleased(GLFW_KEY_U)) return 'U';
	if (isKeyPressedAndReleased(GLFW_KEY_V)) return 'V';
	if (isKeyPressedAndReleased(GLFW_KEY_W)) return 'W';
	if (isKeyPressedAndReleased(GLFW_KEY_X)) return 'X';
	if (isKeyPressedAndReleased(GLFW_KEY_Y)) return 'Y';
	if (isKeyPressedAndReleased(GLFW_KEY_Z)) return 'Z';
	return 0;
}

