#include <SFML/Graphics.hpp>
#include <vector>

class Canvas_view {
  sf::RenderWindow window;

public:
  Canvas_view(int width, int height)
      : window{sf::VideoMode(width, height), "oop cpp"} {};

  void render(std::vector<sf::Drawable *> shapes);
  void update_view(std::vector<sf::Drawable *> shapes);
};
