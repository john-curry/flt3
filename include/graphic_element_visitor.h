#ifndef GRAPHIC_ELEMENT_VISITOR_H
#define GRAPHIC_ELEMENT_VISITOR_H
class entity;
class message_element;
class picture_element;
struct graphic_element_visitor {
  virtual ~graphic_element_visitor() = default;
  virtual void visit(message_element*) = 0;
  virtual void visit(picture_element*) = 0;
  virtual void visit(entity*)          = 0;
};
#endif
