// HighlightCommand.cpp
#include "HighlightCommand.h"

HighlightCommand::HighlightCommand(std::shared_ptr<Shape> shape, bool highlight)
    : shape(shape), highlight(highlight) {}

void HighlightCommand::execute()
{
    if (highlight)
    {
        shape->highlight();
    }
    else
    {
        shape->unhighlight();
    }
}

void HighlightCommand::undo()
{
    if (highlight)
    {
        shape->unhighlight();
    }
    else
    {
        shape->highlight();
    }
}
