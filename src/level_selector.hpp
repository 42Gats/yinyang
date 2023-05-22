/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** level_selector
*/

#ifndef LEVEL_SELECTOR_HPP_
#define LEVEL_SELECTOR_HPP_

#include "GameObjects/Rectangleshape.hpp"
#include "GameObjects/Text.hpp"
#include "../includes/include.hpp"
class level_selector {
    public:
        level_selector();
        void draw(sf::RenderWindow &win);
        void move(int moving_on);
        int getLevelSelected();
    private:
        std::vector<RectangleShape> selector_assets;
        std::vector<Text> selector_text;
        int is_moving;
        int level_selected;
        int animation;
};

#endif /* !LEVEL_SELECTOR_HPP_ */
