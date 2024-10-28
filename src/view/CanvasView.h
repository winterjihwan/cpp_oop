#ifndef CANVAS_VIEW_H
#define CANVAS_VIEW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "../model/Shape.h" // Shape 클래스 포함

class Canvas_view
{
private:
  sf::RenderWindow *window; // 윈도우 객체

public:
  // 생성자
  Canvas_view(sf::RenderWindow *window);

  // Draws all shapes without clearing or displaying the window
  void render(const std::vector<Shape *> &shapes);

  // Updates the view with new positions of shapes without clearing or displaying
  void update_view(const std::vector<Shape *> &shapes);
};

#endif // CANVAS_VIEW_H
