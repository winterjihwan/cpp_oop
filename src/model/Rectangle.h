// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <SFML/Graphics.hpp>

// Rectangle 도형 클래스 정의
class Rectangle : public Shape {
private:
  sf::RectangleShape shape; // SFML의 사각형 도형

public:
  Rectangle(float x, float y, float width, float height);

  // getWidth와 getHeight 메서드 추가 (헤더 파일에 선언)
  float get_width() const;
  float get_height() const;

  bool isSelected(const sf::Vector2f &point) const override {
    return shape.getGlobalBounds().contains(point);
  }

  // set_size 메서드 수정: Rectangle &rect 제거, 일관된 시그니처 사용
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

#endif // RECTANGLE_H
