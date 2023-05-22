#include "level_selector.hpp"

level_selector::level_selector()
{
    RectangleShape caracter;
    RectangleShape level1;
    RectangleShape level2;
    RectangleShape level3;
    RectangleShape po;
    RectangleShape po2;
    RectangleShape po3;
    RectangleShape po4;
    RectangleShape po5;
    RectangleShape ying;
    RectangleShape ying2;
    RectangleShape ying3;
    RectangleShape ying4;
    RectangleShape ying5;

    animation = 64;

    caracter.createRectangleShape(std::string("ressources/character/TiM_anim1.png"), sf::Vector2f(128, 32), sf::Vector2f(450, 500));
    level1.createRectangleShape(std::string("ressources/menu/button_1.png"), sf::Vector2f(200, 200), sf::Vector2f(400, 300));
    level2.createRectangleShape(std::string("ressources/menu/button_2.png"), sf::Vector2f(200, 200), sf::Vector2f(800, 300));
    level3.createRectangleShape(std::string("ressources/menu/button_3.png"), sf::Vector2f(200, 200), sf::Vector2f(1200, 300));
    po.createRectangleShape(std::string("ressources/menu/po.png"), sf::Vector2f(130, 120), sf::Vector2f(200, 200));
    po2.createRectangleShape(std::string("ressources/menu/po.png"), sf::Vector2f(130, 120), sf::Vector2f(600, 600));
    po3.createRectangleShape(std::string("ressources/menu/po.png"), sf::Vector2f(130, 120), sf::Vector2f(1000, 300));
    po4.createRectangleShape(std::string("ressources/menu/po.png"), sf::Vector2f(130, 120), sf::Vector2f(1400, 900));
    po5.createRectangleShape(std::string("ressources/menu/po.png"), sf::Vector2f(130, 120), sf::Vector2f(1800, 600));
    ying.createRectangleShape(std::string("ressources/menu/ying.png"), sf::Vector2f(120, 108), sf::Vector2f(200, 800));
    ying2.createRectangleShape(std::string("ressources/menu/ying.png"), sf::Vector2f(120, 108), sf::Vector2f(1500, 100));
    ying3.createRectangleShape(std::string("ressources/menu/ying.png"), sf::Vector2f(120, 108), sf::Vector2f(1000, 800));
    // level1.setTextRect(0, sf::IntRect(0, 0, 200, 200));
    // level2.setTextRect(0, sf::IntRect(0, 0, 200, 200));
    caracter.setTextRect(0, sf::IntRect(animation, 0, 32, 32));
    // level3.setTextRect(0, sf::IntRect(0, 0, 200, 200));
    selector_assets.push_back(caracter);
    selector_assets.push_back(level1);
    selector_assets.push_back(level2);
    selector_assets.push_back(level3);
    selector_assets.push_back(po);
    selector_assets.push_back(po2);
    selector_assets.push_back(po3);
    selector_assets.push_back(po4);
    selector_assets.push_back(po5);
    selector_assets.push_back(ying);
    selector_assets.push_back(ying2);
    selector_assets.push_back(ying3);
    Text text;
    text.createText("Choose Level", "./assets/thepolice.ttf", 120, (sf::Vector2f){570,80});
    text.colorText(0, sf::Color::Black);
    selector_text.push_back(text);
    is_moving = 1;
    level_selected = 1;
}

void level_selector::draw(sf::RenderWindow &win)
{
    animation += 2;
    if (animation == 128)
        animation = 0;
    if (animation % 32 == 0)
        selector_assets[0].setTextRect(0, sf::IntRect(animation, 0, 32, 32));
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