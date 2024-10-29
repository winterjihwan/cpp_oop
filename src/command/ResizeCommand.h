#ifndef RESIZE_COMMAND_H
#define RESIZE_COMMAND_H

#include "../model/Shape.h"
#include "Command.h"
#include <SFML/Graphics.hpp>

class ResizeCommand : public Command {
private:
  Shape *shape;
  sf::Vector2f newSize;
  sf::Vector2f oldSize;

public:
  ResizeCommand(Shape *shape, const sf::Vector2f &newSize);

  void execute() override;
  void undo() override;
};

#endif // RESIZE_COMMAND_H
