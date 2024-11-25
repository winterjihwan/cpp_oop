// MoveCommand.cpp
#include "MoveCommand.h"

MoveCommand::MoveCommand(std::shared_ptr<Shape> shape,
                         const sf::Vector2f &newPosition)
    : shape(shape), newPosition(newPosition),
      oldPosition(shape->getPosition()) {}

void MoveCommand::execute()
{
  sf::Vector2f delta = newPosition - oldPosition;
  shape->move(delta);
}

void MoveCommand::undo()
{
  sf::Vector2f delta = oldPosition - newPosition;
  shape->move(delta);
}
