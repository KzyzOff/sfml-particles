
#ifndef SFML_PARTICLES_PARTICLES_H
#define SFML_PARTICLES_PARTICLES_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum States { NOT_ACTIVE, TRIGGERED, CLEARING };

class Particle : public sf::Drawable
{

private:
	sf::CircleShape shape;
	sf::Vector2f velocity;
	float speed;
	float angle;

public:
	Particle( float speed, float angle );

	void change_angle( float d_angle );
	void update( float elapsed_time );
	void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

};

class ParticleCluster : public sf::Drawable
{

private:
	sf::RenderWindow &window;
	std::vector<Particle> particle_vec;
	States current_state;
	sf::Clock timer;
	// defines the minimum time after which particles start to disappear (in milliseconds)
	sf::Time lifespan_time;

public:
	explicit ParticleCluster(sf::RenderWindow &win );

	void trigger( sf::Vector2f position );
	void update( float elapsed_time );
	void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

};


#endif