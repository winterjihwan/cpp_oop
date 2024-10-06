#include "controller/CanvasController.h"
#include "model/EllipseFactory.h"
#include "model/ImageFactory.h"
#include "model/LineFactory.h"
#include "model/RectangleFactory.h"
#include "model/TextFactory.h"
#include "view/CanvasView.h"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600),
                          "Shape Factory Pattern Example");

  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;
  TextFactory textFactory;
  ImageFactory imageFactory;
  Canvas_view canvas_view(&window);
  Canvas_controller controller(&rectangleFactory, &ellipseFactory, &lineFactory,
                               &textFactory, &imageFactory, &canvas_view);

  /*controller.create_rectangle();*/
  /*controller.create_ellipse();*/
  /*controller.create_line();*/
  /*controller.create_text();*/
  /*controller.create_text();*/
  controller.create_image();

  sf::Vector2f initial_click_position;
  bool is_dragging = false;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          initial_click_position =
              window.mapPixelToCoords(sf::Mouse::getPosition(window));
          controller.select_shape(initial_click_position);
          is_dragging = controller.getSelectedShape() != nullptr;
        }
      }

      if (event.type == sf::Event::MouseMoved && is_dragging) {
        sf::Vector2f new_position =
            window.mapPixelToCoords(sf::Mouse::getPosition(window));
        controller.move_shape(new_position);
        controller.render_shapes();
      }

      if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          is_dragging = false;
          controller.end_drag();
        }
      }
    }

    window.clear();
    controller.render_shapes();
    window.display();
  }

  return 0;
}
