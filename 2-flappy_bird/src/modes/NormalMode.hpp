#pragma once


#include <src/modes/GameMode.hpp>
#include <src/Bird.hpp>
#include <src/World.hpp>


class NormalMode: public GameMode
{
    public:
        NormalMode(std::shared_ptr<World> world, std::shared_ptr<Bird> bird);
        ~NormalMode() {}
        void handle_input(const sf::Event& event) noexcept override;
        void update(float dt) noexcept override;
        void print() noexcept override;

};