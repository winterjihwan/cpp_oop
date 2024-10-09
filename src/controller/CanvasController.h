#ifndef CANVAS_CONTROLLER_H
#define CANVAS_CONTROLLER_H

#include "../model/ShapeFactory.h"
#include "../view/CanvasView.h"
#include "../model/Shape.h" // Shape 클래스를 포함
#include <vector>
#include <SFML/Graphics.hpp>

class Shape_factory;
class Canvas_view;

class Canvas_controller
{
private:
  Shape_factory *rectangle_factory;
  Shape_factory *ellipse_factory;
  Shape_factory *line_factory;
  Canvas_view *canvas_view;

  // 모든 도형을 관리할 벡터 (Shape* 타입으로 변경)
  std::vector<Shape *> shapes;

  // 현재 선택된 도형 (Shape* 타입으로 변경)
  Shape *selected_shape = nullptr;

  sf::Vector2f offset;      // 도형과 마우스 클릭 위치 간의 기준점
  bool is_selected = false; // 도형이 선택된 상태인지 여부
  bool is_dragging = false; // 드래그 중인지 여부 확인

public:
  // 생성자
  Canvas_controller(Shape_factory *rectangle_factory, Shape_factory *ellipse_factory, Shape_factory *line_factory, Canvas_view *canvas_view);

  // 도형 생성 및 관리
  void create_rectangle();
  void create_ellipse();
  void create_line();

  // 도형 선택 및 이동
  void select_shape(const sf::Vector2f &click_position);
  void move_shape(const sf::Vector2f &new_position);

  // 도형 선택 해제 및 드래그 종료
  void deselect_shape();
  void end_drag();

  // 선택된 도형을 반환하는 메서드 (Shape* 타입으로 변경)
  Shape *getSelectedShape() const;

  // 모든 도형을 화면에 다시 그리기
  void render_shapes();
};

#endif // CANVAS_CONTROLLER_H
