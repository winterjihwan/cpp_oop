#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

#include "../model/Shape.h"
#include "Command.h"
#include <SFML/Graphics.hpp>

class MoveCommand : public Command {
private:
  Shape *shape;
  sf::Vector2f newPosition;
  sf::Vector2f oldPosition;

public:
  MoveCommand(Shape *shape, const sf::Vector2f &newPosition);
  void execute() override;
  void undo() override;
};

#endif // MOVE_COMMAND_H
