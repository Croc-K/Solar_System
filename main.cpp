#include <SFML/Graphics.hpp>

#include "event_logic.cpp"

using namespace sf;

int RENDER_wight = 1920;
int RENDER_height = 1000;  
    
int main() 
{
	rightinfo info; 

	RenderWindow window(VideoMode(RENDER_wight, RENDER_height), "Solar System");
	window.setVerticalSyncEnabled(true); 

	picture im;
	im.xy(window); 
	
	Clock clock; 
	Event event;
	   
	while (window.isOpen())
	{ 
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 200;
	   
		im.time_(time);

		window.clear(); 
		im.event_(window, event);

		im.paint(window);
		 
		window.display();
	}
	return 0;
}