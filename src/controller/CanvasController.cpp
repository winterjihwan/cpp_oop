#include "CanvasController.h"

// 생성자
Canvas_controller::Canvas_controller(Shape_factory *rectangle_factory,
                                     Shape_factory *ellipse_factory,
                                     Shape_factory *line_factory,
                                     Canvas_view *canvas_view)
    : rectangle_factory{rectangle_factory}, ellipse_factory{ellipse_factory},
      line_factory{line_factory}, canvas_view(canvas_view) {}

// 사각형 생성
void Canvas_controller::create_rectangle()
{
  Shape *new_shape = rectangle_factory->createShape(); // Shape* 타입 반환
  shapes.push_back(new_shape);
  canvas_view->render(shapes); // 새로운 도형을 화면에 표시
}

// 타원 생성
void Canvas_controller::create_ellipse()
{
  Shape *new_shape = ellipse_factory->createShape(); // Shape* 타입 반환
  shapes.push_back(new_shape);
  canvas_view->render(shapes);
}

// 선 생성
void Canvas_controller::create_line()
{
  Shape *new_shape = line_factory->createShape(); // Shape* 타입 반환
  shapes.push_back(new_shape);
  canvas_view->render(shapes);
}

// 도형 선택
void Canvas_controller::select_shape(const sf::Vector2f &click_position)
{
  // 현재 선택된 도형이 있다면 해제
  if (selected_shape != nullptr)
  {
    selected_shape->unhighlight(); // 이전 선택 해제
    selected_shape = nullptr;
    is_selected = false;
  }

  for (auto &shape : shapes)
  {
    // 각 도형 클래스의 isSelected() 메서드를 호출하여 선택 여부 확인
    if (shape->isSelected(click_position))
    {
      selected_shape = shape;
      is_selected = true;
      selected_shape->highlight(); // 하이라이트 처리
      break;
    }
  }

  // 도형이 선택되지 않았을 경우 (배경 클릭)
  if (!is_selected)
  {
    selected_shape = nullptr;
  }

  canvas_view->render(shapes); // 변경 사항 반영
}

// 도형 이동 (마우스 이동 시 위치 변경)
void Canvas_controller::move_shape(const sf::Vector2f &new_position)
{
  if (!selected_shape || !is_selected)
  {
    return;
  }

  // 선택된 도형의 위치 설정
  selected_shape->setPosition(new_position - offset);
}

// 선택 해제
void Canvas_controller::deselect_shape()
{
  if (selected_shape != nullptr)
  {
    selected_shape->unhighlight(); // 선택된 도형의 하이라이트 해제
    selected_shape = nullptr;
    is_selected = false;
    canvas_view->render(shapes); // 선택 해제 후 렌더링
  }
}

// 선택된 도형 반환
Shape *Canvas_controller::getSelectedShape() const
{
  return selected_shape;
}

// 모든 도형을 화면에 다시 그리기
void Canvas_controller::render_shapes()
{
  canvas_view->render(shapes); // Shape* 벡터를 넘겨줌
}

void Canvas_controller::end_drag()
{
  is_dragging = false; // 드래그 상태 해제
}
