#include "LineFactory.h"

// Line 도형 생성 함수의 구현부
sf::Drawable *LineFactory::createShape() {
  sf::VertexArray *line =
      new sf::VertexArray(sf::Lines, 2); // 두 개의 점을 가진 선 생성
  (*line)[0].position = sf::Vector2f(10.0f, 10.0f); // 시작점
  (*line)[0].color = sf::Color::Red;
  (*line)[1].position = sf::Vector2f(200.0f, 200.0f); // 끝점
  (*line)[1].color = sf::Color::Red;
  return line;
}
