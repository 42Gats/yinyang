/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** level_selector
*/

#ifndef LEVEL_SELECTOR_HPP_
#define LEVEL_SELECTOR_HPP_

#include "sfml.hpp"

class level_selector {
    public:
        level_selector();
        void draw(sf::RenderWindow &win);
        void move(int moving_on);
    private:
        std::vector<RectangleShape> selector_assets;
        std::vector<Text> selector_text;
        int is_moving;
        int level_selected;
};

#endif /* !LEVEL_SELECTOR_HPP_ */
