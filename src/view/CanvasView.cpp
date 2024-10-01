#include "CanvasView.h"
#include <vector>

// 생성자: 포인터로 전달받은 윈도우 객체 사용
Canvas_view::Canvas_view(sf::RenderWindow *window)
    : window{window} {}

// 도형을 화면에 렌더링
void Canvas_view::render(std::vector<sf::Drawable *> shapes)
{
  window->clear(sf::Color::Black); // 윈도우 지우기

  // 각 도형을 윈도우에 그리기
  for (sf::Drawable *shape : shapes)
  {
    window->draw(*shape);
  }

  window->display(); // 윈도우 업데이트
}

// 업데이트 메서드 (현재 빈 메서드로 유지)
void Canvas_view::update_view(std::vector<sf::Drawable *> shapes)
{
  // 추가적인 업데이트 로직을 구현할 때 사용 가능
}
