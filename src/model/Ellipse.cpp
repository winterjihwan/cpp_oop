#include "Ellipse.h"

// 생성자 정의
Ellipse::Ellipse(float x, float y, float radiusX, float radiusY) {
  ellipse.setPosition(x, y);
  ellipse.setRadius(radiusX); // 원의 기본 반지름 설정 (X축 반지름)
  ellipse.setScale(1.0f,
                   radiusY / radiusX); // Y축 반지름을 설정하여 타원 모양 만듦
}

// get_width() 정의
float Ellipse::get_width() const { return ellipse.getRadius() * 2.0f; }

// get_height() 정의
float Ellipse::get_height() const {
  return ellipse.getRadius() * 2.0f * ellipse.getScale().y;
}

// isSelected() 메서드 정의: 타원 내부에 특정 위치가 포함되는지 확인
bool Ellipse::isSelected(const sf::Vector2f &point) const {
  sf::Vector2f center = ellipse.getPosition() +
                        sf::Vector2f(ellipse.getRadius(), ellipse.getRadius());
  float dx = (point.x - center.x) / ellipse.getScale().x;
  float dy = (point.y - center.y) / ellipse.getScale().y;
  return (dx * dx + dy * dy) <= ellipse.getRadius() * ellipse.getRadius();
}

// set_size() 메서드 정의
void Ellipse::set_size(float width, float height) {
  ellipse.setRadius(width / 2.0f); // X축 반지름
  ellipse.setScale(1.0f, height / width);
}

// 위치 반환 메서드 정의
sf::Vector2f Ellipse::getPosition() const { return ellipse.getPosition(); }

// 위치 설정 메서드 정의
void Ellipse::setPosition(const sf::Vector2f &position) {
  ellipse.setPosition(position);
}

// 크기 반환 메서드 정의
sf::Vector2f Ellipse::getSize() const {
  return sf::Vector2f(ellipse.getRadius() * 2.0f,
                      ellipse.getRadius() * 2.0f * ellipse.getScale().y);
}

// 크기 설정 메서드 정의
void Ellipse::setSize(const sf::Vector2f &size) { set_size(size.x, size.y); }

// draw 메서드 정의
void Ellipse::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(ellipse, states);
}
