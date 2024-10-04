#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

// 타원 도형 클래스 정의
class Ellipse : public Shape {
private:
  sf::CircleShape ellipse; // SFML의 원 도형을 사용하여 타원 구현

public:
  // 생성자
  Ellipse(float x, float y, float radiusX, float radiusY);

  // getWidth와 getHeight 메서드 선언
  float get_width() const;
  float get_height() const;

  // 타원 내부에 특정 점이 포함되는지 확인하는 메서드
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

#endif // ELLIPSE_H
