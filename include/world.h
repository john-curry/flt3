#ifndef WORLD_H
#define WORLD_H
#include <stdexcept>
#include <vector>
#include <memory>
#include "graphic_renderer.h"
#include "entity.h"
#include "event_listener.h"
#include "events.h"
class world_state;
class world {
public:
  world() = default;
  world(world_state * state_):state(state_) { }
  void draw(graphic_renderer * gr, world & w);
  bool update(int game_time, world & w);
  void set_state(world_state * state_);
  void add_event_listener(event_listener * el);
  void notify_event_listeners(event e);
    
private:
    world_state * state;
};
#endif
