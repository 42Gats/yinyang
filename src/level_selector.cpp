#include "level_selector.hpp"

level_selector::level_selector()
{
    RectangleShape caracter;
    RectangleShape level1;
    RectangleShape level2;
    RectangleShape level3;

    caracter.createRectangleShape(std::string("ressources/character/TiM_anim1.png"), sf::Vector2f(100, 100), sf::Vector2f(400, 600));
    level1.createRectangleShape(std::string("ressources/level/level1.png"), sf::Vector2f(100, 100), sf::Vector2f(100, 100));
    level2.createRectangleShape(std::string("ressources/level/level2.png"), sf::Vector2f(100, 100), sf::Vector2f(100, 100));
    level3.createRectangleShape(std::string("ressources/level/level3.png"), sf::Vector2f(100, 100), sf::Vector2f(100, 100));
    selector_assets.push_back(caracter);
    selector_assets.push_back(level1);
    selector_assets.push_back(level2);
    selector_assets.push_back(level3);
    Text text;
    text.createText("Choose Level", "./assets/arial.ttf", 10, (sf::Vector2f){500,100});
    selector_text.push_back(text);
}

void level_selector::draw(sf::RenderWindow &win)
{
    for (size_t i = 0; i < selector_assets.size(); i++)
        selector_assets[i].drawRectangleShape(win);
    for (size_t i = 0; i < selector_text.size(); i++)
        selector_text[i].drawText(win);
}

void level_selector::move(int moving_on)
{   
    if (is_moving == 0) {
        is_moving = 1;
        if (moving_on == 1) {
            level_selected = 1;
            selector_assets[0].createRectangleShape(std::string("ressources/character/TiM_anim1.png"), sf::Vector2f(100, 100), sf::Vector2f(400, 600));
        } else if (moving_on == 2) {
            level_selected = 2;
            selector_assets[0].createRectangleShape(std::string("ressources/character/TiM_anim1.png"), sf::Vector2f(100, 100), sf::Vector2f(700, 600));
        } else if (moving_on == 3) {
            level_selected = 3;
            selector_assets[0].createRectangleShape(std::string("ressources/character/TiM_anim1.png"), sf::Vector2f(100, 100), sf::Vector2f(1000, 600));
        }
    }
}