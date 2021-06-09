#include <SFML\Graphics.hpp>
#include<iostream>
#include <string>
#include <sstream>

#include "painting.cpp"

using namespace sf;

class picture
{
private:

	int scale = 10;
	int spead = 1000000;
	float x, y, x0, y0;
	float dy;
	float time;

	float roket_x= 10, roket_y = 500, roket_ax = 0.01, roket_ay = 0.01, roket_mass = 1;

	int k, v = 0, pr = 0, pole;

	char O=' ';
	float elem=0, elemNull=0, buff;

	String Start;

	Vector2u RENDER;

	CirclePainting circle;
	infoPainting info;
	miniGame game;
	panel p;
	parameterPanel prPanel;

	TextPainting text;

	void Oo(float t_)
	{
		if (O != '.')
		{
			elem = elem * 10;
			elem += t_;
		}
		else 
		if (O == '.')
		{
			if (t_ == 0)
			{
				elemNull += 1;
			}
			else
			{
				for (int i = 0; i <= elemNull; i++)
				{
					t_ = t_ / 10;
				}
				elem = elem + t_;
				elemNull += 1;
			}
		}
	}
	void panelNum(Event& event, RenderWindow& window)
	{
		Vector2i mousePosition = Mouse::getPosition(window);

		if (p.retsprite(1).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(1);
		}
		if (p.retsprite(2).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(2);
		}
		if (p.retsprite(3).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(3);
		}
		if (p.retsprite(4).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(4);
		}
		if (p.retsprite(5).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(5);
		}
		if (p.retsprite(6).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(6);
		}
		if (p.retsprite(7).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(7);
		}
		if (p.retsprite(8).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(8);
		}
		if (p.retsprite(9).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(9);
		}
		if (p.retsprite(0).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			Oo(0);
		}
		if (p.retsprite(12).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			O = '.';
		}
		if (p.retsprite(10).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			O = ' ';
			elem = 0;
			elemNull = 0;
		}
	}
	void ParameterPanel(Event& event, RenderWindow& window)
	{
		Vector2i mousePosition = Mouse::getPosition(window);

		if (prPanel.sprite(0).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			game.RoketParameter(roket_x, roket_y, roket_ax, roket_ay, roket_mass);
			pr = 0;
		}
		if (prPanel.sprite(1).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			roket_x = elem;
		}
		if (prPanel.sprite(2).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			roket_y = elem;
		}
		if (prPanel.sprite(3).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			roket_ax = elem;
		}
		if (prPanel.sprite(4).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			roket_ay = elem;
		}
		if (prPanel.sprite(5).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
		{
			roket_mass = elem;
		}
	}
	void printParameter()
	{
		std::ostringstream st0, st1, st2, st3, st4;
		st0 << roket_x;
		st1 << roket_y;
		st2 << roket_ax;
		st3 << roket_ay;
		st4 << roket_mass;

		prPanel.str(0, st0.str());
		prPanel.str(1, st1.str());
		prPanel.str(2, st2.str());
		prPanel.str(3, st3.str());
		prPanel.str(4, st4.str());
	}

public:
	void xy(RenderWindow& window)
	{
		Vector2u size = window.getSize();
		x = size.x;
		y = size.y;
		x0 = size.x / 2;
		y0 = size.y / 2;

		circle.parametr(x, y, x0, y0, scale, spead);
		info.parameter(x - 500, 10);

		game.parameter(0, 450, y/2, 0);
		game.parameter(1, 1450, y/2, 0);
		game.RoketParameter(roket_x, roket_y, roket_ax, roket_ay, roket_mass);
		
		game.parameter(2, 10, 40, 0);
		game.parameter(3, 10, 80, 0);
		game.parameter(4, 105, 80, 0);
		game.parameter(5, 210, 80, 0);
		game.parameter(6, 315, 80, 0);

		p.position(10, 140);
		prPanel.position(105, 120);
	}

	void event_(RenderWindow& window, Event& event)
	{
		Vector2i mousePosition = Mouse::getPosition(window);

		while (window.pollEvent(event))
		{
			switch (event.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::Resized: {
				float weight = static_cast<float>(event.size.width);
				float height = static_cast<float>(event.size.height);
				window.setView(View(Vector2f(weight / 2.0, height / 2.0), Vector2f(weight, height)));
				xy(window);
				break;
			}

			case Event::MouseButtonPressed:
				if (event.key.code == Mouse::Left)
				{
					if (circle.prSprite(0).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 0;
					}
					if (circle.prSprite(1).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 1;
					}
					if (circle.prSprite(2).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 2;
					}
					if (circle.prSprite(3).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 3;
					}
					if (circle.prSprite(4).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 4;
					}
					if (circle.prSprite(5).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 5;
					}
					if (circle.prSprite(6).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 6;
					}
					if (circle.prSprite(7).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 7;
					}
					if (circle.prSprite(8).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 8;
					}
					if (circle.prSprite(9).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						k = 9;
					}
					if (game.sprite(0).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
					{
						v = 1;
						pr = 0;
						game.RoketParameter(roket_x, roket_y, roket_ax, roket_ay, roket_mass);
						Start == "stop";
					}
					if (v > 0)
					{

						if (game.sprite(1).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
						{
							v = 0;
						}
						if (game.sprite(2).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
						{
							pr = 1;
						}
						if (game.sprite(3).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
						{
							Start = "start";
							pr = 0;
						}
						if (game.sprite(4).getGlobalBounds().contains(mousePosition.x, mousePosition.y))
						{
							Start = "stop";
							game.RoketParameter(roket_x, roket_y, roket_ax, roket_ay, roket_mass);
							pr = 1;
						}
						if (pr == 1)
						{
							panelNum(event, window);

							ParameterPanel(event, window);
						}
					}
				}
			case Event::MouseWheelScrolled:
			{
				if (event.mouseWheelScroll.delta < 0)
				{
					dy = event.mouseWheelScroll.delta;
				}
				else
				{
					dy = event.mouseWheelScroll.delta;
				}
			}
			default:
				break;
			}
			RENDER = window.getSize();
		}
	}

	void paint(RenderWindow& window)
	{
		if (v == 0)
		{
			circle.paint(window, time);

			info.paint(window, k, dy, time, RENDER.y);
			dy = 0;

			text.printLefttable(window, 0, RENDER.y - 300);
			text.printSchematic(window, RENDER.x / 2 - 255, 0);
			window.draw(game.sprite(0));
		}
		else {
			if (v == 1)
			{
				window.draw(game.sprite(1));
				window.draw(game.sprite(2));
				window.draw(game.sprite(3));
				window.draw(game.sprite(4));

				game.paint(window, 0);

				if (Start == "start")
				{
					game.paint(window, time);
				}
				if (Start == "stop")
				{
					game.paint(window, 0);
				}

				if (pr == 1)
				{
					printParameter();
					std::ostringstream ost;
					ost << elem;
					p.paint(window, ost.str());

					prPanel.paint(window);
				}
			}
		}

		text.printSolarSystem(window, 0, 0);
	}

	void time_(float t)
	{
		time = t;
	}
};
