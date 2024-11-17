#ifndef CANVAS_CONTROLLER_H
#define CANVAS_CONTROLLER_H

#include "../command/Command.h"
#include "../factories/ShapeFactory.h"
#include "../model/CompositeShape.h"
#include "../model/Shape.h"
#include "../view/CanvasView.h"
#include "../view/Sidebar.h"
#include "../view/StatusView.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class Shape_factory;
class Canvas_view;
class StatusView;

class CanvasController {
private:
  Shape_factory *rectangle_factory;
  Shape_factory *ellipse_factory;
  Shape_factory *line_factory;
  Shape_factory *text_factory;
  Shape_factory *image_factory;
  Canvas_view *canvas_view;
  StatusView *status_view;
  Sidebar *sidebar;

  std::vector<std::shared_ptr<Shape>> shapes;
  std::shared_ptr<CompositeShape> selected_shapes;
  std::shared_ptr<Shape> single_selected_shape = nullptr;

  std::string selectedShapeType;
  sf::Vector2f offset;
  bool is_dragging = false;
  Command commandManager;

public:
  CanvasController(Shape_factory *rectangle_factory,
                   Shape_factory *ellipse_factory, Shape_factory *line_factory,
                   Shape_factory *text_factory, Shape_factory *image_factory,
                   Canvas_view *canvas_view, StatusView *status_view,
                   Sidebar *sidebar);

  void handleSidebarClick(const sf::Vector2f &clickPosition);

  void create_shape(const std::string &shapeType, const sf::Vector2f &position);
  void select_shape(const sf::Vector2f &click_position,
                    bool multiSelect = false);
  void move_shape(const sf::Vector2f &new_position);
  void resize_shape(const sf::Vector2f &new_size); // For resizing functionality

  void deselect_shape();
  void end_drag();

  void executeCommand(
      std::shared_ptr<CommandInterface> command); // Method to execute commands
  void undo(); // Method to undo the last command
  void redo(); // Method to redo the last undone command

  std::shared_ptr<Shape> getSelectedShape() const;
  std::unordered_map<std::shared_ptr<Shape>, sf::Vector2f> shape_offsets;
  std::string getSelectedShapeType() const;

  bool isStatusViewDirty = true;
  void render_shapes();
  void sort_shapes_by_z();

  bool isSingleSelection() const;
  bool isSelectionActive() const;
  sf::Vector2f getCompositeShapePosition() const;

  void setFocusField(sf::Vector2f mousePos);
};

#endif // CANVAS_CONTROLLER_H
