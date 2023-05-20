/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser()
{
    std::ifstream infile("./ressources/maps/level1.txt");
    std::string line;
    int x = 0;
    for (; std::getline(infile, line); x++)
        this->_map1[x] = line;
    std::ifstream infile2("./ressources/maps/level2.txt");
    std::string line2;
    int y = 0;
    for (; std::getline(infile2, line2); y++)
        this->_map2[y] = line2;
    std::ifstream infile3("./ressources/maps/level3.txt");
    std::string line3;
    int z = 0;
    for (; std::getline(infile3, line3); z++)
        this->_map3[z] = line3;
    this->_color = sf::Color::White;
    
}

Parser::~Parser()
{
}

void Parser::level1(sf::RenderWindow window)
{
    std::string filepath = "./ressources/music/level1.ogg";
    if (music.getStatus() == music.Playing)
        music.stop();
    if (music.openFromFile(filepath)) {
        music.play();
        music.setVolume(50);
        music.setLoop(true);
    }
    while (window.pollEvent(Event)) {
        if (Event.type == sf::Event::Closed)
            this->Inputs.push_front(ESC);
        if (Event.type == sf::Event::KeyPressed) {
            if (Event.key.code == sf::Keyboard::Escape)
                this->Inputs.push_front(ESC);
            if (Event.key.code == sf::Keyboard::R)
                this->Inputs.push_front(RESTART);
            if (Event.key.code == sf::Keyboard::M)
                this->Inputs.push_front(MENU);
            if (Event.key.code == sf::Keyboard::Up)
                this->Inputs.push_front(UP);
            if (Event.key.code == sf::Keyboard::Left)
                this->Inputs.push_front(LEFT);
            if (Event.key.code == sf::Keyboard::Right)
                this->Inputs.push_front(RIGHT);
            if (Event.key.code == sf::Keyboard::Enter){
                if (this->_color == sf::Color::White)
                    this->_color = sf::Color::Black;
                else
                    this->_color = sf::Color::White;
            }
        }
    }
    window.clear();
    std::vector<std::string> color = {" ", "W", "B"};
    std::vector<sf::Color> color2 = {_color, sf::Color::White, sf::Color::Black};
    std::vector<float> size = {32, 32, 32};
    size_t i = 0;
    size_t j = 0;
    for (; i < _map1.size(); i++) {
        for (j = 0; j < _map1[i].size(); j++) {
            for (size_t k = 0; k < color.size(); k++) {
                if (_map1[i][j] == color[k][0]) {
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f(size[k], size[k]));
                    rect.setFillColor(color2[k]);
                    rect.setPosition(j * 20 + (10 - (size[k]/2)), i * 20 + (10 - (size[k]/2)));
                    window.draw(rect);
                }
            }
        }
    }
    window.display();
}

void Parser::level2(sf::RenderWindow window)
{
    std::string filepath = "./ressources/music/level2.ogg";
    if (music.getStatus() == music.Playing)
        music.stop();
    if (music.openFromFile(filepath)) {
        music.play();
        music.setVolume(50);
        music.setLoop(true);
    }
    while (window.pollEvent(Event)) {
        if (Event.type == sf::Event::Closed)
            this->Inputs.push_front(ESC);
        if (Event.type == sf::Event::KeyPressed) {
            if (Event.key.code == sf::Keyboard::Escape)
                this->Inputs.push_front(ESC);
            if (Event.key.code == sf::Keyboard::R)
                this->Inputs.push_front(RESTART);
            if (Event.key.code == sf::Keyboard::M)
                this->Inputs.push_front(MENU);
            if (Event.key.code == sf::Keyboard::Up)
                this->Inputs.push_front(UP);
            if (Event.key.code == sf::Keyboard::Left)
                this->Inputs.push_front(LEFT);
            if (Event.key.code == sf::Keyboard::Right)
                this->Inputs.push_front(RIGHT);
            if (Event.key.code == sf::Keyboard::Enter){
                if (this->_color == sf::Color::White)
                    this->_color = sf::Color::Black;
                else
                    this->_color = sf::Color::White;
            }
        }
    }
    window.clear();
    std::vector<std::string> color = {" ", "W", "B"};
    std::vector<sf::Color> color2 = {_color, sf::Color::White, sf::Color::Black};
    std::vector<float> size = {32, 32, 32};
    size_t i = 0;
    size_t j = 0;
    for (; i < _map2.size(); i++) {
        for (j = 0; j < _map2[i].size(); j++) {
            for (size_t k = 0; k < color.size(); k++) {
                if (_map2[i][j] == color[k][0]) {
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f(size[k], size[k]));
                    rect.setFillColor(color2[k]);
                    rect.setPosition(j * 20 + (10 - (size[k]/2)), i * 20 + (10 - (size[k]/2)));
                    window.draw(rect);
                }
            }
        }
    }
    window.display();
}

void Parser::level3(sf::RenderWindow window)
{
    std::string filepath = "./ressources/music/level3.ogg";
    if (music.getStatus() == music.Playing)
        music.stop();
    if (music.openFromFile(filepath)) {
        music.play();
        music.setVolume(50);
        music.setLoop(true);
    }
    while (window.pollEvent(Event)) {
        if (Event.type == sf::Event::Closed)
            this->Inputs.push_front(ESC);
        if (Event.type == sf::Event::KeyPressed) {
            if (Event.key.code == sf::Keyboard::Escape)
                this->Inputs.push_front(ESC);
            if (Event.key.code == sf::Keyboard::R)
                this->Inputs.push_front(RESTART);
            if (Event.key.code == sf::Keyboard::M)
                this->Inputs.push_front(MENU);
            if (Event.key.code == sf::Keyboard::Up)
                this->Inputs.push_front(UP);
            if (Event.key.code == sf::Keyboard::Left)
                this->Inputs.push_front(LEFT);
            if (Event.key.code == sf::Keyboard::Right)
                this->Inputs.push_front(RIGHT);
            if (Event.key.code == sf::Keyboard::Enter) {
                if (this->_color == sf::Color::White)
                    this->_color = sf::Color::Black;
                else
                    this->_color = sf::Color::White;
            }
        }
    }
    window.clear();
    std::vector<std::string> color = {" ", "W", "B"};
    std::vector<sf::Color> color2 = {_color, sf::Color::White, sf::Color::Black};
    std::vector<float> size = {32, 32, 32};
    size_t i = 0;
    size_t j = 0;
    for (; i < _map3.size(); i++) {
        for (j = 0; j < _map3[i].size(); j++) {
            for (size_t k = 0; k < color.size(); k++) {
                if (_map3[i][j] == color[k][0]) {
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f(size[k], size[k]));
                    rect.setFillColor(color2[k]);
                    rect.setPosition(j * 20 + (10 - (size[k]/2)), i * 20 + (10 - (size[k]/2)));
                    window.draw(rect);
                }
            }
        }
    }
    window.display();
}