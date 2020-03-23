#include "Monster.h"

void su::Monster::init(const float &x_left, const float &x_right, const float &y_base)
{
	hp = max_hp;
	left_x = x_left;
	right_x = x_right;
	base_y = y_base;
	center = vec2(((x_left + x_right) / 2.0f), y_base);
	monsterdot = new MonsterDot(0.2f, 0.2f);
	time3.start();
}

void su::Monster::process(Character *character)
{
	if (state)
	{
		move();
		draw();
		charhit(character);
	}
	else if(time.stopAndGetElapsedMilli() > 7000)
	{
		state = 1;
		center.x = rand.getFloat(left_x,right_x);
		hp = max_hp;
	}
}

void su::Monster::move()
{
	if (move_state)
	{
		if (move_direction)
		{
			if (center.x <= right_x)
			{
				center.x += speed * Game2D().getTimeStep();
			}
			else
			{
				move_direction = 0;
			}
		}
		else
		{
			if (center.x >= left_x)
			{
				center.x -= speed * Game2D().getTimeStep();
			}
			else
			{
				move_direction = 1;
			}
		}
	}
	else if (time2.stopAndGetElapsedMilli() > 500)
	{
		move_state = 1;
	}
}

void su::Monster::draw()
{
	beginTransformation();
	{
		translate(center);
		monsterdot->drawDot();
	}
	endTransformation();
	setLineWidth(7.0f);
	drawLine(Colors::red, vec2(center.x - monsterdot->x_size / 2.0f, center.y + monsterdot->y_size / 2.0f + 0.018f),
		Colors::red, vec2(center.x - monsterdot->x_size/2.0f + hp/max_hp*monsterdot->x_size, center.y + monsterdot->y_size / 2.0f + 0.018f));
}

void su::Monster::hitcheck(Character *character)
{
	bool shot = 0;
	if (state)
	{
		//몹이 공격 내부에
		if ((character->skill->hit[0].x < center.x - monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}
		if ((character->skill->hit[0].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x + monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}

		// 공격이 몹 내부에
		if ((character->skill->hit[1].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}
		if ((character->skill->hit[0].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[0].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}


		if (shot)
		{
			if (character->skill->direction && center.x < right_x)
			{
				center.x += 0.05f;
			}
			else if(!(character->skill->direction) && center.x>left_x)
			{
				center.x -= 0.05f;
			}
			hp -= character->demage * character->skill->dem_per;
			move_state = 0;
			time2.start();
			if (hp <= 0)
			{
				state = 0;
				character->exp += 60.0f;
				time.start();
			}
		}

	}
}

void su::Gold_box::hitcheck(Character *character)
{
	bool shot = 0;
	if (state)
	{
		//몹이 공격 내부에
		if ((character->skill->hit[0].x < center.x - monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}
		if ((character->skill->hit[0].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x + monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}

		// 공격이 몹 내부에
		if ((character->skill->hit[1].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}
		if ((character->skill->hit[0].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[0].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}


		if (shot)
		{
			if (character->skill->direction && center.x < right_x)
			{
				center.x += 0.05f;
			}
			else if (!(character->skill->direction) && center.x>left_x)
			{
				center.x -= 0.05f;
			}
			hp -= character->demage * character->skill->dem_per;
			move_state = 0;
			time2.start();
			if (hp <= 0)
			{
				state = 0;
				character->exp += 60.0f;
				if (character->quest[0] == 1) character->quest[0] = 2;
				time.start();
			}
		}

	}
}

void su::Blue_box::hitcheck(Character *character)
{
	bool shot = 0;
	if (state)
	{
		//몹이 공격 내부에
		if ((character->skill->hit[0].x < center.x - monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}
		if ((character->skill->hit[0].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x + monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}

		// 공격이 몹 내부에
		if ((character->skill->hit[1].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}
		if ((character->skill->hit[0].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[0].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}


		if (shot)
		{
			if (character->skill->direction && center.x < right_x)
			{
				center.x += 0.05f;
			}
			else if (!(character->skill->direction) && center.x>left_x)
			{
				center.x -= 0.05f;
			}
			hp -= character->demage * character->skill->dem_per;
			move_state = 0;
			time2.start();
			if (hp <= 0)
			{
				state = 0;
				character->exp += 60.0f;
				if (character->quest[1] >= 1) character->quest[1]++;
				time.start();
			}
		}

	}
}

void su::Black_box::hitcheck(Character *character)
{
	bool shot = 0;
	if (state)
	{
		//몹이 공격 내부에
		if ((character->skill->hit[0].x < center.x - monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}
		if ((character->skill->hit[0].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x + monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}

		// 공격이 몹 내부에
		if ((character->skill->hit[1].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[1].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}
		if ((character->skill->hit[0].x < center.x + monsterdot->x_size / 2.0f) && (character->skill->hit[0].x > center.x - monsterdot->x_size / 2.0f))
		{
			if ((character->skill->hit[0].y > center.y - monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y - monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
			else if ((character->skill->hit[0].y > center.y + monsterdot->y_size / 2.0f) && (character->skill->hit[3].y < center.y + monsterdot->y_size / 2.0f))
			{
				shot = 1;
			}
		}


		if (shot)
		{
			hp -= character->demage * character->skill->dem_per;
			time2.start();
			if (hp <= 0)
			{
				state = 0;
				character->exp += 60.0f;
				character->quest[2] = 1;
				time.start();
			}
		}

	}
}

void su::Monster::charhit(Character *character)
{
	bool shot = 0;
	if (character->center.x + CHARACTER_X_SIZE > center.x && character->center.x - CHARACTER_X_SIZE<center.x && character->center.y + CHARACTER_X_SIZE >center.y && character->center.y - CHARACTER_X_SIZE < center.y)
	{
		character->shot();
	}
}







void su::Gold_box::init(const float &x_left, const float &x_right, const float &y_base)
{
	hp = max_hp;
	left_x = x_left;
	right_x = x_right;
	base_y = y_base;
	center = vec2(((x_left + x_right) / 2.0f), y_base);
	monsterdot = new Gold_box_dot(0.2f, 0.2f);
	time3.start();
}

void su::Blue_box::init(const float &x_left, const float &x_right, const float &y_base)
{
	hp = max_hp;
	left_x = x_left;
	right_x = x_right;
	base_y = y_base;
	center = vec2(((x_left + x_right) / 2.0f), y_base);
	monsterdot = new Blue_box_dot(0.2f, 0.2f);
	time3.start();
}

void su::Black_box::init(const float &x_left, const float &x_right, const float &y_base)
{
	hp = max_hp;
	left_x = x_left;
	right_x = x_right;
	base_y = y_base;
	center = vec2(((x_left + x_right) / 2.0f), y_base);
	monsterdot = new Black_box_dot(0.2f, 0.2f);
	time3.start();
}