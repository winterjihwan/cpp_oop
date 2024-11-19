#ifndef OBSERVER_H
#define OBSERVER_H

#include "../model/Shape.h"

class Observer {
public:
  virtual ~Observer() = default;
  virtual void update(const std::vector<std::shared_ptr<Shape>> &shapes) = 0;
};

#endif // OBSERVER_H
