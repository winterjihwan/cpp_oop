#include "CanvasView.h"
#include <vector>

Canvas_view::Canvas_view(sf::RenderWindow *window) : window{window} {}

void Canvas_view::render(const std::vector<std::shared_ptr<Shape>> &shapes)
{
  for (const auto &shape : shapes)
  {
    if (shape)
    {
      window->draw(*shape);
    }
  }
}

void Canvas_view::update_view(const std::vector<std::shared_ptr<Shape>> &shapes)
{
  for (const auto &shape : shapes)
  {
    if (shape)
    {
      window->draw(*shape);
    }
  }
}
