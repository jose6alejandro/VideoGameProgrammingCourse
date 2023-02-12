#pragma once

#include <src/Bird.hpp>
#include <src/World.hpp>
#include <SFML/Graphics.hpp>

class GameMode
{
    public:
        GameMode(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird) 
        : world{_world}, bird{_bird} 
        {

        }

        virtual ~GameMode() {}
        virtual void handle_input(const sf::Event & event) noexcept {}
        virtual void update(float dt) noexcept {}
        //virtual void render(sf::RenderTarget& target) noexcept {}
        virtual void print() noexcept {}

    protected:
        std::shared_ptr<Bird> bird;
        std::shared_ptr<World> world;       
};