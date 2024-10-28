#include "Line.h"
#include <cmath>

// 생성자 정의
Line::Line(const sf::Vector2f &start, const sf::Vector2f &end)
{
    line.setPrimitiveType(sf::Lines); // 선 모양으로 설정
    line.resize(2);                   // 두 개의 점 필요
    line[0].position = start;         // 시작점
    line[1].position = end;           // 끝점
    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Red;
}

// getPosition 메서드 구현
sf::Vector2f Line::getPosition() const
{
    return line[0].position;
}

// getSize 메서드 구현
sf::Vector2f Line::getSize() const
{
    return line[1].position - line[0].position;
}

// setPosition 메서드 구현
void Line::setPosition(const sf::Vector2f &position)
{
    sf::Vector2f offset = position - line[0].position;
    line[0].position += offset;
    line[1].position += offset;
}

// setSize 메서드 구현
void Line::setSize(const sf::Vector2f &size)
{
    line[1].position = line[0].position + size;
}

// isSelected 메서드 구현 (점과 점 사이의 거리가 가까운지 확인)
bool Line::isSelected(const sf::Vector2f &point) const
{
    sf::Vector2f p1 = line[0].position;
    sf::Vector2f p2 = line[1].position;
    float line_length_squared = (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
    float t = ((point.x - p1.x) * (p2.x - p1.x) + (point.y - p1.y) * (p2.y - p1.y)) / line_length_squared;

    if (t >= 0.0f && t <= 1.0f)
    {
        sf::Vector2f projection = p1 + t * (p2 - p1);
        float distance = sqrt((point.x - projection.x) * (point.x - projection.x) +
                              (point.y - projection.y) * (point.y - projection.y));

        return distance <= 5.0f; // 5 픽셀 이내면 선택된 것으로 간주
    }

    return false;
}

// highlight 메서드 구현 (선의 색상을 변경하여 선택 여부를 표시)
void Line::highlight()
{
    line[0].color = sf::Color::Yellow;
    line[1].color = sf::Color::Yellow;
}

// unhighlight 메서드 구현 (선의 색상을 기본 색상으로 되돌림)
void Line::unhighlight()
{
    line[0].color = sf::Color::Red;
    line[1].color = sf::Color::Red;
}

// getColor 메서드 구현
sf::Color Line::getColor() const
{
    return line[0].color;
}

// draw 메서드 구현
void Line::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(line, states);
}
