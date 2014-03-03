#include "message_element.h"
#include "graphic_element_visitor.h"
void message_element::accept(graphic_element_visitor * v) {
  v->visit(this);
}
