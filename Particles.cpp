
#include "Particles.h"

// ParticleCluster methods

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

// Particle methods

Particle::Particle( float speed, float angle )
{

}

void Particle::change_angle( float d_angle )
{

}

void Particle::update( float elapsed_time )
{

}

void Particle::draw( sf::RenderTarget &target, sf::RenderStates states ) const
{

}
