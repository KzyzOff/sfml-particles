
#include <iostream>
#include <cmath>
#include <chrono>
#include <SFML/Graphics.hpp>

#include "Particles.h"

#define MS_PER_UPDATE 1.f/45.f

int main()
{
	// creating window
	unsigned int win_width { 800 }, win_height { 600 };
	sf::RenderWindow window( sf::VideoMode( win_width, win_height ), "Particles demo" );
	window.setVerticalSyncEnabled( true );

	Particle part( window, 3.f, (167.f * M_PI) / 180.f );
	part.setRadius( 8.f );
	part.setColor( sf::Color::Red );
	part.setPosition( {300.f, 300.f} );

	sf::Clock loop_timer;
	float previous_time = loop_timer.getElapsedTime().asSeconds();
	float lag = sf::Time::Zero.asSeconds();

	sf::Event event {};
	// main loop
	while ( window.isOpen() )
	{
	    float current_time = loop_timer.getElapsedTime().asSeconds();
	    float elapsed_time = current_time - previous_time;
	    previous_time = current_time;
	    lag += elapsed_time;

		// event and input loop
		while ( window.pollEvent(event) )
		{
			if ( event.type == sf::Event::Closed )
				window.close();
		}
		// update physics loop
        while ( lag >= MS_PER_UPDATE )
        {
            part.updatePhysics();
            lag -= MS_PER_UPDATE;
        }

		// rendering stuff
		window.clear( sf::Color::Black );
		part.render( lag / MS_PER_UPDATE );
		window.display();
	}

	return 0;
}