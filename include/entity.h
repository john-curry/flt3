#ifndef ENTITY_H
#define ENTITY_H

#include "graphic_element.h"
#include "graphic_element_visitor.h"
#include <string>
class world;
class entity : public graphic_element {
public:
  entity(int x_, int y_, std::string file_, std::string name_, std::string type_):
    x(x_), y(y_), file(file_), name(name_), type(type_) { }
  int x, y;
  const std::string file, name, type;
  bool update(int game_time, world & w) { return true; }
  void draw(std::vector<graphic_element> graphics, world & w) { }
  void accept(graphic_element_visitor * v) override {
    v->visit(std::shared_ptr<entity>(this));
  }
};
#endif
