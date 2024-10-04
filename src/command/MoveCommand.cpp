#include "MoveCommand.h"

// 생성자: 도형과 새로운 위치를 받음
MoveCommand::MoveCommand(Shape *shape, const sf::Vector2f &newPosition)
    : shape(shape), newPosition(newPosition) {
  oldPosition = shape->getPosition();
}

// 명령 실행: 도형의 위치를 변경
void MoveCommand::execute() { shape->setPosition(newPosition); }

// 명령 취소: 이전 위치로 되돌림
void MoveCommand::undo() { shape->setPosition(oldPosition); }
