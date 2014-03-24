#include "world_state_test.h"

void world_state_test::action_preformed(event e) {
  if (e == events::state_init) {
    
  }
  if (e == events::controller_confirm) {

  }
}

std::string world_state_test::get_name() {
  return event_listener::name;
}

void world_state_test::draw(graphic_renderer * gr, world & w) { 
  ptr_helper::chk_null(gr);
  state_view.accept(gr);
}
bool world_state_test::update(int game_time, world & w) {
  return true; 
}

void world_state_test::add_event_listener(event_listener * el) {
  lp.add_listener(el);
}


void world_state_test::notify_event_listeners(event e) {
  lp.notify(e);
}


