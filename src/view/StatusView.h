#ifndef STATUSVIEW_H
#define STATUSVIEW_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Shape.h"

class StatusView
{
public:
    StatusView(sf::RenderWindow *window);

    enum class FocusedField { None, PosX, PosY, SizeX, SizeY };

    void render(const Shape *shape);                // Display details of the selected shape
    void clear();                                   // Clear the displayed information
    void handleTextInput(char inputChar);           // Handles keyboard input for entries
    void applyChanges(Shape *shape);                // Apply the input field values to the shape
    void setFocusedField(FocusedField field);       // Set the focused field for input

    // Getter functions for bounds checking in main.cpp
    const sf::Text& getPosXEntry() const { return posXEntryText; }
    const sf::Text& getPosYEntry() const { return posYEntryText; }
    const sf::Text& getSizeXEntry() const { return sizeXEntryText; }
    const sf::Text& getSizeYEntry() const { return sizeYEntryText; }

private:
    sf::RenderWindow *window;
    sf::Font font;
    sf::RectangleShape statusBar; // Status bar background

    FocusedField focusedField = FocusedField::None; // Track focused field

    // Labels for attributes
    sf::Text positionLabel;
    sf::Text colorLabel;
    sf::Text sizeLabel;

    // Text display objects for editable fields
    sf::Text posXEntryText;
    sf::Text posYEntryText;
    sf::Text sizeXEntryText;
    sf::Text sizeYEntryText;

    // String values for editable fields (to store user input)
    std::string posXEntryValue;
    std::string posYEntryValue;
    std::string sizeXEntryValue;
    std::string sizeYEntryValue;

    // Non-editable display for color information
    sf::Text colorValue;

    void displayText(const std::string &text, const sf::Vector2f &position);
    void updateEntryFields(const Shape *shape);
};

#endif // STATUSVIEW_H
