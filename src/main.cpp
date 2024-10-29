#include "./controller/CanvasController.h"
#include "./model/EllipseFactory.h"
#include "./model/LineFactory.h"
#include "./model/RectangleFactory.h"
#include "./view/CanvasView.h"
#include "./view/Sidebar.h"
#include "./view/StatusView.h"
#include "model/TextFactory.h"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(1200, 800), "Miridi project",
                          sf::Style::Titlebar | sf::Style::Close);

  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;
  TextFactory textFactory;
  Canvas_view canvas_view(&window);
  StatusView status_view(&window);
  Sidebar sidebar(200.0f, 800.0f);

  Canvas_controller controller(&rectangleFactory, &ellipseFactory, &lineFactory,
                               &textFactory, &canvas_view, &status_view,
                               &sidebar);

  sf::Vector2f initial_click_position;
  bool is_dragging = false;
  bool shouldCreateShape = false; // New flag to track creation

  while (window.isOpen()) {
    sf::Event event;
    bool shapeChanged = false;

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos =
            window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // Check if click is within the sidebar area
        if (mousePos.x <= 200.0f) {
          controller.handleSidebarClick(mousePos);
          shouldCreateShape = true; // Set flag to create shape on next click
        } else {
          // Check if we should create a new shape or select an existing one
          if (shouldCreateShape) {
            // Create shape at clicked position
            controller.create_shape(controller.getSelectedShapeType(),
                                    mousePos);
            shouldCreateShape = false; // Reset flag after creation
          } else {
            // Select shape on canvas
            initial_click_position = mousePos;
            controller.select_shape(initial_click_position);
            is_dragging = controller.getSelectedShape() != nullptr;
            shapeChanged = true;
          }
        }

        // StatusView interactions
        if (status_view.getPosXEntry().getGlobalBounds().contains(mousePos))
          status_view.setFocusedField(StatusView::FocusedField::PosX);
        else if (status_view.getPosYEntry().getGlobalBounds().contains(
                     mousePos))
          status_view.setFocusedField(StatusView::FocusedField::PosY);
        else if (status_view.getSizeXEntry().getGlobalBounds().contains(
                     mousePos))
          status_view.setFocusedField(StatusView::FocusedField::SizeX);
        else if (status_view.getSizeYEntry().getGlobalBounds().contains(
                     mousePos))
          status_view.setFocusedField(StatusView::FocusedField::SizeY);
        else
          status_view.setFocusedField(StatusView::FocusedField::None);
      }

      if (event.type == sf::Event::MouseMoved && is_dragging) {
        sf::Vector2f new_position =
            window.mapPixelToCoords(sf::Mouse::getPosition(window));
        controller.move_shape(new_position);
        shapeChanged = true;
      }

      if (event.type == sf::Event::MouseButtonReleased &&
          event.mouseButton.button == sf::Mouse::Left) {
        is_dragging = false;
        controller.end_drag();
        shapeChanged = true;
      }

      if (event.type == sf::Event::TextEntered) {
        status_view.handleTextInput(static_cast<char>(event.text.unicode));
      }

      if (event.type == sf::Event::KeyPressed &&
          event.key.code == sf::Keyboard::Enter) {
        if (controller.getSelectedShape()) {
          status_view.applyChanges(controller.getSelectedShape());
          shapeChanged = true;
        }
      }
    }

    window.clear(sf::Color::White);

    controller.render_shapes();
    sidebar.render(window);
    status_view.render(controller.getSelectedShape());

    window.display();
  }

  return 0;
}
