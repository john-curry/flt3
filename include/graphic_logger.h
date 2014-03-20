#ifndef GRAPHIC_LOGGER_H
#define GRAPHIC_LOGGER_H
#include "graphic_element_visitor.h"
struct graphic_logger : public graphic_element_visitor {
  void visit(std::shared_ptr<picture_element>) override;
  void visit(std::shared_ptr<message_element>) override;
  void visit(std::shared_ptr<entity>)          override;
  void visit(std::shared_ptr<selection_element>) override;
  void visit(std::shared_ptr<dialog_element>) override;
};
#endif

