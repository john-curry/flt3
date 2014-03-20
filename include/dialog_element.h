#ifndef DIALOG_ELEMENT_H
#define DIALOG_ELEMENT_H
#include "graphic_element.h"
#include "graphic_element_visitor.h"
#include "text_element.h"
#include "positionable_element.h"
#include "timer.h"
#include "logger.h"
#include <memory>
class dialog_element 
  : public graphic_element, 
    public text_element,
    public positionable_element,
    public std::enable_shared_from_this<dialog_element> {

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
    log::message("current_text_block: " + current_text_block);
  }

  void next_character() {
    current_string_position += 1;
    if (current_string_position > textblock[current_text_block].size()){
      is_text_line_done = true;
      current_string_position -= 1;
    }
    log::message("current_string_position: " + current_string_position);
  }

  std::string get_current_string() {

    std::string ret = textblock[current_text_block].substr(0, current_string_position);
    log::message("current substring: " + ret);
    log::message( "current string: " + textblock[current_text_block]); 

    return ret;
  }
  // accessor for textblock
//  std::vector<std::string> get_textblock() { return textblock; }  
  // overrides
  void accept(graphic_element_visitor * v) override {
    v->visit(shared_from_this());
  }
  int get_x() override { return x; }
  int get_y() override { return y; }
  
  std::string get_font() const override { return font; }
  int get_fontsize() const override { return fontsize; }
   
private:
  const std::vector<std::string> textblock;
  const int x, y;
  const std::string font;
  const int fontsize;
  int current_text_block = 0;
  int current_string_position = 0;
  bool is_done = false;
  bool is_text_line_done = false;
};
#endif
