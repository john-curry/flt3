#ifndef WORLD_STATE_H
#define WORLD_STATE_H
#include <vector>
#include <memory>
#include "graphic_renderer.h"
#include "world.h"
#include "graphic_element.h"
#include "event_listener.h"
class world_state {
public:
  virtual ~world_state() = default;
  virtual bool update(int game_time, world&) = 0;
  virtual void draw(graphic_renderer*, world&) = 0;
  virtual void add_event_listener(event_listener * el) = 0;
  virtual void notify_event_listeners(event e) = 0;
};
#endif
