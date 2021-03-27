
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Particles.h"

int main()
{
	// creating window
	unsigned int win_width { 800 }, win_height { 600 };
	sf::RenderWindow window( sf::VideoMode( win_width, win_height ), "Particles demo" );
	window.setVerticalSyncEnabled( true );

	Particles part( window );

	sf::Event event {};
	// main loop
	while ( window.isOpen() )
	{
		// event loop
		while ( window.pollEvent(event) )
		{
			if ( event.type == sf::Event::Closed )
				window.close();
		}

		// rendering stuff
		window.clear( sf::Color::Black );
		// window.draw();
		window.display();
	}

	return 0;
}