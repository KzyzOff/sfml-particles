
#ifndef SFML_PARTICLES_PARTICLE_H
#define SFML_PARTICLES_PARTICLE_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cmath>

enum class ParticleStates { ALIVE, DEAD };
enum class States { NOT_ACTIVE, TRIGGERED, CLEARING };

class Particle
{
private:
    sf::RenderWindow &window;
	sf::CircleShape shape;
	sf::Vector2f position;
	sf::Vector2f velocity;
	float speed;
	float angle;
	ParticleStates state;

    void updatePosition();
    void updateVelocity();

    // Extrapolates shape position between two updatePhysics() calls.
    // The factor value is between 0 and 1.
    void updateShapePos( float factor );

    void updateState();

public:
	Particle( sf::RenderWindow &win, float speed, float angle_in_rad );

	void updatePhysics();
	// Draw shape on the window
	void render( float factor );

    void setAngle( float d_angle );
    void setColor( sf::Color color );
    void setRadius( float radius );
    void setPosition( sf::Vector2f pos );

	sf::Vector2f getPosition() const;
	sf::Vector2f getVelocity() const;
	float getSpeed() const;
	float getAngle() const;
	float getRadius() const;

};


#endif