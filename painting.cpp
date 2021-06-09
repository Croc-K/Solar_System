#include <SFML\Graphics.hpp>
#include <iostream>

#include "sprite_text.cpp"

using namespace sf;

class CirclePainting {
private:
	Circle Sun, Mercury, Earth, Venus, Mars, Jupiter, Saturn, Uranus, Neptune, Pluton;
	float spead, scale, x, y, x0, y0;

	void painting(RenderWindow& window, Circle& a, float t)
	{
		a.update(t);
		window.draw(a.c());
		window.draw(a.sprite);
		window.draw(a.name);
	}

	void basis()
	{
		Sun.parameters("sprite\\Sun.png", x, y, x0, y0, 0, 0, "Сонце");
		Mercury.parameters("sprite\\Mercury.png", 0, 0, x0, y0, (57.89 / scale) + 40 + 20, 47.9 / spead, "Меркурій");
		Venus.parameters("sprite\\Venus.png", 0, 0, x0, y0, (108.16 / scale) + 40 + 50, 35.0 / spead, "Венера");
		Earth.parameters("sprite\\Earth.png", 0, 0, x0, y0, (149.6 / scale) + 40 + 70, 29.8 / spead, "Земля");
		Mars.parameters("sprite\\Mars.png", 0, 0, x0, y0, (227.99 / scale) + 40 + 90, 24.1 / spead, "Марс");
		Jupiter.parameters("sprite\\Jupiter.png", 0, 0, x0, y0, (778.36 / scale + 180) + 40, 13.1 / spead, "Юпітер");
		Saturn.parameters("sprite\\Saturn.png", 0, 0, x0, y0, (1427.01 / scale + 180) + 40, 9.6 / spead, "Сатурн");
		Uranus.parameters("sprite\\Uranus.png", 0, 0, x0, y0, (2875.27 / scale + 80) + 40, 6.8 / spead, "Уран");
		Neptune.parameters("sprite\\Neptune.png", 0, 0, x0, y0, (4504.39 / scale - 30) + 40, 5.4 / spead, "Нептун");
		Pluton.parameters("sprite\\Pluton.png", 0, 0, x0, y0, (5900.14 / scale - 130) + 40, 4.7 / spead, "Плутон");
	}
public:
	void parametr(float x_, float y_, float x0_, float y0_, float scale_, float spead_)
	{
		x = x_;
		y = y_;
		x0 = x0_;
		y0 = y0_;
		scale = scale_;
		spead = spead_;
		basis();
	}
	Sprite prSprite(int v)
	{
		switch (v)
		{
		case 0:
			return Sun.sprite;
		case 1:
			return Mercury.sprite;
		case 2:
			return Venus.sprite;
		case 3:
			return Earth.sprite;
		case 4:
			return Mars.sprite;
		case 5:
			return Jupiter.sprite;
		case 6:
			return Saturn.sprite;
		case 7:
			return Uranus.sprite;
		case 8:
			return Neptune.sprite;
		case 9:
			return Pluton.sprite;
		default:
			break;
		}
	}
	void paint(RenderWindow& window, float time)
	{
		painting(window, Sun, time);
		painting(window, Mercury, time);
		painting(window, Venus, time);
		painting(window, Earth, time);
		painting(window, Mars, time);
		painting(window, Jupiter, time);
		painting(window, Saturn, time);
		painting(window, Uranus, time);
		painting(window, Neptune, time);
		painting(window, Pluton, time);
	}
};

class infoPainting
{
private:
	rightinfo Sun, Mercury, Venus, Earth, Mars, Jupiter, Saturn, Uranus, Neptune, Pluton;
	float x, y;

	void body()
	{
		Sun.parameter("sprite\\Sun_1.png", x, y);
	    Mercury.parameter("sprite\\Mercury_1.png", x, y);
		Venus.parameter("sprite\\Venus_1.png", x, y);
		Earth.parameter("sprite\\Earth_1.png", x, y);
		Mars.parameter("sprite\\Mars_1.png", x, y);
		Jupiter.parameter("sprite\\Jupiter_1.png", x, y);
		Saturn.parameter("sprite\\Saturn_1.png", x, y);
		Uranus.parameter("sprite\\Uranus_1.png", x, y);
		Neptune.parameter("sprite\\Neptune_1.png", x, y);
		Pluton.parameter("sprite\\Pluton_1.png", x, y);
	}
	void painting(RenderWindow& window, rightinfo& a, float y_, float time, float height)
	{
		a.update(y_, time, height);
		window.draw(a.sprite);
	}

public:
	void parameter(float x_, float y_)
	{
		x = x_;
		y = y_;
		body();
	}

	void paint(RenderWindow& window, int v, float y_, float time, float height)
	{
		switch (v)
		{
		case 0:
			painting(window, Sun, y_, time, height);
			break;
		case 1:
			painting(window, Mercury, y_, time, height);
			break;
		case 2:
			painting(window, Venus, y_, time, height);
			break;
		case 3:
			painting(window, Earth, y_, time, height);
			break;
		case 4:
			painting(window, Mars, y_, time, height);
			break;
		case 5:
			painting(window, Jupiter, y_, time, height);
			break;
		case 6:
			painting(window, Saturn, y_, time, height);
			break;
		case 7:
			painting(window, Uranus, y_, time, height);
			break;
		case 8:
			painting(window, Neptune, y_, time, height);
			break;
		case 9:
			painting(window, Pluton, y_, time, height);
			break;
		default:
			break;
		}
	}
};

class TextPainting
{
private:
	Text text;
	Font font;
	TextHUD textHUD;

	RectangleShape rectangle;

	int textSize = 20;

	void st()
	{
		font.loadFromFile("text\\AGCrownStyle.ttf");
		text.setFont(font);
		text.setCharacterSize(20);
		text.setFillColor(Color::White);

		rectangle.setFillColor(Color(43, 50, 47, 100));
	}

	void position(RenderWindow& window, float x, float y, int v)
	{
		text.setPosition(x, y);
		text.setString(textHUD.retur(v));

		window.draw(text);
	}

public:
	void printSolarSystem(RenderWindow& window, float x0, float y0)
	{
		rectangle.setSize(Vector2f(350.f, 25.f));
		rectangle.setPosition(x0, y0);
		window.draw(rectangle);
		position(window, x0, y0, 13);
	}

	void printSchematic(RenderWindow& window, float x0, float y0)
	{
		rectangle.setSize(Vector2f(510.f, 25.f));
		rectangle.setPosition(x0, y0);
		window.draw(rectangle);
		position(window, x0, y0, 14);
	}

	void printLefttable(RenderWindow& window, float x0, float y0)
	{
		st();
		textHUD.retur(0);

		rectangle.setSize(Vector2f(810, 305.f));
		rectangle.setPosition(x0, y0);

		window.draw(rectangle);

		position(window, x0, y0, 1);
		position(window, x0, y0+(textSize+5) * 1, 2);
		position(window, x0, y0 + (textSize + 5) * 2, 3);
		position(window, x0, y0 + (textSize + 5) * 3, 4);
		position(window, x0, y0 + (textSize + 5) * 4, 5);
		position(window, x0, y0 + (textSize + 5) * 5, 6);
		position(window, x0, y0 + (textSize + 5) * 6, 7);
		position(window, x0, y0 + (textSize + 5) * 7, 8);
		position(window, x0, y0 + (textSize + 5) * 8, 9);
		position(window, x0, y0 + (textSize + 5) * 9, 10);
		position(window, x0, y0 + (textSize + 5) * 10, 11);
		position(window, x0, y0 + (textSize + 5) * 11, 12);
	}
};

class miniGame
{
private:
	float G = 6;

	float arr1[4];
	float arr2[4];
	float arr3[4];

	float ax = 0.01, ay = 0;
	float vx = 0.01, vy = 0.01;

	objGame Eart, Mars, Roket;
	Button game, Exit, param, Start, Stop;

	Texture textureRoket;

	void body(int v, float x, float y, float mass)
	{
		switch (v)
		{
		case 0:
			Eart.parameter(x, y, 5.9742, 450, "sprite\\Earth_game.png", 40, 40, 0);
		case 1:
			Mars.parameter(x, y, 0.642, 390, "sprite\\Mars_game.png", 40, 40, 0);
		case 2:
			game.parameter(x, y, "sprite\\MiniGame.png");
		case 3:
			Exit.parameter(x, y, "sprite\\Exit.png");
		case 4:
			param.parameter(x, y, "sprite\\Parameter.png");
		case 5:
			Start.parameter(x, y, "sprite\\Start.png");
		case 6:
			Stop.parameter(x, y, "sprite\\Stop.png");
		default:
			break;
		}
	}

	float distance(float x1, float y1, float x2, float y2)
	{
		float distance_ = sqrt(fabs(x2 - x1) + fabs(y2 - y1));
		return distance_;
	}

public:
	void parameter(int v, float x, float y, float mass)
	{
		body(v, x, y, mass);
	}
	void RoketParameter(float x, float y, float ax, float ay, float mass)
	{
		vx = ax;
		vy = ay;
		Roket.parameter(x, y, mass, 50, "sprite\\Roket.png", -40, 20, 90);
		Roket.sprite.setPosition(x, y);
	}
	Sprite sprite(int v)
	{
		switch (v)
		{
		case 0:
			return game.sprite;
		case 1:
			return Exit.sprite;
		case 2:
			return param.sprite;
		case 3:
			return Start.sprite;
		case 4:
			return Stop.sprite;
		default:
			break;
		}
	}

	int gravity(float* arr1_, float* arr2_)
	{
		float mass1, mass2;
		float x1, x2, y1, y2;
		float l;
		int k = 0;

		x1 = arr1_[0];
		x2 = arr2_[0];
		mass1 = arr1[2];

		y1 = arr1_[1];
		y2 = arr2_[1];
		mass2 = arr2_[2];

		l = distance(x1, y1, x2, y2);
		if (l <= 23)
		{

			ax = G * mass2 * mass1 * (x2 - x1) / pow(l, 3);
			ay = G * mass2 * mass1 * (y2 - y1) / pow(l, 3);

			vx = vx + ax / 100;
			vy = vy + ay / 100;
			std::cout << vx << "_" << vy << "\n";
			k = 1;
		}

		return k;
	}

	void paint(RenderWindow& window, float time)
	{
		if (time != 0)
		{
			Roket.ret(arr1);
			Eart.ret(arr2);
			Mars.ret(arr3);
			if (time != 0)
			{
				int i=0;
				if (gravity(arr1, arr2) != 0)
				{
					Roket.update(vx, vy, time);
					i++;
				}
				if (gravity(arr1, arr3) != 0)
				{
					Roket.update(vx, vy, time);
					i++;
				}
				if (i == 0)
				{
					Roket.update(vx, vy, time);
				}
			}
		}

		Eart.paint(window);
		Mars.paint(window);
		Roket.paint(window);
	}

};

class panel
{
private:
	Font font;
	Text num;
	float x, y;
	panelButton n1, n2, n3, n4, n5, n6, n7, n8, n9, n0, enter, str, punkt;

	void body()
	{
		font.loadFromFile("text\\AGCrownStyle.ttf");
		num.setFont(font);
		num.setString("enter");
		num.setCharacterSize(15);
		num.setFillColor(Color::White);

		n1.parameter("sprite\\panel\\1.png");
		n2.parameter("sprite\\panel\\2.png");
		n3.parameter("sprite\\panel\\3.png");
		n4.parameter("sprite\\panel\\4.png");
		n5.parameter("sprite\\panel\\5.png");
		n6.parameter("sprite\\panel\\6.png");
		n7.parameter("sprite\\panel\\7.png");
		n8.parameter("sprite\\panel\\8.png");
		n9.parameter("sprite\\panel\\9.png");
		n0.parameter("sprite\\panel\\0.png");
		enter.parameter("sprite\\panel\\Enter.png");
		str.parameter("sprite\\panel\\sl.png");
		punkt.parameter("sprite\\panel\\punkt.png");
	}
public:
	void position(float x, float y)
	{
		body();

		str.sprite.setPosition(x, y);
		num.setPosition(x, y);

		n1.sprite.setPosition(x, y + 20);
		n2.sprite.setPosition(x + 20, y + 20);
		n3.sprite.setPosition(x + 40, y + 20);
		n4.sprite.setPosition(x + 60, y + 20);

		n5.sprite.setPosition(x, y + 40);
		n6.sprite.setPosition(x + 20, y + 40);
		n7.sprite.setPosition(x + 40, y + 40);
		n8.sprite.setPosition(x + 60, y + 40);

		n9.sprite.setPosition(x, y + 60);
		n0.sprite.setPosition(x + 20, y + 60);
		punkt.sprite.setPosition(x + 40, y + 60);
		enter.sprite.setPosition(x + 60, y + 60);
	}
	void paint(RenderWindow& window, String st)
	{
		num.setString(st);

		window.draw(str.sprite);
		window.draw(num);
		window.draw(n1.sprite);
		window.draw(n2.sprite);
		window.draw(n3.sprite);
		window.draw(n4.sprite);
		window.draw(n5.sprite);
		window.draw(n6.sprite);
		window.draw(n7.sprite);
		window.draw(n8.sprite);
		window.draw(n9.sprite);
		window.draw(n0.sprite);
		window.draw(punkt.sprite);
		window.draw(enter.sprite);
	}

	Sprite retsprite(int v)
	{
		switch (v)
		{
		case 0:
			return n0.sprite;
		case 1:
			return n1.sprite;
		case 2:
			return n2.sprite;
		case 3:
			return n3.sprite;
		case 4:
			return n4.sprite;
		case 5:
			return n5.sprite;
		case 6:
			return n6.sprite;
		case 7:
			return n7.sprite;
		case 8:
			return n8.sprite;
		case 9:
			return n9.sprite;
		case 10:
			return enter.sprite;
		case 11:
			return str.sprite;
		case 12:
			return punkt.sprite;
		default:
			break;
		}
	}
};

class parameterPanel
{
private:
	panelButton info, seve, X, Y, Vx, Vy, Mass;

	Font font;
	Text x, y, vx, vy, mass;

	void body()
	{
		info.parameter("sprite\\Parameter Panel\\info.png");
		seve.parameter("sprite\\Parameter Panel\\Seve.png");
		X.parameter("sprite\\Parameter Panel\\X.png");
		Y.parameter("sprite\\Parameter Panel\\Y.png");
		Vx.parameter("sprite\\Parameter Panel\\Vx.png");
		Vy.parameter("sprite\\Parameter Panel\\Vy.png");
		Mass.parameter("sprite\\Parameter Panel\\Mass.png");

		font.loadFromFile("text\\AGCrownStyle.ttf");
		x.setFont(font);
		x.setString("0");
		x.setCharacterSize(15);
		x.setFillColor(Color::White);

		y.setFont(font);
		y.setString("0");
		y.setCharacterSize(15);
		y.setFillColor(Color::White);

		vx.setFont(font);
		vx.setString("0");
		vx.setCharacterSize(15);
		vx.setFillColor(Color::White);

		vy.setFont(font);
		vy.setString("0");
		vy.setCharacterSize(15);
		vy.setFillColor(Color::White);

		mass.setFont(font);
		mass.setString("0");
		mass.setCharacterSize(15);
		mass.setFillColor(Color::White);
	}
public:
	void position(float x_, float y_)
	{
		body();
		info.sprite.setPosition(x_, y_);
		seve.sprite.setPosition(x_ + 25, y_ + 175);
		X.sprite.setPosition(x_ + 205, y_);
		Y.sprite.setPosition(x_ + 205 + 45, y_);
		Vx.sprite.setPosition(x_ + 205, y_ + 45);
		Vy.sprite.setPosition(x_ + 205 + 45, y_ + 45);
		Mass.sprite.setPosition(x_ + 205, y_ + 90);

		x.setPosition(x_ + 209, y_ + 21);
		y.setPosition(x_ + 209 + 45, y_ + 21);
		vx.setPosition(x_ + 209, y_ + 45 + 21);
		vy.setPosition(x_ + 209 + 45, y_ + 45 + 21);
		mass.setPosition(x_ + 209, y_ + 90 + 21);
	}
	void paint(RenderWindow& window)
	{
		window.draw(info.sprite);
		window.draw(X.sprite);
		window.draw(Y.sprite);
		window.draw(Vx.sprite);
		window.draw(Vy.sprite);
		window.draw(Mass.sprite);
		window.draw(seve.sprite);

		window.draw(x);
		window.draw(y);
		window.draw(vx);
		window.draw(vy);
		window.draw(mass);
	}

	Sprite sprite(int v)
	{
		switch (v)
		{
		case 0:
			return seve.sprite;
		case 1:
			return X.sprite;
		case 2:
			return Y.sprite;
		case 3:
			return Vx.sprite;
		case 4:
			return Vy.sprite;
		case 5:
			return Mass.sprite;
		default:
			break;
		}
	}

	void str(int v, String s)
	{
		switch (v)
		{
		case 0:
			x.setString(s);
		case 1:
			y.setString(s);
		case 2:
			vx.setString(s);
		case 3:
			vy.setString(s);
		case 4:
			mass.setString(s);
		default:
			break;
		}
	}
};