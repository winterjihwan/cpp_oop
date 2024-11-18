#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <algorithm>
#include <memory>
#include <vector>

class Subject {
private:
  std::vector<std::shared_ptr<Observer>> observers;

public:
  void attach(const std::shared_ptr<Observer> &observer) {
    observers.push_back(observer);
  }

  void detach(const std::shared_ptr<Observer> &observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer),
                    observers.end());
  }

  void notify() {
    for (const auto &observer : observers) {
      observer->update();
    }
  }
};

#endif // SUBJECT_H
