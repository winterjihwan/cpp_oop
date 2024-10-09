#include "controller/CanvasController.h"
#include "controller/Sidebar.h"
#include "model/EllipseFactory.h"
#include "model/LineFactory.h"
#include "model/RectangleFactory.h"
#include "model/TextFactory.h"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 600),
                          "Shape Factory Pattern Example");
  window.setVerticalSyncEnabled(true);

  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;
  TextFactory textFactory;
  Canvas_view canvasView(&window);
  Sidebar sidebar(200.0f, 600.0f);
  Canvas_controller controller(&rectangleFactory, &ellipseFactory, &lineFactory,
                               &textFactory, &canvasView, &sidebar);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      // Handle mouse clicks
      if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          sf::Vector2f clickPosition =
              window.mapPixelToCoords(sf::Mouse::getPosition(window));

          // If click is within the sidebar's area
          if (clickPosition.x <= 200.0f) {
            controller.handleSidebarClick(clickPosition);
          } else {
            // Create a shape on the canvas at the click position
            controller.create_shape(controller.getSelectedShapeType(),
                                    clickPosition);
          }
        }
      }
    }

    window.clear(sf::Color::White); // Clear the window
    controller.render_shapes();     // Render the shapes on the canvas
    sidebar.render(window);         // Render the sidebar
    window.display();               // Display the rendered frame
  }

  return 0;
}
