#include <SFML/Graphics.hpp>

class Rectangle : public sf::Drawable {
  sf::RectangleShape shape;

public:
  Rectangle(float width, float height, float x_coor, float y_coor, int z);

  float get_width();
  float get_height();

  void set_size(Rectangle &rect, float width, float height);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
