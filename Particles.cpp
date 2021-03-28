
#include "Particles.h"

// ParticleCluster implementation

ParticleCluster::ParticleCluster(sf::RenderWindow &win )
		: window( win ),
		current_state( States::NOT_ACTIVE ),
		lifespan_time( sf::Time::Zero )
{
	particle_vec.clear();
}

void ParticleCluster::trigger(sf::Vector2f position )
{

}

void ParticleCluster::update(float elapsed_time )
{

}

void ParticleCluster::draw(sf::RenderTarget &target, sf::RenderStates states ) const
{

}

// Particle implementation

Particle::Particle( sf::RenderWindow &win, float speed, float angle )
        : window(win),
        speed(speed),
        angle(angle)
{
    direction.x = cos( (double)angle );
    direction.y = sin( (double)angle );
}

void Particle::setAngle( float d_angle )
{
    angle = d_angle;
}

void Particle::setColor( sf::Color color )
{
    shape.setFillColor( color );
}

void Particle::setRadius( float radius )
{
    shape.setRadius( radius );
}

void Particle::setPosition( sf::Vector2f pos )
{
    shape.setPosition( pos );
}

void Particle::update( float elapsed_time )
{
    shape.setPosition( {elapsed_time * direction.x, elapsed_time * direction.y} );
}

void Particle::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{
    target.draw( shape );
}

sf::Vector2f Particle::getPosition() const
{
    return shape.getPosition();
}

sf::Vector2f Particle::getDirection() const
{
    return direction;
}

float Particle::getSpeed() const
{
    return speed;
}

float Particle::getAngle() const
{
    return angle;
}

float Particle::getRadius() const
{
    return shape.getRadius();
}
