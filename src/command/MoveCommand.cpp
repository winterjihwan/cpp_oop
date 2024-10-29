#include "MoveCommand.h"

MoveCommand::MoveCommand(Shape *shape, const sf::Vector2f &newPosition)
    : shape(shape), newPosition(newPosition) {
  oldPosition = shape->getPosition();
}

void MoveCommand::execute() { shape->setPosition(newPosition); }

void MoveCommand::undo() { shape->setPosition(oldPosition); }
