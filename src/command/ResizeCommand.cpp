// ResizeCommand.cpp
#include "ResizeCommand.h"

// 생성자: 도형 객체와 새로운 크기를 받아 초기화
ResizeCommand::ResizeCommand(Shape *shape, const sf::Vector2f &newSize)
    : shape(shape), newSize(newSize)
{
    // 기존 도형의 크기를 저장하여 나중에 undo()에서 사용할 수 있도록 함
    oldSize = shape->getSize();
}

// execute() 메서드: 새로운 크기로 도형 크기를 변경
void ResizeCommand::execute()
{
    shape->setSize(newSize);
}

// undo() 메서드: 이전 크기로 도형 크기를 되돌림
void ResizeCommand::undo()
{
    shape->setSize(oldSize);
}
