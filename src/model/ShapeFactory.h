#ifndef SHAPE_FACTORY_H
#define SHAPE_FACTORY_H

#include <SFML/Graphics.hpp>

// 추상 팩토리 클래스
class Shape_factory
{
public:
  virtual ~Shape_factory() = default;

  // 순수 가상 함수: 자식 클래스에서 반드시 구현해야 하는 함수
  virtual sf::Drawable *createShape() = 0;
};

#endif // SHAPE_FACTORY_H
