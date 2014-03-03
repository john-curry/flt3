#ifndef VIEW_H
#define VIEW_H
#include <vector>
#include <memory>
#include "graphic_element.h"
#include "graphic_element_visitor.h"
struct view : public graphic_element {
  view(std::vector<std::shared_ptr<graphic_element>> elements_): elements(elements_) { }
  std::vector<std::shared_ptr<graphic_element>> elements;
  void accept(graphic_element_visitor * visitor) override {
    for (auto & g: elements) {
      g->accept(visitor);
    }
  }
};
#endif
