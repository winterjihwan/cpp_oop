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

  // Shape* 타입의 벡터를 받아들임
  void render(std::vector<Shape *> shapes);
  void update_view(std::vector<Shape *> shapes);
};

#endif // CANVAS_VIEW_H
