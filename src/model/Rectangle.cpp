// Rectangle.cpp
#include "Rectangle.h"

// 생성자 정의: 헤더 파일과 동일한 시그니처 사용
Rectangle::Rectangle(float x, float y, float width, float height)
{
  shape.setPosition(x, y);
  shape.setSize(sf::Vector2f(width, height));
}

// get_width() 정의
float Rectangle::get_width() const
{
  return shape.getSize().x;
}

// get_height() 정의
float Rectangle::get_height() const
{
  return shape.getSize().y;
}

// set_size() 메서드 정의
void Rectangle::set_size(float width, float height)
{
  shape.setSize(sf::Vector2f(width, height));
}

// 위치 반환 메서드 정의
sf::Vector2f Rectangle::getPosition() const
{
  return shape.getPosition();
}

// 위치 설정 메서드 정의
void Rectangle::setPosition(const sf::Vector2f &position)
{
  shape.setPosition(position);
}

// 크기 반환 메서드 정의
sf::Vector2f Rectangle::getSize() const
{
  return shape.getSize();
}

// 크기 설정 메서드 정의
void Rectangle::setSize(const sf::Vector2f &size)
{
  shape.setSize(size);
}

// draw 메서드 정의: 헤더 파일에 이미 선언된 메서드와 동일한 시그니처 사용
void Rectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(shape, states);
}
