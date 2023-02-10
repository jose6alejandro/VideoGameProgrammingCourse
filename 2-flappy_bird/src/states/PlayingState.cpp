/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class PlayingBaseState.
*/

#include <Settings.hpp>
#include <src/text_utilities.hpp>
#include <src/states/StateMachine.hpp>
#include <src/states/PlayingState.hpp>

PlayingState::PlayingState(StateMachine* sm) noexcept
    : BaseState{sm}, game_mode{nullptr}
{

}

void PlayingState::enter(std::shared_ptr<World> _world, std::shared_ptr<Bird> _bird, int _score) noexcept
{
    world = _world;
    score = _score;
    
    world->reset(true);
    
    if (_bird == nullptr)
    {
        bird = std::make_shared<Bird>(
            Settings::VIRTUAL_WIDTH / 2 - Settings::BIRD_WIDTH / 2, Settings::VIRTUAL_HEIGHT / 2 - Settings::BIRD_HEIGHT / 2,
            Settings::BIRD_WIDTH, Settings::BIRD_HEIGHT
        );  
    }
    else
    {
        bird = _bird;
    }

    if (game_mode == nullptr)
    {        
        if (!(state_machine->get_game_mode()))
        {
            game_mode = std::make_shared<NormalMode>(world, bird);
        }
        else
        {
            game_mode = std::make_shared<HardMode>(world, bird);
        }    
        
    }
    
}

void PlayingState::handle_inputs(const sf::Event& event) noexcept
{
    game_mode->handle_input(event);

    if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space) 
    {
        state_machine->change_state("pause", world, bird, score);
    }
}

void PlayingState::update(float dt) noexcept
{
    game_mode->update(dt);

    if (world->collides(bird->get_collision_rect()))
    {
        Settings::sounds["explosion"].play();
        Settings::sounds["hurt"].play();
        state_machine->change_state("count_down");
    }

    if (world->update_scored(bird->get_collision_rect()))
    {
        ++score;
        Settings::sounds["score"].play();
    }
}

void PlayingState::render(sf::RenderTarget& target) const noexcept
{
    world->render(target);
    bird->render(target);
    render_text(target, 20, 10, "Score: " + std::to_string(score), Settings::FLAPPY_TEXT_SIZE, "flappy", sf::Color::White);
}