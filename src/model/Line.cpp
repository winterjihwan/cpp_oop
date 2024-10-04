#include "Line.h"
#include <cmath>

// 생성자 정의
Line::Line(float startX, float startY, float endX, float endY) {
  line.setPrimitiveType(sf::Lines);
  line.resize(2);
  line[0].position = sf::Vector2f(startX, startY);
  line[1].position = sf::Vector2f(endX, endY);
}

// get_width() 정의
float Line::get_width() const {
  return std::abs(line[1].position.x - line[0].position.x);
}

// get_height() 정의
float Line::get_height() const {
  return std::abs(line[1].position.y - line[0].position.y);
}

// isSelected() 메서드 정의
bool Line::isSelected(const sf::Vector2f &point) const {
  sf::Vector2f start = line[0].position;
  sf::Vector2f end = line[1].position;

  // 점-선 거리 공식 사용
  float distance =
      std::abs((end.y - start.y) * point.x - (end.x - start.x) * point.y +
               end.x * start.y - end.y * start.x) /
      std::hypot(end.x - start.x, end.y - start.y);

  // 거리 기준으로 선 선택 여부 확인
  return distance < 5.0f; // 임계값 5.0f 이내면 선택됨
}

// set_size() 메서드 정의
void Line::set_size(float width, float height) {
  line[1].position =
      sf::Vector2f(line[0].position.x + width, line[0].position.y + height);
}

// 위치 반환 메서드 정의
sf::Vector2f Line::getPosition() const { return line[0].position; }

// 위치 설정 메서드 정의
void Line::setPosition(const sf::Vector2f &position) {
  sf::Vector2f offset = position - getPosition();
  line[0].position += offset;
  line[1].position += offset;
}

// 크기 반환 메서드 정의
sf::Vector2f Line::getSize() const {
  return sf::Vector2f(get_width(), get_height());
}

// 크기 설정 메서드 정의
void Line::setSize(const sf::Vector2f &size) { set_size(size.x, size.y); }

// draw 메서드 정의
void Line::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(line, states);
}
