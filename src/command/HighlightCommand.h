// HighlightCommand.h
#ifndef HIGHLIGHTCOMMAND_H
#define HIGHLIGHTCOMMAND_H

#include "CommandInterface.h"
#include "Shape.h"
#include <memory>

class HighlightCommand : public CommandInterface
{
public:
    HighlightCommand(std::shared_ptr<Shape> shape, bool highlight);
    void execute() override;
    void undo() override;

private:
    std::shared_ptr<Shape> shape;
    bool highlight;
};

#endif // HIGHLIGHTCOMMAND_H
