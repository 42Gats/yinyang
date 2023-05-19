/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP_
    #include "../includes/include.hpp"
    #include "GameObjects/Text.hpp"
    #include "GameObjects/Rectangleshape.hpp"

class game_loop {
    public:
        void init();
        void loop();
        void event();
        void draw();
    private:
        sf::RenderWindow win = sf::RenderWindow(sf::VideoMode(1920, 1080), "Raccoon Window");
        RectangleShape rect;
        Text text;
};

#endif /* !SFML_HPP_ */
