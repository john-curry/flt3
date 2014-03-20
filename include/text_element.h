#ifndef TEXT_ELEMENT_H
#define TEXT_ELEMENT_H
#include <string>
#include "positionable_element.h"
struct text_element {
  virtual std::string get_font() const = 0;
  virtual int get_fontsize() const = 0;
 };
#endif
