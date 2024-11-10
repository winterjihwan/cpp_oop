// CommandInterface.h
#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H

class CommandInterface
{
public:
    virtual ~CommandInterface() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

#endif // COMMANDINTERFACE_H
