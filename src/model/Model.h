// Model.h
#ifndef MODEL_H
#define MODEL_H

#include "../observer/Subject.h"
#include "Shape.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Model : public Subject {
private:
  std::vector<std::shared_ptr<Shape>> shapes;

public:
  void addShape(const std::shared_ptr<Shape> &shape);
  void removeShape(const std::shared_ptr<Shape> &shape);
  void updateShape(const std::shared_ptr<Shape> &shape);

  std::vector<std::shared_ptr<Shape>> &getShapes();
  void notifyObservers();
};

#endif // MODEL_H
