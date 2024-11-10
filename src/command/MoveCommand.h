// MoveCommand.h
#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "CommandInterface.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class MoveCommand : public CommandInterface
{
public:
  MoveCommand(std::shared_ptr<Shape> shape, const sf::Vector2f &newPosition);

  void execute() override;
  void undo() override;

private:
  std::shared_ptr<Shape> shape;
  sf::Vector2f oldPosition;
  sf::Vector2f newPosition;
};

#endif // MOVECOMMAND_H
