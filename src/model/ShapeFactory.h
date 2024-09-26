#include <SFML/Graphics.hpp>

class Shape_factory {
public:
  virtual ~Shape_factory() = default;

  virtual sf::Drawable *createShape() = 0;
};
