#include "world.h"
#include "world_state.h"
#include "helper.h"
void world::draw(graphic_renderer * gr, world & w) {
  ptr_helper::chk_null(state);
  ptr_helper::chk_null(gr);
  state->draw(gr, w);
}

bool world::update(int game_time, world & w) {
  ptr_helper::chk_null(state);
  if (!state->update(game_time, w)) { return false; }

  return true;
}

void world::set_state(world_state * state_) {
  ptr_helper::chk_null(state_);
  state = state_;
  state_->notify_event_listeners(events::state_init);
}

void world::add_event_listener(event_listener * el) {
  ptr_helper::chk_null(el);
  state->add_event_listener(el);
}

void world::notify_event_listeners(event e) {
  state->notify_event_listeners(e);
}
