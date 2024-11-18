#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "../model/Shape.h"
#include "../observer/observer.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>

class Sidebar : public Observer {
public:
  Sidebar(float width, float height);

  void render(sf::RenderWindow &window);
  std::string handleClick(const sf::Vector2f &clickPosition);
  void update() override;

private:
  sf::RectangleShape sidebarRect;
  std::vector<std::shared_ptr<Shape>> previewShapes;
  std::vector<sf::RectangleShape> buttons;
  std::vector<std::string> buttonLabels;

  void initializeButtons();
  void createPreviews();
};

#endif // SIDEBAR_H
