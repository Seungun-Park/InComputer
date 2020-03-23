#ifndef __DIALOGUE_H__
#define __DIALOGUE_H__

#include "Game2D.h"
#include "DrawAlphabet.h"

namespace su {
	using namespace jm;
	using namespace std;

	class Dialogue
	{
	protected:
		string Name, Script1, Script2, Script3, Script4;

	public:
		Dialogue() {};
		Dialogue(const string& name, const string& script1, const string& script2 = "", const string& script3 = "", const string& script4 = "")
			:Name(name), Script1(script1), Script2(script2), Script3(script3), Script4(script4)
		{}

		virtual void draw()
		{
			beginTransformation();
			{
				translate(0.0f, -0.7f);
				drawFilledBox(Colors::white, 1.6f, 0.5f);
				setLineWidth(3.0f);
				drawWiredBox(Colors::blue, 1.6f, 0.5f);
				translate(-0.65f, +0.25f);
				drawFilledBox(Colors::white, 0.4f, 0.1f);
				drawWiredBox(Colors::red, 0.4f, 0.1f);
			}
			endTransformation();
			DrawString(Name, -0.65f, -0.45f, true).draw();
			DrawString(Script1, -0.7f, -0.55f, false).draw();
			DrawString(Script2, -0.7f, -0.62f, false).draw();
			DrawString(Script3, -0.7f, -0.69f, false).draw();
			DrawString(Script4, -0.7f, -0.76f, false).draw();
			DrawString("Enter", 0.68f, -0.9f, true).draw();
		}
	};

	class LoopScript
	{
	private:
		string Script;
		vec2 Pos;

	public:
		LoopScript(vec2&& pos, const string& script)
			:Pos(pos), Script(script)
		{
			beginTransformation();
			{
				translate(Pos.x, Pos.y + 0.1f);
				rotate(180);
				setLineWidth(1.0f);
				drawFilledTriangle(Colors::white, 0.1f);
				drawWiredTriangle(Colors::black, 0.1f);
			}
			endTransformation();
			beginTransformation();
			{
				translate(Pos.x, Pos.y+0.2f);
				setLineWidth(1.0f);
				drawFilledBox(Colors::white, 0.4f, 0.2f);
				drawWiredBox(Colors::black, 0.4f, 0.2f);
				translate(0.0f, -0.1f);
				drawFilledBox(Colors::white, 0.075f, 0.005f);
			}
			endTransformation();
			DrawString(Script, Pos.x, Pos.y+0.2f, true).draw();
		}
		LoopScript(vec2& pos, const string& script)
			:Pos(pos), Script(script)
		{
			beginTransformation();
			{
				translate(Pos.x, Pos.y + 0.1f);
				rotate(180);
				setLineWidth(1.0f);
				drawFilledTriangle(Colors::white, 0.1f);
				drawWiredTriangle(Colors::black, 0.1f);
			}
			endTransformation();
			beginTransformation();
			{
				translate(Pos.x, Pos.y + 0.2f);
				setLineWidth(1.0f);
				drawFilledBox(Colors::white, 0.4f, 0.2f);
				drawWiredBox(Colors::black, 0.4f, 0.2f);
				translate(0.0f, -0.1f);
				drawFilledBox(Colors::white, 0.075f, 0.005f);
			}
			endTransformation();
			DrawString(Script, Pos.x, Pos.y + 0.2f, true).draw();
		}
	};
}

#endif