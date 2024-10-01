// Command.h
#ifndef COMMAND_H
#define COMMAND_H

// 추상 Command 클래스
class Command
{
public:
    virtual ~Command() = default;

    // 명령을 실행하는 메서드
    virtual void execute() = 0;

    // 실행 취소를 위한 메서드 (옵션)
    virtual void undo() = 0;
};

#endif // COMMAND_H
