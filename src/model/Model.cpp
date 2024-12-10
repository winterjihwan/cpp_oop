// Model.cpp
#include "Model.h"

void Model::addShape(const std::shared_ptr<Shape> &shape) {
  shapes.push_back(shape);
  notify(shapes);
}

void Model::removeShape(const std::shared_ptr<Shape> &shape) {
  shapes.erase(std::remove(shapes.begin(), shapes.end(), shape), shapes.end());
  notify(shapes);
}

void Model::updateShape(const std::shared_ptr<Shape> &shape) { notify(shapes); }

std::vector<std::shared_ptr<Shape>> &Model::getShapes() { return shapes; }
