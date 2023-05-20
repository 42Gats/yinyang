#include "level_selector.hpp"

level_selector::level_selector()
{
    RectangleShape caracter;
    RectangleShape level1;
    RectangleShape level2;
    RectangleShape level3;

    caracter.createRectangleShape(std::string("ressources/character/TiM_anim1.png"), sf::Vector2f(128, 32), sf::Vector2f(450, 500));
    level1.createRectangleShape(std::string("ressources/menu/button_1.png"), sf::Vector2f(200, 200), sf::Vector2f(400, 300));
    level2.createRectangleShape(std::string("ressources/menu/button_2.png"), sf::Vector2f(200, 200), sf::Vector2f(800, 300));
    level3.createRectangleShape(std::string("ressources/menu/button_3.png"), sf::Vector2f(200, 200), sf::Vector2f(1200, 300));
    // level1.setTextRect(0, sf::IntRect(0, 0, 200, 200));
    // level2.setTextRect(0, sf::IntRect(0, 0, 200, 200));
    caracter.setTextRect(0, sf::IntRect(0, 0, 32, 32));
    // level3.setTextRect(0, sf::IntRect(0, 0, 200, 200));
    selector_assets.push_back(caracter);
    selector_assets.push_back(level1);
    selector_assets.push_back(level2);
    selector_assets.push_back(level3);
    Text text;
    text.createText("Choose Level", "./assets/thepolice.ttf", 120, (sf::Vector2f){570,80});
    text.colorText(0, sf::Color::Black);
    selector_text.push_back(text);
    is_moving = 0;
    level_selected = 1;
}

void level_selector::draw(sf::RenderWindow &win)
{
    for (size_t i = 0; i < selector_assets.size(); i++) {
        selector_assets[i].drawRectangleShape(win);
    }
    for (size_t i = 0; i < selector_text.size(); i++)
        selector_text[i].drawText(win);
}

int level_selector::getLevelSelected()
{
    return (level_selected);
}

void level_selector::move(int moving_on)
{   
    // if (is_moving == 0) {
    //     is_moving = 1;
    // }
    std::cout << "moving on : " << moving_on << std::endl;
    if (moving_on == 1)
    {
        level_selected = moving_on;
        selector_assets[0].setPos(0, sf::Vector2f(450, 500));
    }
    else if (moving_on == 2)
    {
        level_selected = moving_on;
        selector_assets[0].setPos(0, sf::Vector2f(850, 500));
    }
    else if (moving_on == 3)
    {
        level_selected = moving_on;
        selector_assets[0].setPos(0, sf::Vector2f(1250, 500));
    }
}