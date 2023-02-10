#include <src/modes/NormalMode.hpp>

NormalMode::NormalMode(std::shared_ptr<World> world, std::shared_ptr<Bird> bird):
    GameMode(world, bird)
{

}

void NormalMode::handle_input(const sf::Event & event) noexcept
{
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {        
        bird->jump();
    }
}


void NormalMode::print() noexcept
{
 std::cout << "Normal!" << std::endl;
}

void NormalMode::update(float dt) noexcept
{
    bird->update(dt);
    world->update(dt);
}
