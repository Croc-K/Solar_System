#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

class Circle
{
private:
	int x0, y0, x, y;

	float angle = 0;
	float radius, angleSpeed;

	float widthTexture;
	float heightTexture;

	String adres;
	String text;
	Font font;

	Texture texture;

	void body()
	{
		texture.loadFromFile(adres);

		Vector2u size = texture.getSize();
		widthTexture = size.x;
		heightTexture = size.y;

		sprite.setTexture(texture);

		sprite.setPosition(x0 - widthTexture / 2, y0 - heightTexture / 2);

		font.loadFromFile("text\\AGCrownStyle.ttf");

		name.setFont(font);
		name.setString(text);
		name.setCharacterSize(20);
		name.setFillColor(Color::White);
		name.setPosition(x - widthTexture / 2, y - (30 + heightTexture / 2));
	}

public:
	Sprite sprite;
	Text name;

	void parameters(String a, int px, int py, int sizex, int sizey, float r, float s, String t)
	{
		adres = a;
		x = px;
		y = py;
		x0 = sizex;
		y0 = sizey;
		radius = r;
		angleSpeed = s;
		text = t;
		body();
	}

	void update(float time)
	{
		x = x0 + cos(angle) * radius;
		y = y0 + sin(angle) * radius;

		sprite.setPosition(x - widthTexture / 2, y - heightTexture / 2);
		name.setPosition(x - widthTexture / 2, y - (7 + heightTexture / 2));

		angle = angle + time * angleSpeed;
		if (angle >= 360)
		{
			angle = 0;
		}
	}

	CircleShape c()
	{
		CircleShape shape(radius);
		shape.setOutlineThickness(1);
		shape.setFillColor(Color(0, 0, 0, 0));
		shape.setOutlineColor(Color::Green);

		shape.setPosition(x0 - radius, y0 - radius);
		return shape;
	}
};

class TextHUD
{
private:
	String str, Mercury, Earth, Venus, Mars, Jupiter, Saturn, Uranus, Neptune, p, Pluton;
	String solarSystem, Schematic;

	void st()
	{
		str = "�������  |  ������������� ����� | ���� x10^24 | ³������ �� �����";
		Mercury = "�������                   2439.7 ��               0.330 ��             57.89 ���. ��      ";
		Venus = "������                       6051.8 ��               4.869 ��            108.16 ���. ��      ";
		Earth = "�����                       6378.14 ��              5.9742 ��            149.60 ���. ��      ";
		Mars = "����                            3397 ��               0.642 ��            227.99 ���. ��      ";
		Jupiter = "�����                      71492 ��              1898.8 ��            778.36 ���. ��      ";
		Saturn = "������                       60268 ��               568.5 ��           1427.01 ���. ��      ";
		Uranus = "����                         25559 ��              86.625 ��           2875.27 ���. ��      ";
		Neptune = "������                      24764 ��              102.78 ��           4504.39 ���. ��      ";
		p = "_______________________��������� �������___________________________";
		Pluton = "������                        1151 ��               0.015 ��           5900.14 ���. ��      ";

		solarSystem = "��������� ������� �������";
		Schematic = "���������� ���������� ������� �������";
	}
public:
	String retur(int v)
	{
		switch (v)
		{
		case 0:
			st();
		case 1:
			return str;
		case 2:
			return Mercury;
		case 3:
			return Venus;
		case 4:
			return Earth;
		case 5:
			return Venus;
		case 6:
			return Mars;
		case 7:
			return Jupiter;
		case 8:
			return Saturn;
		case 9:
			return Uranus;
		case 10:
			return Neptune;
		case 11:
			return p;
		case 12:
			return Pluton;
		case 13:
			return solarSystem;
		case 14:
			return Schematic;
		default:
			break;
		}
	}
};

class rightinfo
{
private:
	Texture texture;
	float x, y;
	String adres;
	void body()
	{
		texture.loadFromFile(adres);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}
public:
	Sprite sprite;
	void parameter(String adres_, float x_, float y_)
	{
		adres = adres_;
		x = x_;
		y = y_;
		body();
	}
	void update(float y_, float time_, float height)
	{
	    sprite.setPosition(x, y);
		if ((y + y_) < (1610 - height)*-1)
		{
			y = y+10;
		}
		else
			if ((y + y_) > 10)
			{
				y = y-10;
			}
			else {
				y = y +(y_/10) * time_;
			}
		sprite.setPosition(x, y);
	}
};

class objGame
{ 
private:
	Texture texture;
	String s;
	float sprite_x, sprite_y;

	float x, y, mass;
	float l;

	int rotation;

	void body()
	{
		texture.loadFromFile(s);
		sprite.setTexture(texture);
		sprite.setRotation(rotation);
		sprite.setPosition(x, y);
	}

public:
	Sprite sprite;

	void parameter(float x_, float y_, float mass_, float l_, String s_, float sprite_x_, float sprite_y_, int rotation_)
	{
		x = x_, y = y_, mass = mass_, l = l_;
		s = s_;
		sprite_x = sprite_x_;
		sprite_y = sprite_y_;
		rotation = rotation_;
		body();
	}

	void paint(RenderWindow& window)
	{
		window.draw(shape());
		window.draw(sprite);
	}

	void update(float ax, float ay, float time)
	{
		x = x + ax * time;
		y = y + ay * time;
		sprite.setPosition(x, y);
	}

	float* ret(float* arr)
	{
		arr[0] = x + sprite_x;
		arr[1] = y + sprite_y;
		arr[2] = mass;
		arr[3] = l;
		return arr;
	}

	CircleShape shape()
	{
		CircleShape shape(l);
		shape.setOutlineThickness(2);
		shape.setFillColor(Color(0, 0, 0, 0));
		shape.setOutlineColor(Color::Green);
		shape.setPosition(x - l + sprite_x, y - l + sprite_y);

		return shape;
	}
};

class Button
{
private:
	Texture texture;
public:
	Sprite sprite;
	void parameter(float x, float y, String s)
	{
		texture.loadFromFile(s);
		sprite.setTexture(texture);
		sprite.setPosition(x, y);
	}
};

class panelButton
{
private:
	Texture texture;
public:
	Sprite sprite;
	void parameter(String s)
	{
		texture.loadFromFile(s);
		sprite.setTexture(texture);
	}

};