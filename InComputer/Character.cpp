#include "Character.h"

void su::Character::process(float left_size, float right_size)
{
	//top scale check
	if (center.y >= 1.0f)
	{
		y_speed = 0.0f;
		center.y -= 0.01f;
	}
	//left right scale check
	if (center.x >= right_size)
	{
		x_speed = 0.0f;
		center.x -= 0.01f;
	}
	if (center.x <= -left_size)
	{
		x_speed = 0.0f;
		center.x += 0.01f;
	}

	//level up
	if (exp >= max_exp)
	{
		level++;
		exp -= max_exp;
		front_demage += 10;
		back_demage += 10;
		max_hp += 20*level;
		max_mp += 20*level;
		max_exp += 50;
		str_timer.reset();
	}

	if (str_timer.stopAndGetElapsedMilli() < 3000 && level>1)
	{
		DrawString("LEVEL UP", 0.0f, y_size * 2 / 3, true).draw();
	}

	if (recovery_timer.stopAndGetElapsedMilli() > 1000)
	{
		hp += recovery_hp;
		mp += recovery_mp;
		if (hp > max_hp) hp = max_hp;
		if (mp > max_hp) mp = max_mp;
		recovery_timer.reset();
	}

	move();
	draw();

	//skill
	if (attack_state == 1)
	{
		skill->center.x = center.x;
		skill->center.y = center.y;
		if (skill->process())
		{
			attack_state = 2;
			if (skill != nullptr)
			{
				delete skill;
				skill = nullptr;
			}
		}
	}
	else if (attack_state == 2 && time.stopAndGetElapsedMilli() > 500)
	{
		attack_state = 0;
	}
}

void su::Character::draw()
{
	
	beginTransformation();
	{
		characterdot->drawDot();
	}
	endTransformation();

	//draw bar
	beginTransformation();
	{
		translate(0.0f, -0.85f);
		drawFilledBox(Colors::skyblue, 0.8f, 0.3f);
	}
	endTransformation();

	str_name->draw();

	//draw hp bar
	setLineWidth(20.0f);
	drawLine(Colors::red, vec2(-0.35f, -0.83f), Colors::red, vec2(-0.35f + 0.7f * hp/max_hp, -0.83f));

	//draw mp bar
	setLineWidth(20.0f);
	drawLine(Colors::blue, vec2(-0.35f, -0.9f), Colors::blue, vec2(-0.35f + 0.7f * mp / max_mp, -0.9f));

	//draw exp bar
	setLineWidth(20.0f);
	drawLine(Colors::yellow, vec2(-0.35f, -0.97f), Colors::yellow, vec2(-0.35f + 0.7f * exp / max_exp, -0.97f));
}

void su::Character::move()
{
	if ((!attack_state) || ((attack_state) && (jump_state)))
	{
		center.x += x_speed;
	}
	if (fall_state)
	{
		center.y += y_speed * Game2D().getTimeStep();
		y_speed -= GRAVITY * Game2D().getTimeStep();
	}
}

void su::Character::jump()
{
	if (!jump_state)
	{
		center.y += 0.02f;
		y_speed = JUMP_SPEED;
		fall_state = 1;
		jump_state = 1;
	}
}

void su::Character::attack_start()
{
	demage = rand.getFloat(front_demage, back_demage);
	time.start();
	skill = new Attack(center.x, center.y);
	mp -= 10.0f;
	if (characterdot->x_size < 0)
	{
		skill->direction = 0;
		if (skill->skilldot->x_size > 0) skill->skilldot->x_size = -skill->skilldot->x_size;
		skill->degree = -90.0f;
	}
	else
	{
		skill->direction = 1;
		if (skill->skilldot->x_size < 0) skill->skilldot->x_size = -skill->skilldot->x_size;
		skill->degree = 90.0f;
	}
}

void su::Character::shot()
{
	if (shot_timer.stopAndGetElapsedMilli() > 2000)
	{
		hp -= 20;
		shot_timer.reset();
	}
}