#ifndef STATUSVIEW_H
#define STATUSVIEW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Shape.h"

class StatusView
{
public:
    StatusView(sf::RenderWindow *window);

    void render(const Shape *shape); // Display details of the selected shape
    void clear();                    // Clear the displayed information (now public)

private:
    sf::RenderWindow *window;
    sf::Font font;
    sf::RectangleShape statusBar; // Add status bar background as a rectangle

    // Text placeholders
    std::string positionText;
    std::string colorText;
    std::string sizeText;

    // Helper function to format and display text
    void displayText(const std::string &text, const sf::Vector2f &position);
};

#endif // STATUSVIEW_H
