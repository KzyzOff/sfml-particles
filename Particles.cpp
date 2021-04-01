
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

Particle::Particle( sf::RenderWindow &win, float speed, float angle_in_rad )
        : window(win),
        speed(speed),
        angle(angle_in_rad),
        state(ParticleStates::ALIVE)
{
    updateVelocity();
}

void Particle::updatePosition()
{
    position = {shape.getPosition().x + velocity.x,
                shape.getPosition().y + velocity.y};
}

void Particle::updateVelocity()
{
    // calculate X and Y values of direction vector
    float dir_x = cosf( angle ) * speed;
    float dir_y = -sinf( angle ) * speed;
    // round values to 0 when less than 0.00001f
    velocity.x = ( fabsf(dir_x) > 0.00001f ) ? dir_x : 0.f;
    velocity.y = ( fabsf(dir_y) > 0.00001f ) ? dir_y : 0.f;
}

void Particle::updatePhysics()
{
    updatePosition();
    updateVelocity();
}

void Particle::updateShapePos( float time_factor )
{
    shape.setPosition( {position.x + velocity.x * time_factor,
                        position.y + velocity.y * time_factor} );
}

void Particle::render( float time_factor )
{
    updateShapePos( time_factor );
    window.draw( shape );
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
    if ( pos.x > window.getSize().x || pos.x < 0 ||
         pos.y > window.getSize().y || pos.y < 0)
    {
        return;
    }
    position = pos;
}

sf::Vector2f Particle::getPosition() const
{
    return shape.getPosition();
}

sf::Vector2f Particle::getVelocity() const {
    return velocity;
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