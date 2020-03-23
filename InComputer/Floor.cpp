#include "Floor.h"


//Floor Function

void su::Floor::init(float x, float y, float size_x, float size_y)
{
	center.x = x;
	center.y = y;
	x_size = size_x;
	y_size = size_y;
	floordot = new FloorDot(size_x, size_y);
}

void su::Floor::process(Character *character)
{
	draw();
	fall_check(character);
	collision_check(character);
}

void su::Floor::draw()
{
	beginTransformation();
	{
		translate(center);
		if(floordot!=nullptr)floordot->drawDot();
	}
	endTransformation();
}

void su::Floor::fall_check(Character *character)
{
	if ((character->fall_state) && ((character->center.y - character->y_size / 2.0f) <= center.y) && ((character->center.y - character->y_size / 2.0f) >= center.y- 0.02f)
		&& (character->center.x > center.x - (x_size / 2.0f + CHARACTER_X_SIZE / 2.0f)) && (character->center.x < center.x + (x_size / 2.0f + CHARACTER_X_SIZE / 2.0f)) && character->y_speed<0)
	{
		character->center.y = (character->y_size / 2.0f) + center.y;
		character->fall_state = 0;
		character->y_speed = 0;
		if (character->jump_state) character->jump_state = 0;
		collision = 1;
	}
}

void su::Floor::collision_check(Character *character)
{
	if (collision && ((character->center.x < center.x - (x_size / 2.0f + CHARACTER_X_SIZE / 2.0f)) || (character->center.x > center.x + (x_size / 2.0f + CHARACTER_X_SIZE / 2.0f))))
	{
		character->fall_state = 1;
		collision = 0;
	}
}



//MainFloor Function

void su::MainFloor::fall_check(Character *character)
{
	if ((character->fall_state) && ((character->center.y - character->y_size / 2.0f) <= center.y) && (character->center.x>center.x - MAINFLOOR_SIZE / 2.0f)
		&& (character->center.x<center.x + MAINFLOOR_SIZE / 2.0f))
	{
		character->center.y = (character->y_size / 2.0f) + center.y;
		character->fall_state = 0;
		if (character->jump_state) character->jump_state = 0;
	}
}