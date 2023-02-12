/*
    ISPPJ1 2023
    Study Case: Flappy Bird

    Author: Alejandro Mujica
    alejandro.j.mujic4@gmail.com

    This file contains the definition of the class LogPair.
*/

#include <Settings.hpp>
#include <src/LogPair.hpp>

LogPair::LogPair(float _x, float _y, float _log_gap) noexcept
    : x{_x}, y{_y}, log_gap{_log_gap},
      top{x, y + Settings::LOG_HEIGHT, true},
      bottom{x, y + _log_gap + Settings::LOG_HEIGHT, false}
{

}

bool LogPair::collides(const sf::FloatRect& rect) const noexcept
{
    return top.get_collision_rect().intersects(rect) || bottom.get_collision_rect().intersects(rect);
}

void LogPair::update(float dt) noexcept //edit
{
    float vy = (Settings::BACK_SCROLL_SPEED - 10) * dt;
    x += -Settings::MAIN_SCROLL_SPEED * dt;

    if (displacement)
    {
        
        if (closed_gap) 
        {
            top.update(x, vy);
            bottom.update(x, -vy);
        }
        else 
        {
            top.update(x, -vy);
            bottom.update(x, vy);
        }

        if (top.get_collision_rect().intersects(bottom.get_collision_rect())) 
        {   
            closed_gap = false;
            Settings::sounds["explosion"].play(); //shock
        }

        if (top.get_collision_rect().top <= y) 
        {
            closed_gap = true;
        }
    }
    else 
    {
        top.update(x, 0);
        bottom.update(x, 0);
    }
}

void LogPair::render(sf::RenderTarget& target) const noexcept
{
    top.render(target);
    bottom.render(target);
}

bool LogPair::is_out_of_game() const noexcept
{
    return x < -Settings::LOG_WIDTH;
}

bool LogPair::update_scored(const sf::FloatRect& rect) noexcept
{
    if (scored)
    {
        return false;
    }

    if (rect.left > x + Settings::LOG_WIDTH)
    {
        scored = true;
        return true;
    }

    return false;
}

void LogPair::reset(float _x, float _y) noexcept
{
    x = _x;
    y = _y;
    scored = false;

    top.reset(x, y + Settings::LOG_HEIGHT);
    bottom.reset(x, y + log_gap + Settings::LOG_HEIGHT);

}

void LogPair::set_displacement(bool _displacement) noexcept
{
    displacement = _displacement;
}
