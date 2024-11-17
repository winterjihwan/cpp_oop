// Command.h
#ifndef COMMAND_H
#define COMMAND_H

#include "CommandInterface.h"
#include <memory>
#include <stack>

class Command {
public:
  void executeCommand(std::shared_ptr<CommandInterface> command);
  void undo();
  void redo();

private:
  std::stack<std::shared_ptr<CommandInterface>> undoStack;
  std::stack<std::shared_ptr<CommandInterface>> redoStack;
};

#endif // COMMAND_H
