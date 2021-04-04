
#ifndef SFML_PARTICLES_CLUSTER_H
#define SFML_PARTICLES_CLUSTER_H


#include <SFML/Graphics.hpp>
#include <vector>

#include "particle/Particle.h"

class Cluster : public sf::Drawable
{
private:
    sf::RenderWindow &window;
    std::vector<Particle> particle_vec;
    States current_state;
    sf::Clock timer;
    // defines the minimum time after which particles start to disappear (in milliseconds)
    sf::Time lifespan_time;

public:
    explicit Cluster( sf::RenderWindow &win );

    void trigger( sf::Vector2f position );
    void update( float elapsed_time );
    void draw( sf::RenderTarget &target, sf::RenderStates states ) const override;

};


#endif //SFML_PARTICLES_CLUSTER_H
