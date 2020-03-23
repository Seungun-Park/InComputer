#include "Skill.h"

bool su::Skill::process()
{
	draw();
	return 0;
}

bool su::Skill::draw()
{
	beginTransformation();
	{
		translate(center);
		skilldot->drawDot();
	}
	endTransformation();
	return 0;
}

void su::Skill::hitbox()
{

}

bool su::Attack::process()
{
	return draw();
}

bool su::Attack::draw()
{
	beginTransformation();
	{
		rotate(degree);
		skilldot->drawDot();
	}
	endTransformation();

	if (direction)
	{
		degree -= 2.0f;
		if (degree == -90.0f) return 1;
	}
	else
	{
		degree += 2.0f;
		if (degree == 90.0f) return 1;
	}
	return 0;
}

void su::Attack::hitbox()
{
	if (direction)
	{
		hit[0] = vec2(center.x, center.y + (skilldot->y_size / 2.0f));
		hit[1] = vec2(center.x + (skilldot->x_size / 2.0f), center.y + (skilldot->y_size / 2.0f));
		hit[2] = vec2(center.x, center.y - (skilldot->y_size / 2.0f));
		hit[3] = vec2(center.x + (skilldot->x_size / 2.0f), center.y - (skilldot->y_size / 2.0f));
	}
	else
	{
		hit[0] = vec2(center.x + (skilldot->x_size / 2.0f), center.y + (skilldot->y_size / 2.0f));
		hit[1] = vec2(center.x, center.y + (skilldot->y_size / 2.0f));
		hit[2] = vec2(center.x +(skilldot->x_size / 2.0f), center.y - (skilldot->y_size / 2.0f));
		hit[3] = vec2(center.x, center.y - (skilldot->y_size / 2.0f));
	}
}