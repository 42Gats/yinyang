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
        sf::FloatRect dimensions(int i) const;
        sf::Vector2f getPos(int i) const;
        void drawRectangleShape(sf::RenderWindow &window) const;
        ~RectangleShape();
    protected:
    private:
        std::vector<sf::RectangleShape> rect_tab;
        std::vector<sf::Texture> texture_tab;
};


#endif /* !RECTANGLESHAPE_HPP_ */
