/*
** EPITECH PROJECT, 2023
** test
** File description:
** text
*/

#include "Text.hpp"

Text::Text()
{
}

Text::~Text()
{
}

void Text::createText(std::string sentence, std::string font, unsigned int size, sf::Vector2f pos)
{
    // Text
    sf::Text text;
    text.setPosition(pos);
    text.setString(sentence);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::White);

    // Font
    sf::Font t;
    t.loadFromFile(font);
    text.setFont(t);
    
    // push in list
    text_tab.push_back(text);
    font_tab.push_back(t);
}

void Text::drawText(sf::RenderWindow &window) const
{
    auto it2 = font_tab.begin();
    for (auto it = text_tab.begin(); it != text_tab.end() && it2 != font_tab.end(); it++, it2++) {
        sf::Text text = *it;
        text.setFont(*it2);
        window.draw(text);
    }
}

sf::Vector2f Text::getPos(int i)
{
    return (text_tab[i].getPosition());
}

void Text::setSentence(std::string sentence)
{
    text_tab[0].setString(sentence);
}
