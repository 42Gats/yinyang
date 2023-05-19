/*
** EPITECH PROJECT, 2023
** jam
** File description:
** savejump
*/

#include "../includes/include.hpp"

void jump(void)
{
    int speed = 0;
    sf::Clock clock;
    sf::Sprite sprite;
    sf::Sprite entity;
    sf::Time time3 = clock.getElapsedTime();
    if (time3.asMicroseconds() / 1000000.0 > 0.01) {
        entity.setPosition(sf::Vector2f(entity.getPosition().y - 20 - speed, entity.getPosition().x));
        clock.restart();
        speed++;
    }
}
