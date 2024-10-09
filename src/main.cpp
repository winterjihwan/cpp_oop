#include "controller/CanvasController.h"
#include "model/EllipseFactory.h"
#include "model/LineFactory.h"
#include "model/RectangleFactory.h"
#include "view/CanvasView.h"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600),
                          "Shape Factory Pattern Example");

  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;
  Canvas_view canvas_view(&window);
  Canvas_controller controller(&rectangleFactory, &ellipseFactory, &lineFactory,
                               &canvas_view);

  // Create shapes
  controller.create_rectangle();
  controller.create_ellipse();
  controller.create_line();

  sf::Vector2f initial_click_position;
  bool is_dragging = false;

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      // Start dragging on mouse press
      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          initial_click_position =
              window.mapPixelToCoords(sf::Mouse::getPosition(window));
          controller.select_shape(initial_click_position);
          is_dragging = controller.getSelectedShape() != nullptr;
        }
      }

      // Move shape if dragging
      if (event.type == sf::Event::MouseMoved && is_dragging) {
        sf::Vector2f new_position =
            window.mapPixelToCoords(sf::Mouse::getPosition(window));
        controller.move_shape(new_position);
        controller.render_shapes(); // render_shapes() 호출하여 위치 업데이트 후
                                    // 전체 렌더링
      }

      // Stop dragging on mouse release
      if (event.type == sf::Event::MouseButtonReleased) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          is_dragging = false;
          controller.end_drag(); // Ensure dragging ends
        }
      }
    }

    window.clear();
    controller
        .render_shapes(); // Ensure shapes are rendered only once per frame
    window.display();
  }

  return 0;
}
