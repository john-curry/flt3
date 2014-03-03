#ifndef GRAPHIC_MOVER_H
#define GRAPHIC_MOVER_H
#include "graphic_element_visitor.h"
struct graphic_mover : public graphic_element_visitor {
  void visit(picture_element*) override;
  void visit(message_element*) override;
  void visit(entity*)          override;
};
#endif
