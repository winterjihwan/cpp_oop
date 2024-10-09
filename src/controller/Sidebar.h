#ifndef SIDEBAR_H
#define SIDEBAR_H

#include "../model/Shape.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

class Sidebar {
public:
  Sidebar(float width, float height);
  void render(sf::RenderWindow &window);
  std::string handleClick(const sf::Vector2f &clickPosition);

private:
  sf::RectangleShape sidebarRect;
  std::vector<std::unique_ptr<Shape>> previewShapes;
  std::vector<sf::RectangleShape> buttons;
  std::vector<std::string> buttonLabels;

  void initializeButtons();
  void createPreviews();
};

#endif // SIDEBAR_H
