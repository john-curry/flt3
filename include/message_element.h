#ifndef MESSAGE_ELEMENT_H
#define MESSAGE_ELEMENT_H
#include <vector>
#include <string>
#include "graphic_element.h"
class graphic_element_visitor;
struct message_element : public graphic_element {
  message_element(std::string message_, std::string font_, int fontsize_, int x_, int y_):
     message(message_), font(font_), fontsize(fontsize_), x(x_), y(y_) { }

  const std::string message;
  const std::string font;
  const int fontsize;
  const int x, y;
  void accept(graphic_element_visitor * visitor) override;
};
#endif
