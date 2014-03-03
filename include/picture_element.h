#ifndef PICTURE_ELEMENT_VISITOR_H
#define PICTURE_ELEMENT_VISITOR_H
#include <string>
#include "graphic_element.h"
class graphic_element_visitor;
struct picture_element : public graphic_element {
  picture_element(int x_, int y_, int w_, int h_, std::string file_):
    x(x_), y(y_), w(w_), h(h_), file(file_) { }
  int x, y, w, h;
  const std::string file; 
  void accept(graphic_element_visitor*) override;
};
#endif
