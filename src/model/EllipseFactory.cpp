#include "EllipseFactory.h"

// Ellipse 도형 생성 함수의 구현부
sf::Drawable *EllipseFactory::createShape()
{
    sf::CircleShape *ellipse = new sf::CircleShape(50.0f); // 반지름 50의 원 생성
    ellipse->setScale(1.5f, 1.0f);                         // 타원형으로 변형
    ellipse->setFillColor(sf::Color::Blue);
    return ellipse;
}
