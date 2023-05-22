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
    this->menu_assets.resize(15);
    this->menu_assets[0].createRectangleShape("./ressources/menu/menu_back.png", (sf::Vector2f){1920,1080}, (sf::Vector2f){-30,0});
    this->menu_assets[1].createRectangleShape("./ressources/menu/play.png", (sf::Vector2f){200,200}, (sf::Vector2f){825,700});
    this->menu_assets[2].createRectangleShape("./ressources/menu/play_c.png", (sf::Vector2f){200,200}, (sf::Vector2f){825,700});
    this->menu_assets[3].createRectangleShape("./ressources/menu/defeat_screen.jpg", (sf::Vector2f){1880,1040}, (sf::Vector2f){-30,0});
    this->menu_assets[4].createRectangleShape("./ressources/menu/return.png", (sf::Vector2f){200,200}, (sf::Vector2f){1470,800});
    this->menu_assets[5].createRectangleShape("./ressources/menu/return_c.png", (sf::Vector2f){200,200}, (sf::Vector2f){1470,800});
    this->menu_assets[6].createRectangleShape("./ressources/menu/pause_menu.png", (sf::Vector2f){1000,700}, (sf::Vector2f){450,150});
    this->menu_assets[7].createRectangleShape("./ressources/menu/play.png", (sf::Vector2f){100,100}, (sf::Vector2f){675,650});
    this->menu_assets[8].createRectangleShape("./ressources/menu/play_c.png", (sf::Vector2f){100,100}, (sf::Vector2f){675,650});
    this->menu_assets[9].createRectangleShape("./ressources/menu/return.png", (sf::Vector2f){100,100}, (sf::Vector2f){1125,650});
    this->menu_assets[10].createRectangleShape("./ressources/menu/return_c.png", (sf::Vector2f){100,100}, (sf::Vector2f){1125,650});
    this->menu_assets[11].createRectangleShape("./ressources/menu/more.png", (sf::Vector2f){50,50}, (sf::Vector2f){770,470});
    this->menu_assets[12].createRectangleShape("./ressources/menu/more_c.png", (sf::Vector2f){50,50}, (sf::Vector2f){770,470});
    this->menu_assets[13].createRectangleShape("./ressources/menu/less.png", (sf::Vector2f){50,50}, (sf::Vector2f){1070,470});
    this->menu_assets[14].createRectangleShape("./ressources/menu/less_c.png", (sf::Vector2f){50,50}, (sf::Vector2f){1070,470});
    this->text.createText("0", "./assets/arial.ttf", 50, (sf::Vector2f){920, 470});
    this->text.colorText(0, sf::Color::White);
    this->song_volume = 50;
    this->save_game = 4;
    this->text.setSentence(std::to_string(this->song_volume));
    this->view = new sf::View(sf::FloatRect(0, 0, 640, 230));
    this->view1 = new sf::View(sf::FloatRect(0, 0, 1920, 1080));
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

    this->speed_jump = HEIGHT_JUMP;
}

void game_loop::loop()
{
    while (win.isOpen())
    {
        if (event() == 84)
            return;
        if (this->game_status == 10 || this->game_status == 7)
            win.clear(sf::Color::White);
        else
            win.clear(sf::Color::Black);
        if (this->game_status == 1)
        {
            win.setView(*view1);
            draw();
            win.display();
        }
        if (this->game_status == 3)
        {
            win.setView(*view1);
            draw();
            win.display();
        }
        if (this->game_status == 7)
        {
            win.setView(*view1);
            draw();
            win.display();
        }
        if (this->game_status == 4)
        {
            win.setView(*view);
            this->level1();
        }
        if (this->game_status == 5)
        {
            win.setView(*view);
            this->level2();
        }
        if (this->game_status == 6)
        {
            win.setView(*view);
            this->level3();
        }
        if (this->game_status == 10)
        {
            selector_menu.draw(win);
            win.display();
        }
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
                this->game_status = 10;
            }
        }
        if (this->game_status == 3 && Event.type == sf::Event::MouseButtonPressed && Event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
            sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            if (this->menu_assets[5].dimensions(0).contains(mousePositionFloat)) {
                this->game_status = 1;
            }
        }
        if (this->game_status == 7 && Event.type == sf::Event::MouseButtonPressed && Event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(win);
            sf::Vector2f mousePositionFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
            if (this->menu_assets[10].dimensions(0).contains(mousePositionFloat)) {
                this->game_status = 1;
            }
            if (this->menu_assets[8].dimensions(0).contains(mousePositionFloat)) {
                this->game_status = this->save_game;
            }
            if (sf::Mouse::getPosition(win).x >= 740 && sf::Mouse::getPosition(win).x <= 790 && sf::Mouse::getPosition(win).y >= 445 && sf::Mouse::getPosition(win).y <= 495) {
                if (this->song_volume < 100)
                    this->song_volume += 10;
                this->text.setSentence(std::to_string(this->song_volume));
                this->music.setVolume(this->song_volume);
            }
            if (sf::Mouse::getPosition(win).x >= 1040 && sf::Mouse::getPosition(win).x <= 1090 && sf::Mouse::getPosition(win).y >= 445 && sf::Mouse::getPosition(win).y <= 495) {
                if (this->song_volume > 0)
                    this->song_volume -= 10;
                this->text.setSentence(std::to_string(this->song_volume));
                this->music.setVolume(this->song_volume);
            }
        }
        if (Event.type == sf::Event::Closed)
            return (84);
        if (Event.type == sf::Event::KeyPressed) {
            if (Event.key.code == sf::Keyboard::Escape)
                return (84);
            if (Event.key.code == sf::Keyboard::M)
                this->game_status = 1;
            if (Event.key.code == sf::Keyboard::Space && this->game_status != 1) {
                if (jump_ok == true)
                    speed_jump = 0;
            }
            if (Event.key.code == sf::Keyboard::Enter && this->game_status != 10) {
                if (this->_color == sf::Color::White)
                    this->_color = sf::Color::Black;
                else
                    this->_color = sf::Color::White;
            }
            // Selector menu
            if (Event.key.code == sf::Keyboard::Right && this->game_status == 10) {
                if (selector_menu.getLevelSelected() < 3)
                    selector_menu.move(selector_menu.getLevelSelected() + 1);
            }
            if (Event.key.code == sf::Keyboard::Left && this->game_status == 10) {
                if (selector_menu.getLevelSelected() > 0)
                    selector_menu.move(selector_menu.getLevelSelected() - 1);
            }
            if (Event.key.code == sf::Keyboard::Enter && this->game_status == 10) {
                this->game_status = selector_menu.getLevelSelected() + 3;
            }
            if (Event.key.code == sf::Keyboard::A && this->game_status <= 6 && this->game_status >= 4) {
                this->save_game = this->game_status;
                this->game_status = 7;
            }
        }
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
    if (this->game_status == 7) {
        this->menu_assets[6].drawRectangleShape(win);
        this->text.setSentence(std::to_string(this->song_volume));
        this->text.drawText(win);
        if (sf::Mouse::getPosition(win).x >= 675 && sf::Mouse::getPosition(win).x <= 775 && sf::Mouse::getPosition(win).y >= 600 && sf::Mouse::getPosition(win).y <= 700) {
            this->menu_assets[8].drawRectangleShape(win);
        } else
            this->menu_assets[7].drawRectangleShape(win);
        if (sf::Mouse::getPosition(win).x >= 1125 && sf::Mouse::getPosition(win).x <= 1225 && sf::Mouse::getPosition(win).y >= 600 && sf::Mouse::getPosition(win).y <= 700) {
            this->menu_assets[10].drawRectangleShape(win);
        } else
            this->menu_assets[9].drawRectangleShape(win);
        if (sf::Mouse::getPosition(win).x >= 740 && sf::Mouse::getPosition(win).x <= 790 && sf::Mouse::getPosition(win).y >= 445 && sf::Mouse::getPosition(win).y <= 495) {
            this->menu_assets[12].drawRectangleShape(win);
        } else
            this->menu_assets[11].drawRectangleShape(win);
        if (sf::Mouse::getPosition(win).x >= 1040 && sf::Mouse::getPosition(win).x <= 1090 && sf::Mouse::getPosition(win).y >= 445 && sf::Mouse::getPosition(win).y <= 495) {
            this->menu_assets[14].drawRectangleShape(win);
        } else
            this->menu_assets[13].drawRectangleShape(win);
    }
}

void game_loop::jump()
{
    if (deltaTime.asMilliseconds() >= 50) {
        movement += 10;

        _perso.setPosition(sf::Vector2f(_perso.getPosition().x, _perso.getPosition().y - HEIGHT_JUMP + speed_jump));
        speed_jump += JUMP;

        for (size_t i = 0; i < _rect_tab.size(); i++) {
            sf::Color fillcolor = _rect_tab[i].getFillColor();

            if (_color == sf::Color::Black && fillcolor == sf::Color::White) {
                sf::RectangleShape rect = _rect_tab[i];
                rect.setPosition(sf::Vector2f(rect.getPosition().x, rect.getPosition().y));
                sf::FloatRect entity = rect.getGlobalBounds();
                sf::FloatRect player = _perso.getGlobalBounds();
                if (player.intersects(entity)) {
                    speed_jump = HEIGHT_JUMP * 2;
                    jump_ok = true;
                    _perso.setPosition(sf::Vector2f(_perso.getPosition().x, rect.getPosition().y - player.height - 2));
                    break;
                } else {
                    jump_ok = false;
                }
            }
            if (_color == sf::Color::White && fillcolor == sf::Color::Black) {
                sf::RectangleShape rect = _rect_tab[i];
                rect.setPosition(sf::Vector2f(rect.getPosition().x, rect.getPosition().y));
                sf::FloatRect entity = rect.getGlobalBounds();
                sf::FloatRect player = _perso.getGlobalBounds();
                if (player.intersects(entity)) {
                    speed_jump =  HEIGHT_JUMP * 2;
                    jump_ok = true;
                    _perso.setPosition(sf::Vector2f(_perso.getPosition().x, rect.getPosition().y - player.height - 2));
                    break;
                } else {
                    jump_ok = false;
                }
            }
        }
        
        if (_rect_perso.left + 32 < 128) {
            _rect_perso = sf::IntRect(_rect_perso.left + 32, 0, 32, 32);
            deltaTime = sf::seconds(0);
        } else {
            _rect_perso = sf::IntRect(0, 0, 32, 32);
            deltaTime = sf::seconds(0);
        }
        _perso.setTextureRect(_rect_perso);
    }
    if (_perso.getPosition().y >= 260) {
        movement = 0;
        speed_jump =  HEIGHT_JUMP * 2;
        jump_ok = true;
        _perso.setPosition(sf::Vector2f(_perso.getPosition().x, 100));
        this->game_status = 3;
        this->_color = sf::Color::White;
    }
    for (size_t i = 0; i < _rect_tab.size(); i++) {
        sf::Color fillcolor = _rect_tab[i].getFillColor();

        if (_color == sf::Color::Black && fillcolor == sf::Color::White) {
            sf::RectangleShape rect = _rect_tab[i];
            rect.setPosition(sf::Vector2f(rect.getPosition().x, rect.getPosition().y + 10));
            sf::FloatRect entity = rect.getGlobalBounds();
            sf::FloatRect player = _perso.getGlobalBounds();
            if (player.intersects(entity)) {
                movement = 0;
                speed_jump =  HEIGHT_JUMP * 2;
                jump_ok = true;
                _perso.setPosition(sf::Vector2f(_perso.getPosition().x, 100));
                this->game_status = 3;
                this->_color = sf::Color::White;
            }
        }
        if (_color == sf::Color::White && fillcolor == sf::Color::Black) {
            sf::RectangleShape rect = _rect_tab[i];
            rect.setPosition(sf::Vector2f(rect.getPosition().x, rect.getPosition().y + 10));
            sf::FloatRect entity = rect.getGlobalBounds();
            sf::FloatRect player = _perso.getGlobalBounds();
            if (player.intersects(entity)) {
                movement = 0;
                speed_jump =  HEIGHT_JUMP * 2;
                jump_ok = true;
                _perso.setPosition(sf::Vector2f(_perso.getPosition().x, 100));
                this->game_status = 3;
                this->_color = sf::Color::White;
            }
        }
        if (movement >= 1830 && this->game_status < 6)
            this->game_status++;
        else if (movement >= 1830)
            this->game_status = 4;
    }
    sf::RectangleShape rect = _perso;
    win.draw(rect);
}

void game_loop::level1()
{
    win.clear();
    std::vector<std::string> color = {" ", "W", "B"};
    std::vector<sf::Color> color2 = {_color, sf::Color::White, sf::Color::Black};
    std::vector<float> size = {32, 32, 32};
    size_t i = 0;
    size_t j = 0;
    _rect_tab.clear();
    for (; i < _map1.size(); i++) {
        for (j = 0; j < _map1[i].size(); j++) {
            for (size_t k = 0; k < color.size(); k++) {
                if (_map1[i][j] == color[k][0]) {
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f(size[k], size[k]));
                    rect.setFillColor(color2[k]);
                    rect.setPosition((j * 20 + (10 - (size[k]/2))) - movement, i * 20 + (10 - (size[k]/2)));
                    win.draw(rect);
                    _rect_tab.push_back(rect);
                }
            }
        }
    }
    jump();
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
    _rect_tab.clear();
    for (; i < _map2.size(); i++) {
        for (j = 0; j < _map2[i].size(); j++) {
            for (size_t k = 0; k < color.size(); k++) {
                if (_map2[i][j] == color[k][0]) {
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f(size[k], size[k]));
                    rect.setFillColor(color2[k]);
                    rect.setPosition((j * 20 + (10 - (size[k]/2))) - movement, i * 20 + (10 - (size[k]/2)));
                    win.draw(rect);
                    _rect_tab.push_back(rect);
                }
            }
        }
    }
    jump();
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
    _rect_tab.clear();
    for (; i < _map3.size(); i++) {
        for (j = 0; j < _map3[i].size(); j++) {
            for (size_t k = 0; k < color.size(); k++) {
                if (_map3[i][j] == color[k][0]) {
                    sf::RectangleShape rect;
                    rect.setSize(sf::Vector2f(size[k], size[k]));
                    rect.setFillColor(color2[k]);
                    rect.setPosition((j * 20 + (10 - (size[k]/2))) - movement, i * 20 + (10 - (size[k]/2)));
                    win.draw(rect);
                    _rect_tab.push_back(rect);
                }
            }
        }
    }
    jump();
    win.display();
}