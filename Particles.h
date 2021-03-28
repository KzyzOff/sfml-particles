
#ifndef SFML_PARTICLES_PARTICLES_H
#define SFML_PARTICLES_PARTICLES_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

enum States { NOT_ACTIVE, TRIGGERED, CLEARING };

class Particle : public sf::Drawable
{
private:
    sf::RenderWindow &window;
	sf::CircleShape shape;
	sf::Vector2f direction;
	float speed;
	float angle;

public:
	Particle( sf::RenderWindow &win, float speed, float angle );

	void update( float elapsed_time );
	void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;
    void setAngle( float d_angle );
    void setColor( sf::Color color );
    void setRadius( float radius );
    void setPosition( sf::Vector2f pos );

	sf::Vector2f getPosition() const;
	sf::Vector2f getDirection() const;
	float getSpeed() const;
	float getAngle() const;
	float getRadius() const;

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
	explicit ParticleCluster( sf::RenderWindow &win );

	void trigger( sf::Vector2f position );
	void update( float elapsed_time );
	void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

};


#endif