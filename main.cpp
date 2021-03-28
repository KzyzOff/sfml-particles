
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Particles.h"

int main()
{
	// creating window
	unsigned int win_width { 800 }, win_height { 600 };
	sf::RenderWindow window( sf::VideoMode( win_width, win_height ), "Particles demo" );
	window.setVerticalSyncEnabled( true );

	Particle part( window, 20.f, 10.f );
	part.setRadius( 10.f );
	part.setColor( sf::Color::Red );
	part.setPosition( {300.f, 300.f} );

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
		window.draw( part );
		window.display();
	}

	return 0;
}