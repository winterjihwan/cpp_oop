#include "./controller/CanvasController.h"
#include "./factories/EllipseFactory.h"
#include "./factories/LineFactory.h"
#include "./factories/RectangleFactory.h"
#include "./state/ContextState.h"
#include "./state/PropertyState.h"
#include "./state/SidebarState.h"
#include "./state/UIContext.h"
#include "./view/CanvasView.h"
#include "./view/Sidebar.h"
#include "./view/StatusView.h"
#include "factories/ImageFactory.h"
#include "factories/TextFactory.h"
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode(1200, 800), "Miridi Project",
                          sf::Style::Titlebar | sf::Style::Close);

  RectangleFactory rectangleFactory;
  EllipseFactory ellipseFactory;
  LineFactory lineFactory;
  TextFactory textFactory;
  ImageFactory imageFactory("apple.png");
  Canvas_view canvas_view(&window);
  StatusView status_view(&window);
  Sidebar sidebar(200.0f, 800.0f);
  Model model;

  CanvasController controller(&rectangleFactory, &ellipseFactory, &lineFactory,
                              &textFactory, &imageFactory, &canvas_view,
                              &status_view, &sidebar, &model);

  model.attach(std::make_shared<StatusView>(status_view));

  SidebarState sidebarState;
  ContextState contextState;
  PropertyState propertyState;
  UIContext uiContext(&sidebarState, &contextState, &propertyState);

  while (window.isOpen()) {
    sf::Event event;
    sf::Vector2f mousePos =
        window.mapPixelToCoords(sf::Mouse::getPosition(window));

    uiContext.updateState(mousePos.x, static_cast<float>(window.getSize().x));

    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::MouseButtonPressed &&
          event.mouseButton.button == sf::Mouse::Left) {
        uiContext.getState()->handleMousePress(mousePos, controller, uiContext);
      }

      if (event.type == sf::Event::MouseMoved) {
        uiContext.getState()->handleMouseMove(mousePos, controller, uiContext);
      }

      if (event.type == sf::Event::MouseButtonReleased &&
          event.mouseButton.button == sf::Mouse::Left) {
        uiContext.getState()->handleMouseRelease(mousePos, controller,
                                                 uiContext);
      }

      if (event.type == sf::Event::TextEntered) {
        uiContext.getState()->handleTextInput(
            static_cast<char>(event.text.unicode), status_view, uiContext);
      }

      if (event.type == sf::Event::KeyPressed) {
        bool isCtrlPressed =
            sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);

        if (isCtrlPressed) {
          if (event.key.code == sf::Keyboard::Z) {
            controller.undo();
          } else if (event.key.code == sf::Keyboard::Y) {
            controller.redo();
          }
        } else {
          uiContext.getState()->handleKeyPress(event.key.code, controller,
                                               status_view);
        }
      }
    }

    window.clear(sf::Color::White);
    controller.sort_shapes_by_z();
    controller.render_shapes();
    sidebar.render(window);
    status_view.render(controller.isSingleSelection()
                           ? controller.getSelectedShape()
                           : nullptr);
    window.display();
  }

  return 0;
}
