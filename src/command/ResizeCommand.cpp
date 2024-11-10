// ResizeCommand.cpp
#include "ResizeCommand.h"

ResizeCommand::ResizeCommand(std::shared_ptr<Shape> shape, const sf::Vector2f &newSize)
    : shape(shape), newSize(newSize), oldSize(shape->getSize()) {}

void ResizeCommand::execute()
{
  shape->setSize(newSize);
}

void ResizeCommand::undo()
{
  shape->setSize(oldSize);
}
