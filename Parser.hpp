/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

enum Input {
    NONE,
    RESTART,
    ESC,
    MENU,
    PAUSE,
    UP,
    LEFT,
    RIGHT,
    SWITCH
};

class Parser {
    public:
        Parser();
        ~Parser();

        void level1();
        void level2();
        void level3();

    protected:
    private:
        std::map<int, std::string> _map1;
        std::map<int, std::string> _map2;
        std::map<int, std::string> _map3;
        std::list<Input> Inputs;
        sf::Event Event;
        sf::RenderWindow window;
        sf::Music music;
};

#endif /* !PARSER_HPP_ */
