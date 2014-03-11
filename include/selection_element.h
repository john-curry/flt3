#ifndef SELECTION_VIEW_H
#define SELECTION_VIEW_H

#include "graphic_element.h"
#include "graphic_element_visitor.h"
#include "event_listener.h"
#include "events.h"
#include <string>
#include <vector>
class selection_element : public graphic_element, public event_listener {
  public:
    selection_element(
      std::string name_,
      std::vector<std::string> options_,
      const int x_, const int y_,
      const int fontsize_):
      event_listener(name_), options(options_), x(x_), y(y_), fontsize(fontsize_)  { }
    
    
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
    int get_selection_number() { return current_selection; }
    void accept(graphic_element_visitor * v) { v->visit(this); }    
    const std::vector<std::string> options;
    const int x, y, fontsize;
  private:
    int current_selection = 0;
};
#endif
