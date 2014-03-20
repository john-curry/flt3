#ifndef MESSAGE_ELEMENT_H
#define MESSAGE_ELEMENT_H
#include <vector>
#include <string>
#include "graphic_element.h"
#include "text_element.h"
class graphic_element_visitor;
class message_element 
  : public graphic_element, 
    public text_element,
    public positionable_element,
    public std::enable_shared_from_this<message_element> {
public:
  message_element(std::string message_, int x_, int y_, int fontsize_, std::string font_):
    message(message_), x(x_), y(y_), fontsize(fontsize_), font(font_) { } 
  // positionable_element overrides
  int get_x() override { return x; }
  int get_y() override { return y; }
  // text_element overrides
  int get_fontsize() const override { return fontsize; }
  std::string get_font() const override { return font; }
  std::string get_message() const { return message; }
     
private:
  const std::string message;
  int x, y, fontsize;
  const std::string font;
  void accept(graphic_element_visitor * visitor) override;
  
};
#endif
