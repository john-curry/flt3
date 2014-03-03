#ifndef GRAPHIC_LOGGER_H
#define GRAPHIC_LOGGER_H
#include "graphic_element_visitor.h"
struct graphic_logger : public graphic_element_visitor {
  void visit(picture_element*) override;
  void visit(message_element*) override;
  void visit(entity*)          override;
};
#endif

