/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the declaration of the class TitleScreenState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/TitleScreenState.hpp>

TitleScreenState::TitleScreenState(StateMachine* sm) noexcept
    : BaseState{sm}, world{}
{

}

void TitleScreenState::handle_inputs(const sf::Event& event) noexcept
{
    
    if (event.key.code == sf::Keyboard::Space && !select_mode)
    {  
        state_machine->set_game_mode(select_mode);
        state_machine->change_state("count_down"); //NormalMode
    }

    if (event.key.code == sf::Keyboard::Space && select_mode)
    {
        state_machine->set_game_mode(select_mode);
        state_machine->change_state("count_down"); //HardMode
    }
    
    
    if (event.key.code == sf::Keyboard::W)
    {
        select_mode = false;
    }

    if (event.key.code == sf::Keyboard::S)
    {
        select_mode = true;
    }

}

void TitleScreenState::update(float dt) noexcept
{
    world.update(dt);
}

void TitleScreenState::render(sf::RenderTarget& target) const noexcept 
{
    world.render(target);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 3, "Flappy Bird", Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White, true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, (2 * Settings::VIRTUAL_HEIGHT / 3) - 40, "Select the game mode to start", Settings::MEDIUM_TEXT_SIZE, "font", sf::Color::White, true);
    
    sf::Color first_color(250, 141, 54);
    sf::Color second_color(255, 255, 255);    
    
    if (select_mode)
    {
        first_color  = sf::Color(255, 255, 255);
        second_color = sf::Color(250, 141, 54);
    }
    
    render_text(target, Settings::VIRTUAL_WIDTH / 2, (2 * Settings::VIRTUAL_HEIGHT / 3), "Normal", Settings::MEDIUM_TEXT_SIZE, "font", first_color , true);
    render_text(target, Settings::VIRTUAL_WIDTH / 2, (2 * Settings::VIRTUAL_HEIGHT / 3) + 30, "Hard", Settings::MEDIUM_TEXT_SIZE, "font", second_color, true);  

    
}