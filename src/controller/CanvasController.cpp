#include "CanvasController.h"

// 생성자
Canvas_controller::Canvas_controller(Shape_factory *rectangle_factory,
                                     Shape_factory *ellipse_factory,
                                     Shape_factory *line_factory,
                                     Canvas_view *canvas_view,
                                     StatusView *statusView)
    : rectangle_factory{rectangle_factory}, ellipse_factory{ellipse_factory},
      line_factory{line_factory}, canvas_view(canvas_view), status_view(statusView) {}

// 사각형 생성
void Canvas_controller::create_rectangle()
{
  Shape *new_shape = rectangle_factory->createShape(); // Shape* 타입 반환
  shapes.push_back(new_shape);
  isStatusViewDirty = true; // Mark status view for update
}

// 타원 생성
void Canvas_controller::create_ellipse()
{
  Shape *new_shape = ellipse_factory->createShape(); // Shape* 타입 반환
  shapes.push_back(new_shape);
  isStatusViewDirty = true; // Mark status view for update
}

// 선 생성
void Canvas_controller::create_line()
{
  Shape *new_shape = line_factory->createShape(); // Shape* 타입 반환
  shapes.push_back(new_shape);
  isStatusViewDirty = true; // Mark status view for update
}

// 도형 선택
void Canvas_controller::select_shape(const sf::Vector2f &click_position)
{
  // Unselect currently selected shape
  if (selected_shape != nullptr)
  {
    selected_shape->unhighlight();
    selected_shape = nullptr;
    is_selected = false;
  }

  for (auto &shape : shapes)
  {
    if (shape->isSelected(click_position))
    {
      selected_shape = shape;
      is_selected = true;
      selected_shape->highlight();
      isStatusViewDirty = true; // Mark status view for update
      return;
    }
  }

  // Clear status view if no shape was selected
  if (!is_selected)
  {
    isStatusViewDirty = true;
    status_view->clear();
  }
}

// 도형 이동 (마우스 이동 시 위치 변경)
void Canvas_controller::move_shape(const sf::Vector2f &new_position)
{
  if (selected_shape && is_selected)
  {
    selected_shape->setPosition(new_position - offset);
    isStatusViewDirty = true; // Mark status view for update
  }
}

// 선택 해제
void Canvas_controller::deselect_shape()
{
  if (selected_shape != nullptr)
  {
    selected_shape->unhighlight();
    selected_shape = nullptr;
    is_selected = false;
    isStatusViewDirty = true;
    status_view->clear();
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
