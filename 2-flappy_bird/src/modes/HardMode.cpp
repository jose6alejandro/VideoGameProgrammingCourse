#include <src/modes/HardMode.hpp>


HardMode::HardMode(std::shared_ptr<World> world, std::shared_ptr<Bird> bird):
    GameMode(world, bird)
{

}

void HardMode::handle_input(const sf::Event & event) noexcept
{   
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {        
        bird->jump();
        
    }

    if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::A)
    {
        bird->move_left();
    }

    if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::D)
    {
        bird->move_right();
    }
}

void HardMode::print() noexcept
{
 std::cout << "Hard!" << std::endl;
}

void HardMode::update(float dt) noexcept
{
    bird->update(dt);
    world->update_hard_mode(dt);
}


