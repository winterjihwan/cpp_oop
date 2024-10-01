#ifndef RESIZE_COMMAND_H
#define RESIZE_COMMAND_H

#include "Command.h"
#include "../model/Shape.h"
#include <SFML/Graphics.hpp>

class ResizeCommand : public Command
{
private:
    Shape *shape;
    sf::Vector2f newSize;
    sf::Vector2f oldSize;

public:
    // 함수 선언만 포함
    ResizeCommand(Shape *shape, const sf::Vector2f &newSize);

    // 함수 선언만 포함
    void execute() override;
    void undo() override;
};

#endif // RESIZE_COMMAND_H
