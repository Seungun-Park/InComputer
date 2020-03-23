#include "fmod.hpp"

#include "MainControl.h"
#include <conio.h>
#include <iostream>

#pragma comment(linker, "/subsystem:\"windows\"\ /entry:\"mainCRTStartup\"")

int main(void)
{
	FMOD::System     *system(nullptr);
	FMOD::Sound      *sound1(nullptr);
	FMOD::Channel    *channel1(nullptr);
	FMOD::Sound      *sound2(nullptr);
	FMOD::Channel    *channel2(nullptr);
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata(nullptr);

	result = FMOD::System_Create(&system);
	if (result != FMOD_OK) return -1;

	result = system->getVersion(&version);
	if (result != FMOD_OK) return -1;

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	if (result != FMOD_OK) return -1;

	//result = system->createSound("singing.wav", FMOD_LOOP_NORMAL, 0, &sound);
	result = system->createSound("Sound/Maplestory_Erev.mp3", FMOD_LOOP_NORMAL, 0, &sound1); // .mp3 files work!
	if (result != FMOD_OK) return -1;

	result = system->playSound(sound1, 0, true, &channel1);
	if (result != FMOD_OK) return -1;

	result = system->createSound("Sound/Trueffect.mp3", FMOD_LOOP_NORMAL, 0, &sound2); // .mp3 files work!
	if (result != FMOD_OK) return -1;

	result = system->playSound(sound2, 0, true, &channel2);
	if (result != FMOD_OK) return -1;

	{
		su::MainControl(channel1, channel2).run();
	}
	
	channel1->stop();
	channel2->stop();

	std::cout << "all clear" << std::endl;
	//fflush(stdin);
	//_getch();
	return 0;
}
