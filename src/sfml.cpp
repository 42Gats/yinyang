/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** sfml
*/

#include "sfml.hpp"

void game_loop::init()
{
    this->game_status = 1;
    rect.createRectangleShape("./assets/raccoon.jpeg", (sf::Vector2f){219,230}, (sf::Vector2f){0,0});
    text.createText("Salut!", "./assets/arial.ttf", 10, (sf::Vector2f){500,100});
    this->menu_assets.resize(6);
    this->menu_assets[0].createRectangleShape("./ressources/menu/menu_back.png", (sf::Vector2f){1920,1080}, (sf::Vector2f){-30,0});
    this->menu_assets[1].createRectangleShape("./ressources/menu/play.png", (sf::Vector2f){200,200}, (sf::Vector2f){825,700});
    this->menu_assets[2].createRectangleShape("./ressources/menu/play_c.png", (sf::Vector2f){200,200}, (sf::Vector2f){825,700});
    this->menu_assets[3].createRectangleShape("./ressources/menu/defeat_screan.png", (sf::Vector2f){1880,1040}, (sf::Vector2f){-30,0});
    this->menu_assets[4].createRectangleShape("./ressources/menu/return.png", (sf::Vector2f){200,200}, (sf::Vector2f){1470,740});
    this->menu_assets[5].createRectangleShape("./ressources/menu/return_c.png", (sf::Vector2f){200,200}, (sf::Vector2f){1470,740});
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
        if (this->game_status == 1 && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
            sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            if (this->menu_assets[2].dimensions(0).contains(mousePositionFloat)) {
                    this->game_status = 3;
            }
        }
        if (this->game_status == 3 && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
            sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            if (this->menu_assets[5].dimensions(0).contains(mousePositionFloat)) {
                    this->game_status = 1;
            }
        }
    }
}

void game_loop::draw()
{
    rect.drawRectangleShape(win);
    text.drawText(win);
    if (this->game_status == 1) {
        this->menu_assets[0].drawRectangleShape(win);
        if (sf::Mouse::getPosition(win).x >= 825 && sf::Mouse::getPosition(win).x <= 1025 && sf::Mouse::getPosition(win).y >= 700 && sf::Mouse::getPosition(win).y <= 900) {
            this->menu_assets[2].drawRectangleShape(win);
        } else
            this->menu_assets[1].drawRectangleShape(win);
    }
    if (this->game_status == 3) {
        this->menu_assets[3].drawRectangleShape(win);
        if (sf::Mouse::getPosition(win).x >= 1470 && sf::Mouse::getPosition(win).x <= 1670 && sf::Mouse::getPosition(win).y >= 740 && sf::Mouse::getPosition(win).y <= 940) {
            this->menu_assets[5].drawRectangleShape(win);
        } else
            this->menu_assets[4].drawRectangleShape(win);
    }
}
