/*
** EPITECH PROJECT, 2023
** test
** File description:
** rectangleshape
*/

#ifndef RECTANGLESHAPE_HPP_
    #define RECTANGLESHAPE_HPP_
    #include "../../includes/include.hpp"

class RectangleShape {
    public:
        RectangleShape();
        void createRectangleShape(std::string texture, sf::Vector2f size, sf::Vector2f pos);
        void setPos(int i, sf::Vector2f pos) {
            rect_tab[i].setPosition(pos);
        };
        void setTextRect(int i, sf::IntRect rect) {
            rect_tab[i].setTextureRect(rect);
        };
        sf::FloatRect dimensions(int i) const;
        sf::Vector2f getPos(int i) const;
        sf::Vector2f getSize(int i) const {
            return (rect_tab[i].getSize());
        };
        sf::RectangleShape getRect(int i) const {
            return (rect_tab[i]);
        };
        size_t size() const {
            return (rect_tab.size());
        };
        void drawRectangleShape(sf::RenderWindow &window) const;
        ~RectangleShape();
    protected:
    private:
        std::vector<sf::RectangleShape> rect_tab;
        std::vector<sf::Texture> texture_tab;
};


#endif /* !RECTANGLESHAPE_HPP_ */
