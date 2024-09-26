#include <SFML/Graphics.hpp>

class Renderer {
  sf::RenderWindow window;

public:
  Renderer(int width, int height)
      : window{sf::VideoMode(width, height), "oop cpp"} {};
  void render(sf::RenderWindow *window);
};
