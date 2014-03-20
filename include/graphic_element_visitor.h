#ifndef GRAPHIC_ELEMENT_VISITOR_H
#define GRAPHIC_ELEMENT_VISITOR_H
#include <memory>
class entity;
class message_element;
class picture_element;
class selection_element;
class dialog_element;
struct graphic_element_visitor {
  virtual ~graphic_element_visitor() = default;
  virtual void visit(std::shared_ptr<message_element>) = 0;
  virtual void visit(std::shared_ptr<picture_element>) = 0;
  virtual void visit(std::shared_ptr<entity>)          = 0;
  virtual void visit(std::shared_ptr<selection_element>) = 0;
  virtual void visit(std::shared_ptr<dialog_element>) = 0;
};
#endif
