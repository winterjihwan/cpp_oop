#include "CanvasView.h"
#include <vector>

// 생성자: 포인터로 전달받은 윈도우 객체 사용
Canvas_view::Canvas_view(sf::RenderWindow *window)
    : window{window} {}

void Canvas_view::render(std::vector<sf::Drawable *> shapes)
{
  window->clear(sf::Color::Black); // 화면 지우기
  for (sf::Drawable *shape : shapes)
  {
    window->draw(*shape); // 각 도형을 현재 위치에 그리기
  }
  window->display(); // 새로운 프레임을 표시
}

// update_view: 화면을 지우지 않고 도형의 위치를 업데이트하여 표시
void Canvas_view::update_view(std::vector<sf::Drawable *> shapes)
{
  for (sf::Drawable *shape : shapes)
  {
    window->draw(*shape); // 위치만 업데이트하고 다시 그리기
  }
  window->display(); // 기존 화면에 업데이트된 도형만 표시
}