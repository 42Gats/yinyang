/*
** EPITECH PROJECT, 2023
** yinyang
** File description:
** sfml
*/

#include "sfml.hpp"

game_loop::game_loop()
{
    std::string filepath = "./ressources/music/no1.ogg";
    if (music.openFromFile(filepath)) {
        music.play();
        music.setVolume(50);
        music.setLoop(true);
    }
    win.create(sf::VideoMode(1920, 1080), "YinYang");
    win.setFramerateLimit(60);
    this->game_status = 1;



    _perso = sf::RectangleShape(sf::Vector2f(32, 32));
    _texture_perso = sf::Texture();
    _texture_perso.loadFromFile("./ressources/character/TiM_anim2.png");
    _perso.setTexture(&_texture_perso);
    _perso.setPosition(sf::Vector2f(100, 100));
    _rect_perso = sf::IntRect(0, 0, 32, 32);

    this->menu_assets.resize(6);
    this->menu_assets[0].createRectangleShape("./ressources/menu/menu_back.png", (sf::Vector2f){1920,1080}, (sf::Vector2f){-30,0});
    this->menu_assets[1].createRectangleShape("./ressources/menu/play.png", (sf::Vector2f){200,200}, (sf::Vector2f){825,700});
    this->menu_assets[2].createRectangleShape("./ressources/menu/play_c.png", (sf::Vector2f){200,200}, (sf::Vector2f){825,700});
    this->menu_assets[3].createRectangleShape("./ressources/menu/defeat_screen.jpg", (sf::Vector2f){1880,1040}, (sf::Vector2f){-30,0});
    this->menu_assets[4].createRectangleShape("./ressources/menu/return.png", (sf::Vector2f){200,200}, (sf::Vector2f){1470,800});
    this->menu_assets[5].createRectangleShape("./ressources/menu/return_c.png", (sf::Vector2f){200,200}, (sf::Vector2f){1470,800});
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

    this->speed_jump = -1;
}

void game_loop::loop()
{
    while (win.isOpen()) {
        if (event() == 84)
            return;
        win.clear(sf::Color::Black);
        if (this->game_status == 1) {
            draw();
            win.display();
        }
        if (this->game_status == 3) {
            draw();
            win.display();
        }
        if (this->game_status == 4)
            this->level1();
        if (this->game_status == 5)
            this->level2();
        if (this->game_status == 6)
            this->level3();
        deltaTime += clock.restart();
    }
}

int game_loop::event()
{
    while (win.pollEvent(Event)) {
         if (this->game_status == 1 && Event.type == sf::Event::MouseButtonPressed && Event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
            sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            if (this->menu_assets[2].dimensions(0).contains(mousePositionFloat)) {
                    this->game_status = 3;
            }
        }
        if (this->game_status == 3 && Event.type == sf::Event::MouseButtonPressed && Event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
            sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            if (this->menu_assets[5].dimensions(0).contains(mousePositionFloat)) {
                    this->game_status = 1;
            }
        }
        if (Event.type == sf::Event::Closed)
            return (84);
        if (Event.type == sf::Event::KeyPressed) {
            if (Event.key.code == sf::Keyboard::Escape)
                return (84);
            if (Event.key.code == sf::Keyboard::M)
                this->game_status = 1;
            if (Event.key.code == sf::Keyboard::Up) {
                speed_jump = 0;
            }
            if (Event.key.code == sf::Keyboard::Left) {
                if (this->game_status > 4)
                    this->game_status -= 1;
            }
            if (Event.key.code == sf::Keyboard::Right) {
                if (this->game_status < 6)
                    this->game_status += 1;
            }
            if (Event.key.code == sf::Keyboard::Enter){
                if (this->_color == sf::Color::White)
                    this->_color = sf::Color::Black;
                else
                    this->_color = sf::Color::White;
            }
        }
    }
    if (deltaTime >= sf::seconds(0.1) && speed_jump >= 0 && speed_jump <= 20) {
        _perso.setPosition(sf::Vector2f(_perso.getPosition().y - 20 - speed_jump, _perso.getPosition().x));
        speed_jump += 1;
    } else {
        speed_jump = -1;
    }
    return (0);
}

void game_loop::draw()
{
    if (this->game_status == 1) {
        this->menu_assets[0].drawRectangleShape(win);
        if (sf::Mouse::getPosition(win).x >= 825 && sf::Mouse::getPosition(win).x <= 1025 && sf::Mouse::getPosition(win).y >= 700 && sf::Mouse::getPosition(win).y <= 900) {
            this->menu_assets[2].drawRectangleShape(win);
        } else
            this->menu_assets[1].drawRectangleShape(win);
    }
    if (this->game_status == 3) {
        this->menu_assets[3].drawRectangleShape(win);
        if (sf::Mouse::getPosition(win).x >= 1470 && sf::Mouse::getPosition(win).x <= 1670 && sf::Mouse::getPosition(win).y >= 800 && sf::Mouse::getPosition(win).y <= 1000) {
            this->menu_assets[5].drawRectangleShape(win);
        } else
            this->menu_assets[4].drawRectangleShape(win);
    }
}

void game_loop::level1()
{
    win.clear();
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
                    win.draw(rect);
                }
            }
        }
    }
    sf::RectangleShape rect = _perso;
    win.draw(rect);



    if (deltaTime.asMilliseconds() >= 50) {
        if (_rect_perso.left + 32 < 128) {
            _rect_perso = sf::IntRect(_rect_perso.left + 32, 0, 32, 32);
            deltaTime = sf::seconds(0);
        } else {
            _rect_perso = sf::IntRect(0, 0, 32, 32);
            deltaTime = sf::seconds(0);
        }
        _perso.setTextureRect(_rect_perso);
    }

    
    win.display();
}

void game_loop::level2()
{
    win.clear();
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
                    win.draw(rect);
                }
            }
        }
    }
    win.display();
}

void game_loop::level3()
{
    win.clear();
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
                    win.draw(rect);
                }
            }
        }
    }
    win.display();
}