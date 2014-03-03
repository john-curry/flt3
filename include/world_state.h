#ifndef WORLD_STATE_H
#define WORLD_STATE_H
#include <vector>
#include <memory>
#include "graphic_renderer.h"
#include "world.h"
#include "graphic_element.h"
struct world_state {
  virtual ~world_state() = default;
  virtual bool update(int, world&) = 0;
  virtual void draw(graphic_renderer*, world&) = 0;
};
#endif
