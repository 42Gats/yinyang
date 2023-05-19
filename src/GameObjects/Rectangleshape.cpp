/*
** EPITECH PROJECT, 2023
** test
** File description:
** rectangleshape
*/

#include "Rectangleshape.hpp"

RectangleShape::RectangleShape()
{
}

RectangleShape::~RectangleShape()
{
}

void RectangleShape::createRectangleShape(std::string texture, sf::Vector2f size, sf::Vector2f pos)
{
    // rectangleshape
    sf::RectangleShape rectangle;
    rectangle.setSize(size);
    rectangle.setPosition(pos);

    // texture
    sf::Texture t;
    t.setSmooth(true);
    t.loadFromFile(texture);
    rectangle.setTexture(&t);
    
    // push in list
    rect_tab.push_back(rectangle);
    texture_tab.push_back(t);
}

void RectangleShape::drawRectangleShape(sf::RenderWindow &window) const
{
    auto it2 = texture_tab.begin();
    for (auto it = rect_tab.begin(); it != rect_tab.end() && it2 != texture_tab.end(); it++, it2++) {
        sf::RectangleShape rec = *it;
        rec.setTexture(&*it2);
        window.draw(rec);
    }
}

sf::FloatRect RectangleShape::dimensions(int i) const
{
    return (rect_tab[i].getGlobalBounds());
}

sf::Vector2f RectangleShape::getPos(int i) const
{
    return (rect_tab[i].getPosition());
}

