#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H

#include "Shape.h"
#include <vector>
#include <memory>
#include <algorithm>

class CompositeShape : public Shape
{
public:
    CompositeShape();
    ~CompositeShape();

    void add(std::shared_ptr<Shape> shape) override;

    void remove(std::shared_ptr<Shape> shape) override;

    std::shared_ptr<Shape> getChild(int index) const override;

    const std::vector<std::shared_ptr<Shape>> &getChildren() const;

    void clear();

    bool empty() const;

    void setPosition(const sf::Vector2f &position) override;

    sf::Vector2f getPosition() const override;

    void setSize(const sf::Vector2f &size) override;

    sf::Vector2f getSize() const override;

    void highlight() override;

    void unhighlight() override;

    sf::Color getColor() const override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    bool isSelected(const sf::Vector2f &point) const override;

    bool contains(const std::shared_ptr<Shape> &shape) const;

    void move(const sf::Vector2f &delta) override;

private:
    std::vector<std::shared_ptr<Shape>> children;
};

#endif // COMPOSITESHAPE_H
