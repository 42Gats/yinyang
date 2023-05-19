/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** sfml
*/

#include "sfml.hpp"

void game_loop::init()
{
    rect.createRectangleShape("./assets/raccoon.jpeg", (sf::Vector2f){219,230}, (sf::Vector2f){0,0});
    text.createText("Salut!", "./assets/arial.ttf", 10, (sf::Vector2f){500,100});
}

void game_loop::loop()
{
    while (win.isOpen()) {
        event();
        win.clear(sf::Color::Black);
        draw();
        win.display();
    }
}

void game_loop::event()
{
    sf::Event event;
    while (win.pollEvent(event)) {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            win.close();
    }
}

void game_loop::draw()
{
    rect.drawRectangleShape(win);
    text.drawText(win);
}
