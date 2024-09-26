#include "controller/CanvasController.h"
#include "iostream"
#include "model/RectangleFactory.h"

int main() {
  Canvas_view canvas{800, 600};

  RectangleFactory rect_factory{};
  Canvas_controller rect_controller{&rect_factory, &canvas};

  /*rect_controller.create_rectangle();*/
}
