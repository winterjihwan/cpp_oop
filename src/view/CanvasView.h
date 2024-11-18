#ifndef CANVAS_VIEW_H
#define CANVAS_VIEW_H

#include "../model/Shape.h"
#include "../observer/observer.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Canvas_view : public Observer {
private:
  sf::RenderWindow *window;

public:
  Canvas_view(sf::RenderWindow *window);

  void render(const std::vector<std::shared_ptr<Shape>> &shapes);

  void update_view(const std::vector<std::shared_ptr<Shape>> &shapes);

  void update() override;
};

#endif // CANVAS_VIEW_H
