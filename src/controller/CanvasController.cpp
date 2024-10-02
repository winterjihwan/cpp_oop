#include "CanvasController.h"

// 생성자
Canvas_controller::Canvas_controller(Shape_factory *rectangle_factory, Shape_factory *ellipse_factory, Shape_factory *line_factory, Canvas_view *canvas_view)
    : rectangle_factory{rectangle_factory}, ellipse_factory{ellipse_factory}, line_factory{line_factory}, canvas_view(canvas_view) {}

// 사각형 생성
void Canvas_controller::create_rectangle()
{
  sf::Drawable *new_shape = rectangle_factory->createShape();
  shapes.push_back(new_shape);
  canvas_view->render(shapes); // 새로운 도형을 화면에 표시
}

// 타원 생성
void Canvas_controller::create_ellipse()
{
  sf::Drawable *new_shape = ellipse_factory->createShape();
  shapes.push_back(new_shape);
  canvas_view->render(shapes);
}

// 선 생성
void Canvas_controller::create_line()
{
  sf::Drawable *new_shape = line_factory->createShape();
  shapes.push_back(new_shape);
  canvas_view->render(shapes);
}

// 도형 선택 (마우스 클릭 시 선택)
void Canvas_controller::select_shape(const sf::Vector2f &click_position)
{
  for (auto &shape : shapes)
  {
    if (auto circle_shape = dynamic_cast<sf::CircleShape *>(shape))
    {
      sf::Vector2f center = circle_shape->getPosition() + sf::Vector2f(circle_shape->getRadius(), circle_shape->getRadius());
      float dx = click_position.x - center.x;
      float dy = click_position.y - center.y;
      if ((dx * dx + dy * dy) <= circle_shape->getRadius() * circle_shape->getRadius())
      {
        selected_shape = shape;
        is_selected = true; // 도형이 선택됨
        offset = click_position - circle_shape->getPosition();
        break;
      }
    }
    else if (auto rect_shape = dynamic_cast<sf::RectangleShape *>(shape))
    {
      sf::FloatRect bounds = rect_shape->getGlobalBounds();
      if (bounds.contains(click_position))
      {
        selected_shape = shape;
        is_selected = true; // 도형이 선택됨
        offset = click_position - rect_shape->getPosition();
        break;
      }
    }
  }
}

// 도형 이동 (마우스 이동 시 위치 변경)
void Canvas_controller::move_shape(const sf::Vector2f &new_position)
{
  if (!selected_shape || !is_selected)
  {
    return;
  }

  if (auto rect_shape = dynamic_cast<sf::RectangleShape *>(selected_shape))
  {
    rect_shape->setPosition(new_position - offset); // 마우스 위치 - 오프셋 사용
  }
  else if (auto circle_shape = dynamic_cast<sf::CircleShape *>(selected_shape))
  {
    circle_shape->setPosition(new_position - offset);
  }
}

// 도형 선택 해제 (마우스 버튼을 놓을 때 호출)
void Canvas_controller::deselect_shape()
{
  selected_shape = nullptr;
  is_selected = false;
}

// 드래그 종료
void Canvas_controller::end_drag()
{
  is_selected = false;
}

// 선택된 도형 반환
sf::Drawable *Canvas_controller::getSelectedShape() const
{
  return selected_shape;
}

// 모든 도형을 화면에 다시 그리기
void Canvas_controller::render_shapes()
{
  canvas_view->render(shapes);
}
