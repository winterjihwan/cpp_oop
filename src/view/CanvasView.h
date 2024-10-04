#ifndef CANVAS_VIEW_H
#define CANVAS_VIEW_H

#include <SFML/Graphics.hpp>
#include <vector>

// Canvas_view 클래스 정의
class Canvas_view
{
private:
  sf::RenderWindow *window; // sf::RenderWindow 포인터로 변경하여 외부 윈도우를 사용
  // 원래는 독립적인 RenderWindow 객체를 가지고 있었으나, main에서 전달받도록 수정함
public:
  // 기존 생성자를 변경하여 포인터를 받도록 수정
  Canvas_view(sf::RenderWindow *window);

  // 도형을 화면에 렌더링하는 메서드
  void render(std::vector<sf::Drawable *> shapes);

  // 업데이트 메서드 (추가적인 처리 필요 시 사용)
  void update_view(std::vector<sf::Drawable *> shapes);
};

#endif // CANVAS_VIEW_H
