#ifndef CANVAS_VIEW_H
#define CANVAS_VIEW_H

#include "../model/Shape.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Canvas_view {
private:
  sf::RenderWindow *window;

public:
  Canvas_view(sf::RenderWindow *window);

  void render(const std::vector<Shape *> &shapes);

  void update_view(const std::vector<Shape *> &shapes);
};

#endif // CANVAS_VIEW_H
