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
    #include "level_selector.hpp"
    #define JUMP 3
    #define HEIGHT_JUMP 21

class game_loop {
    public:
        game_loop();
        ~game_loop() {
            this->music.stop();
            this->win.close();
            delete this->view;
            delete this->view1;
        };
        void loop();
        int event();
        void draw();
        void jump();
        void level1();
        void level2();
        void level3();
    private:
        sf::RenderWindow win;
        RectangleShape _rect;
        Text text;
        std::vector<RectangleShape> menu_assets;
        level_selector selector_menu;
        int game_status;
        int save_game;


        std::map<int, std::string> _map1;
        std::map<int, std::string> _map2;
        std::map<int, std::string> _map3;
        sf::Color _color;
        std::list<Input> Inputs;
        sf::Event Event;
        sf::Music music;
        int song_volume;

        sf::Clock clock;
        sf::Time deltaTime;
        int speed_jump;

        std::vector<sf::RectangleShape> _rect_tab;

        sf::View *view;
        sf::View *view1;

        int movement = 0;

        sf::RectangleShape _perso;
        sf::Texture _texture_perso;
        sf::IntRect _rect_perso;

};

#endif /* !SFML_HPP_ */
