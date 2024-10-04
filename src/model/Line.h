#ifndef LINE_H
#define LINE_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

// 선 도형 클래스 정의
class Line : public Shape {
private:
  sf::VertexArray line; // SFML의 VertexArray를 사용하여 선 표현

public:
  // 생성자
  Line(float startX, float startY, float endX, float endY);

  // getWidth와 getHeight 메서드 선언
  float get_width() const;
  float get_height() const;

  // 특정 위치가 선 내부에 있는지 확인하는 메서드
  bool isSelected(const sf::Vector2f &point) const override;

  // set_size 메서드 선언
  void set_size(float width, float height);

  // 위치 반환 메서드
  sf::Vector2f getPosition() const override;

  // 위치 설정 메서드
  void setPosition(const sf::Vector2f &position) override;

  // 크기 반환 메서드
  sf::Vector2f getSize() const override;

  // 크기 설정 메서드
  void setSize(const sf::Vector2f &size) override;

  // SFML Drawable의 draw 메서드 오버라이드
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // LINE_H
