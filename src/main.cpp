#include <SFML/Graphics.hpp>
#include <iostream>
#include "RectangleFactory.h"
#include "EllipseFactory.h"
#include "LineFactory.h"
#include "CanvasController.h"
#include "CanvasView.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Shape Factory Pattern Example");

  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;
  Canvas_view canvas_view(&window);
  Canvas_controller controller(&rectangleFactory, &ellipseFactory, &lineFactory, &canvas_view);

  controller.create_rectangle();
  controller.create_ellipse();
  controller.create_line();

  sf::Vector2f initial_click_position;
  bool is_dragging = false;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::MouseButtonPressed)
      {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
          initial_click_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
          controller.select_shape(initial_click_position);
          is_dragging = controller.getSelectedShape() != nullptr;
        }
      }

      if (event.type == sf::Event::MouseMoved && is_dragging)
      {
        sf::Vector2f new_position = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        controller.move_shape(new_position);
      }

      if (event.type == sf::Event::MouseButtonReleased)
      {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
          is_dragging = false;
          controller.end_drag(); // 드래그 종료
        }
      }
    }

    window.clear();
    controller.render_shapes();
    window.display();
  }

  return 0;
}
