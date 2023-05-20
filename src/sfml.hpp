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
    #include "Parser/Parser.hpp"

class game_loop {
    public:
        game_loop();
        ~game_loop() {
            this->music.stop();
            this->win.close();
        };
        void loop();
        int event();
        void draw();

        void level1();
        void level2();
        void level3();
    private:
        sf::RenderWindow win;
        RectangleShape rect;
        Text text;
        std::vector<RectangleShape> menu_assets;
        int game_status;


        std::map<int, std::string> _map1;
        std::map<int, std::string> _map2;
        std::map<int, std::string> _map3;
        sf::Color _color;
        std::list<Input> Inputs;
        sf::Event Event;
        sf::Music music;
};

#endif /* !SFML_HPP_ */
