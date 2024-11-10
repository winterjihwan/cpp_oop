// ResizeCommand.h
#ifndef RESIZECOMMAND_H
#define RESIZECOMMAND_H

#include "CommandInterface.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <memory>

class ResizeCommand : public CommandInterface
{
public:
  ResizeCommand(std::shared_ptr<Shape> shape, const sf::Vector2f &newSize);
  void execute() override;
  void undo() override;

private:
  std::shared_ptr<Shape> shape;
  sf::Vector2f oldSize;
  sf::Vector2f newSize;
};

#endif // RESIZECOMMAND_H
