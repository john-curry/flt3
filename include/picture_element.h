#ifndef PICTURE_ELEMENT_VISITOR_H
#define PICTURE_ELEMENT_VISITOR_H
#include <string>
#include <memory>
#include "graphic_element.h"
#include "positionable_element.h"
class graphic_element_visitor;
class picture_element 
  : public graphic_element, 
    public positionable_element,
    public std::enable_shared_from_this<picture_element> {
public:
  picture_element(int x_, int y_, int w_, int h_, std::string file_):
    x(x_), y(y_), w(w_), h(h_), file(file_) { }
    // positionable_element overrides
    int get_x() override { return x; }
    int get_y() override { return y; }
    std::string get_file() const { return file; }
      
    void accept(graphic_element_visitor*) override;
private:
  int x, y, w, h;
  const std::string file; 
};
#endif
