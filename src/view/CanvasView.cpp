#include "CanvasView.h"
#include <vector>

// 생성자: 포인터로 전달받은 윈도우 객체 사용
Canvas_view::Canvas_view(sf::RenderWindow *window) : window{window} {}

// render: Shape* 타입의 벡터를 받아서 렌더링
void Canvas_view::render(const std::vector<Shape *> &shapes)
{
  // Only draw shapes without clearing or displaying
  for (Shape *shape : shapes)
  {
    if (shape != nullptr)
    {
      window->draw(*shape); // Draw each shape at its current position
    }
  }
}

// update_view: 화면을 지우지 않고 도형의 위치를 업데이트하여 표시
void Canvas_view::update_view(const std::vector<Shape *> &shapes)
{
  // Similar to render but without clearing or displaying the window
  for (Shape *shape : shapes)
  {
    if (shape != nullptr)
    {
      window->draw(*shape); // Redraw each shape without clearing the screen
    }
  }
}
