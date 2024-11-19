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

  void update(const std::vector<std::shared_ptr<Shape>> &shapes) override;
};

#endif // CANVAS_VIEW_H
