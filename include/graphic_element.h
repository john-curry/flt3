#ifndef GRAPHIC_ELEMENT_H
#define GRAPHIC_ELEMENT_H
class graphic_element_visitor;
struct graphic_element {
  virtual ~graphic_element() = default;
  virtual void accept(graphic_element_visitor*) = 0;
};
#endif
