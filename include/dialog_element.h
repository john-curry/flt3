#ifndef DIALOG_ELEMENT_H
#define DIALOG_ELEMENT_H
#include "graphic_element.h"
#include "graphic_element_visitor.h"
#include "timer.h"

class dialog_element : public graphic_element {
public:
  dialog_element(const std::vector<std::string> textblock_, 
    const int x_, const int y_, 
    const std::string font_, const int fontsize_):
    textblock(textblock_), x(x_), y(y_), font(font_), fontsize(fontsize_) { }
  
  void next_text_block() {
    current_text_block += 1;
    current_string_position = 0;
    if (current_text_block >= textblock.size()) {
      is_done = true;
      current_text_block -= 1;
    }
    std::cout << "current_text_block: " << current_text_block << std::endl;
  }

  void next_character() {
    current_string_position += 1;
    if (current_string_position > textblock[current_text_block].size()){
      is_text_line_done = true;
      current_string_position -= 1;
    }
    std::cout << "current_string_position: " << current_string_position << std::endl;
  }

  std::string get_current_string() {

    std::string ret = textblock[current_text_block].substr(0, current_string_position);
    std::cout << "current substring: " << ret << std::endl;
    std::cout << "current string: " << textblock[current_text_block] << std::endl;

    return ret;
  }
  
  void accept(graphic_element_visitor * v) override {
    v->visit(this);
  }

  const std::vector<std::string> textblock;
  const int x, y;
  const std::string font;
  const int fontsize;
private:
  int current_text_block = 0;
  int current_string_position = 0;
  bool is_done = false;
  bool is_text_line_done = false;
};
#endif
