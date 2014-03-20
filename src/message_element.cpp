#include "message_element.h"
#include "graphic_element_visitor.h"
#include <memory>
void message_element::accept(graphic_element_visitor * v) {
  v->visit(shared_from_this());
}
