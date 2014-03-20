#ifndef WORLD_STATE_TEST_H
#define WORLD_STATE_TEST_h
#include <memory>
#include "world_state.h"
#include "view.h"
#include "graphic_renderer.h"
#include "graphic_logger.h"
#include "assetsheet.h"
#include "event_listener.h"
#include "events.h"
#include "logger.h"
#include "helper.h"
class world_state_test : public world_state, public event_listener {
  public:
    world_state_test(std::string assets, std::shared_ptr<world> world_ptr_): 
      event_listener("world_test_state"), 
      world_ptr(world_ptr_), 
      state_view(assetsheet(assets).get_assets()) { }

    void action_preformed(event e) override { 
      if (e == events::controller_confirm) {
        //auto new_state = new world_state_test("assets/menu_sheet.json", world_ptr);
        //world_ptr->set_state(new_state);
      }
    }
     
    std::string get_name() override { return event_listener::name; }

    void draw(graphic_renderer * gr, world & w) override { 
      ptr_helper::chk_null(gr);
      state_view.accept(gr);
    }

    bool update(int game_time, world & w) override { 
      state_view.accept(logger.get()); 
      return true; 
    }
  private:
    std::shared_ptr<world> world_ptr;
    std::shared_ptr<graphic_logger> logger = std::make_shared<graphic_logger>();
    view state_view;
    bool has_init = false;
};

#endif
