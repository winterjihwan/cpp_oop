// Command.cpp
#include "Command.h"

void Command::executeCommand(std::shared_ptr<CommandInterface> command)
{
  command->execute();
  undoStack.push(command);

  while (!redoStack.empty())
  {
    redoStack.pop();
  }
}

void Command::undo()
{
  if (!undoStack.empty())
  {
    auto command = undoStack.top();
    undoStack.pop();

    command->undo();
    redoStack.push(command);
  }
}

void Command::redo()
{
  if (!redoStack.empty())
  {
    auto command = redoStack.top();
    redoStack.pop();

    command->execute();
    undoStack.push(command);
  }
}
