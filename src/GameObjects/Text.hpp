/*
** EPITECH PROJECT, 2023
** test
** File description:
** text
*/

#ifndef TEXT_HPP_
    #define TEXT_HPP_
    #include "../../includes/include.hpp"

class Text {
    public:
        Text();
        void createText(std::string sentence, std::string font, unsigned int size, sf::Vector2f pos);
        void drawText(sf::RenderWindow &window) const;
        void setSentence(std::string sentence);
        void colorText(int i, sf::Color color);
        sf::Vector2f getPos(int i);
        ~Text();
    protected:
    private:
        std::vector<sf::Text> text_tab;
        std::vector<sf::Font> font_tab;
};

#endif /* !TEXT_HPP_ */
