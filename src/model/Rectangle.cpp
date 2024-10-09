// Rectangle.cpp
#include "Rectangle.h"

// 생성자 정의: 헤더 파일과 동일한 시그니처 사용
Rectangle::Rectangle(float x, float y, float width, float height)
{
  shape.setPosition(x, y);
  shape.setSize(sf::Vector2f(width, height));
  shape.setFillColor(sf::Color::Green);
}

// get_width() 정의
float Rectangle::get_width() const { return shape.getSize().x; }

// get_height() 정의
float Rectangle::get_height() const { return shape.getSize().y; }

// set_size() 메서드 정의
void Rectangle::set_size(float width, float height)
{
  shape.setSize(sf::Vector2f(width, height));
}

// 위치 반환 메서드 정의
sf::Vector2f Rectangle::getPosition() const { return shape.getPosition(); }

// 위치 설정 메서드 정의
void Rectangle::setPosition(const sf::Vector2f &position)
{
  shape.setPosition(position);
}

// 크기 반환 메서드 정의
sf::Vector2f Rectangle::getSize() const { return shape.getSize(); }

// 크기 설정 메서드 정의
void Rectangle::setSize(const sf::Vector2f &size) { shape.setSize(size); }

void Rectangle::highlight()
{
  shape.setOutlineThickness(5.0f);
  shape.setOutlineColor(sf::Color::Red);
}

void Rectangle::unhighlight()
{
  shape.setOutlineThickness(0.0f);
  shape.setOutlineColor(sf::Color::Black);
}

// draw 메서드 정의: 헤더 파일에 이미 선언된 메서드와 동일한 시그니처 사용
void Rectangle::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(shape, states);
}
