#include "StatusView.h"
#include <sstream>
#include <stdexcept>

// Constructor
StatusView::StatusView(sf::RenderWindow *window) : window(window)
{
    // Load the font (adjust path as needed)
    if (!font.loadFromFile("../FiraCode-Regular.ttf"))
    {
        throw std::runtime_error("Failed to load font");
    }

    // Configure the background rectangle for the status bar
    statusBar.setSize({window->getSize().x * 0.2f, static_cast<float>(window->getSize().y)});
    statusBar.setPosition(window->getSize().x * 0.8f, 0);  // Position it at the right edge
    statusBar.setFillColor(sf::Color(220, 220, 220, 255)); // Light grey background color
}

// Render method to display status information
void StatusView::render(const Shape *shape)
{
    // Draw the status bar background
    window->draw(statusBar);

    if (shape != nullptr)
    {
        // Display selected shape's information
        std::ostringstream posStream, colorStream, sizeStream;

        // Format position text
        posStream << "Position: (" << shape->getPosition().x << ", " << shape->getPosition().y << ")";
        positionText = posStream.str();

        // Format color text
        sf::Color shapeColor = shape->getColor();
        colorStream << "Color: (R: " << static_cast<int>(shapeColor.r)
                    << ", G: " << static_cast<int>(shapeColor.g)
                    << ", B: " << static_cast<int>(shapeColor.b) << ")";
        colorText = colorStream.str();

        // Format size text
        sizeStream << "Size: (" << shape->getSize().x << ", " << shape->getSize().y << ")";
        sizeText = sizeStream.str();

        // Display each text string at designated positions within the status bar
        displayText(positionText, {window->getSize().x * 0.8f + 10, 20});
        displayText(colorText, {window->getSize().x * 0.8f + 10, 60});
        displayText(sizeText, {window->getSize().x * 0.8f + 10, 100});
    }
    else
    {
        // If no shape is selected, display blank status view
        displayText("Position: ", {window->getSize().x * 0.8f + 10, 20});
        displayText("Color: ", {window->getSize().x * 0.8f + 10, 60});
        displayText("Size: ", {window->getSize().x * 0.8f + 10, 100});
    }
}

// Clear the status view display by redrawing the blank status background
void StatusView::clear()
{
    // Draw the status bar background
    window->draw(statusBar);

    // Clear the displayed information by displaying empty strings
    displayText("", {window->getSize().x * 0.8f + 10, 20});
    displayText("", {window->getSize().x * 0.8f + 10, 60});
    displayText("", {window->getSize().x * 0.8f + 10, 100});
}

// Helper function to display text at a specific position on the window
void StatusView::displayText(const std::string &text, const sf::Vector2f &position)
{
    sf::Text displayText;
    displayText.setFont(font); // Set the font for the text
    displayText.setString(text);
    displayText.setPosition(position);
    displayText.setCharacterSize(14);           // Set a readable size for the text
    displayText.setFillColor(sf::Color::Black); // Set the text color

    window->draw(displayText);
}
