#ifndef LINE_H
#define LINE_H

#include <SFML/Graphics.hpp>
#include "Shape.h"

// Line 클래스 정의 (Shape 클래스를 상속)
class Line : public Shape
{
private:
    sf::VertexArray line; // 선을 저장할 sf::VertexArray 객체

public:
    Line(const sf::Vector2f &start, const sf::Vector2f &end); // 생성자

    // Shape 클래스의 가상 함수 구현
    sf::Vector2f getPosition() const override;
    sf::Vector2f getSize() const override;
    void setPosition(const sf::Vector2f &position) override;
    void setSize(const sf::Vector2f &size) override;
    bool isSelected(const sf::Vector2f &point) const override;

    // 선택 및 하이라이트 메서드 구현
    void highlight() override;
    void unhighlight() override;

    sf::Color getColor() const override; // Added getColor

    // SFML의 draw() 메서드 재정의
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};

#endif // LINE_H
