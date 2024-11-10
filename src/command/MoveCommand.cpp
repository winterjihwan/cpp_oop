// MoveCommand.cpp
#include "MoveCommand.h"

MoveCommand::MoveCommand(std::shared_ptr<Shape> shape, const sf::Vector2f &newPosition)
    : shape(shape), newPosition(newPosition), oldPosition(shape->getPosition()) {}

void MoveCommand::execute()
{
  // Calculate the delta
  sf::Vector2f delta = newPosition - oldPosition;

  // Apply delta to move the shape
  shape->setPosition(shape->getPosition() + delta);
}

void MoveCommand::undo()
{
  // Calculate the delta to move back to the old position
  sf::Vector2f delta = oldPosition - newPosition;

  // Apply delta to revert the shape's position
  shape->setPosition(shape->getPosition() + delta);
}
