#include <SFML/Graphics.hpp>
#include <iostream>
#include "RectangleFactory.h"
#include "EllipseFactory.h"
#include "LineFactory.h"
#include "CanvasController.h"
#include "CanvasView.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1200, 800), "Shape Factory Pattern Example", sf::Style::Titlebar | sf::Style::Close);

  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;
  Canvas_view canvas_view(&window);
  StatusView status_view(&window);
  Canvas_controller controller(&rectangleFactory, &ellipseFactory, &lineFactory, &canvas_view, &status_view);

  // Create shapes
  controller.create_rectangle();
  controller.create_ellipse();
  controller.create_line();

  sf::Vector2f initial_click_position;
  bool is_dragging = false;

  while (window.isOpen())
  {
    sf::Event event;
    bool shapeChanged = false; // Flag to track changes in shape positions or selection

    // Process events
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      // Start dragging on mouse press
      if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
      {
        initial_click_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        controller.select_shape(initial_click_position);
        is_dragging = controller.getSelectedShape() != nullptr;
        shapeChanged = true; // Mark that a change occurred
      }

      // Move shape if dragging
      if (event.type == sf::Event::MouseMoved && is_dragging)
      {
        sf::Vector2f new_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        controller.move_shape(new_position);
        shapeChanged = true; // Mark that a change occurred
      }

      // Stop dragging on mouse release
      if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
      {
        is_dragging = false;
        controller.end_drag(); // Ensure dragging ends
        shapeChanged = true;   // Mark that a change occurred
      }
    }

    // Render only if a change has occurred
    if (shapeChanged || controller.isStatusViewDirty)
    {
      window.clear(sf::Color::White); // Clear the screen at the beginning of a new frame

      // Render shapes
      controller.render_shapes();

      // Only render status view if there is a change in selection or shape properties
      if (controller.isStatusViewDirty)
      {
        status_view.render(controller.getSelectedShape());
        controller.isStatusViewDirty = false; // Reset the dirty flag
      }

      window.display(); // Display the updated frame
    }
  }

  return 0;
}
