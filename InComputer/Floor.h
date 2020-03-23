#ifndef __FLOOR_H__
#define __FLOOR_H__

#include "Game2D.h"
#include "Character.h"
#include "FloorDot.h"

namespace su
{
	using namespace jm;

	class Floor
	{
	public:
		FloorDot * floordot = nullptr;

	//value
	public:
		bool collision = 0;
		vec2 center = vec2(0.0f, 0.0f);
		float x_size, y_size;

	public:
		Floor()
		{
			//std::cout << "Floor Default Constructer" << std::endl;
			x_size = 0.5f;
			y_size = 0.5f;
			
		};
		Floor(float x, float y, float size_x, float size_y)
		{
			init(x, y, size_x, size_y);
		}
		virtual ~Floor()
		{
			//std::cout << "Floor Destructor" << std::endl;
			if (floordot != nullptr) delete floordot;
		}

		//function
	public:
		void process(Character *character);
		void init(float x, float y, float size_x, float size_y);
		void draw();
		virtual void fall_check(Character *character);
		void collision_check(Character *character);
	};

	class MainFloor : public Floor
	{
	public:
		MainFloor()
		{
			//std::cout << "Floor Default Constructer" << std::endl;
			floordot = new FloorDot(MAINFLOOR_SIZE, CHARACTER_Y_SIZE);
		};
		virtual ~MainFloor()
		{
			//std::cout << "Floor Destructor" << std::endl;
		}

		void fall_check(Character *character) override;
	};
}

#endif