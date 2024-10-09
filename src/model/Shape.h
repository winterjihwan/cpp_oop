// Shape.h
#ifndef SHAPE_H
#define SHAPE_H

#include <SFML/Graphics.hpp>

// 모든 도형의 기본 추상 클래스
class Shape : public sf::Drawable
{
public:
    virtual ~Shape() = default;

    // 도형의 위치 반환
    virtual sf::Vector2f getPosition() const = 0;

    // 도형의 크기 반환
    virtual sf::Vector2f getSize() const = 0;

    // 도형의 위치 설정
    virtual void setPosition(const sf::Vector2f &position) = 0;

    // 도형의 크기 설정
    virtual void setSize(const sf::Vector2f &size) = 0;

    // 도형의 선택 여부 감지
    virtual bool isSelected(const sf::Vector2f &point) const = 0;

    // 도형의 선택시 highlight 표시
    virtual void highlight() = 0;

    // 도형의 하이라이트를 해제
    virtual void unhighlight() = 0;
};

#endif // SHAPE_H
