#pragma once


#include <src/modes/GameMode.hpp>
#include <src/Bird.hpp>
#include <src/World.hpp>

class HardMode: public GameMode
{
    public:
        HardMode(std::shared_ptr<World> world, std::shared_ptr<Bird> bird);
        ~HardMode() {}
        void handle_input(const sf::Event & event) noexcept override;
        void update(float dt) noexcept override;
        void print() noexcept override;

};