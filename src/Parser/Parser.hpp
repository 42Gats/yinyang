/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_
    #include "../../includes/include.hpp"

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
