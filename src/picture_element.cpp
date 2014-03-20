#include "picture_element.h"
#include "graphic_element_visitor.h"
void picture_element::accept(graphic_element_visitor * v) {
  v->visit(shared_from_this());
}
