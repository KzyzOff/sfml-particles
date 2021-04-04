//
// Created by krzysztof on 02.04.2021.
//

#include "Cluster.h"

Cluster::Cluster(sf::RenderWindow &win )
        : window( win ),
          current_state( States::NOT_ACTIVE ),
          lifespan_time( sf::Time::Zero )
{
    particle_vec.clear();
}

void Cluster::trigger(sf::Vector2f position )
{

}

void Cluster::update(float elapsed_time )
{

}

void Cluster::draw(sf::RenderTarget &target, sf::RenderStates states ) const
{

}