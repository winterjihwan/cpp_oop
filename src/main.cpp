#include "./controller/CanvasController.h"
#include "./model/EllipseFactory.h"
#include "./model/LineFactory.h"
#include "./model/RectangleFactory.h"
#include "./view/CanvasView.h"
#include "./view/StatusView.h"
#include "model/TextFactory.h"
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
  sf::RenderWindow window(sf::VideoMode(1200, 800), "Miridi project",
                          sf::Style::Titlebar | sf::Style::Close);

  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;
  TextFactory textFactory;
  Canvas_view canvas_view(&window);
  StatusView status_view(&window);
  Canvas_controller controller(&rectangleFactory, &ellipseFactory, &lineFactory,
                               &textFactory, &canvas_view, &status_view);

  controller.create_rectangle();
  controller.create_ellipse();
  controller.create_line();
  controller.create_text();

  sf::Vector2f initial_click_position;
  bool is_dragging = false;

  while (window.isOpen()) {
    sf::Event event;
    bool shapeChanged =
        false; // Flag to track changes in shape positions or selection

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos =
            window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // Check if click is within status view bounds
        float statusViewXStart = window.getSize().x * 0.7f;
        if (mousePos.x < statusViewXStart) {
          // If clicking in the canvas area, proceed with selection/deselection
          initial_click_position = mousePos;
          controller.select_shape(initial_click_position);
          is_dragging = controller.getSelectedShape() != nullptr;
          shapeChanged = true;
        }

        // Set focus to a specific entry field in StatusView if clicked
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

      // Handle mouse movement for dragging
      if (event.type == sf::Event::MouseMoved && is_dragging) {
        sf::Vector2f new_position =
            window.mapPixelToCoords(sf::Mouse::getPosition(window));
        controller.move_shape(new_position);
        shapeChanged = true;
      }

      // Stop dragging on mouse release
      if (event.type == sf::Event::MouseButtonReleased &&
          event.mouseButton.button == sf::Mouse::Left) {
        is_dragging = false;
        controller.end_drag();
        shapeChanged = true;
      }

      // Handle text entry for position and size fields in StatusView
      if (event.type == sf::Event::TextEntered) {
        std::cout << "Text entered: " << event.text.unicode << std::endl;
        // Pass the entered character to StatusView for editing
        status_view.handleTextInput(static_cast<char>(event.text.unicode));
      }

      // Apply changes on pressing Enter
      if (event.type == sf::Event::KeyPressed &&
          event.key.code == sf::Keyboard::Enter) {
        if (controller.getSelectedShape()) {
          status_view.applyChanges(controller.getSelectedShape());
          shapeChanged = true;
        }
      }
    }

    // Clear the window at the start of each frame
    window.clear(sf::Color::White);

    // Render shapes in the canvas view
    controller.render_shapes();

    // Render the status view, which will always display on the right
    status_view.render(controller.getSelectedShape());

    // Update the display with all drawn elements
    window.display();
  }

  return 0;
}
