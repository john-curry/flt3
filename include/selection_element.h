#ifndef SELECTION_VIEW_H
#define SELECTION_VIEW_H

#include "graphic_element.h"
#include "text_element.h"
#include "positionable_element.h"
#include "graphic_element_visitor.h"
#include "event_listener.h"
#include "events.h"
#include <string>
#include <vector>
#include <memory>
class selection_element : 
// interfaces
  public graphic_element,
  public text_element, 
  public positionable_element,
  public event_listener,
  public std::enable_shared_from_this<selection_element> {
  
  public:
    selection_element(
      std::string name_,
      std::vector<std::string> options_,
      const int x_, const int y_,
      const std::string font_,
      const int fontsize_):
        event_listener(name_), 
        options(options_), x(x_), y(y_), 
        font(font_), fontsize(fontsize_)  { }

    int get_selection_number() { return current_selection; }
    std::vector<std::string> get_options() { return options; }
    // overrides 
    void accept(graphic_element_visitor * v) { v->visit(shared_from_this()); }
    // event_listener    
    std::string get_name() override { return event_listener::name; }
    void action_preformed(event e) override {
      if (e == events::controller_up) {
        if (current_selection == 0) { }
        else { current_selection -= 1; }
      }
      if (e == events::controller_down) {
        if (current_selection >= options.size() - 1) { }
        else { current_selection += 1; }
      }
    }
    // positionable_element
    int get_x() override { return x; }
    int get_y() override { return y; }
    // text_element
    int get_fontsize() const override { return fontsize; }
    std::string get_font() const override { return font; }

  private:
    int current_selection = 0;
    const std::vector<std::string> options;
    const int x, y;
    const std::string font;
    const int fontsize;
};
#endif
