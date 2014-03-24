#ifndef WORLD_STATE_TEST_H
#define WORLD_STATE_TEST_h
#include <memory>
#include <string>
#include "world_state.h"
#include "view.h"
#include "graphic_renderer.h"
#include "graphic_logger.h"
#include "assetsheet.h"
#include "event_listener.h"
#include "events.h"
#include "logger.h"
#include "helper.h"
class world_state_test 
  : public world_state, 
    public event_listener {

  public:
    world_state_test(std::string assets, 
      std::shared_ptr<world> world_ptr_)
      : event_listener("world_test_state"), 
        world_ptr(world_ptr_), 
        state_view(assetsheet(assets).get_assets()) { }

    void action_preformed(event e) override;
    std::string get_name() override;
    void draw(graphic_renderer * gr, world & w) override;
    bool update(int game_time, world & w) override;
    void add_event_listener(event_listener *el) override;
    void notify_event_listeners(event e) override;
  private:
    std::shared_ptr<world> world_ptr;
    listener_pool lp;
    view state_view;
    bool has_init = false;
};

#endif
