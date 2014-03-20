#ifndef POSITIONABLE_ELEMENT_H
#define POSITIONABLE_ELEMENT_H
struct positionable_element {
  virtual int get_x() = 0;
  virtual int get_y() = 0;
};
#endif
