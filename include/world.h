#ifndef WORLD_H
#define WORLD_H
#include <stdexcept>
#include <vector>
#include <memory>
#include "graphic_renderer.h"
#include "entity.h"
#include "world_state.h"
class world {
public:
  world() = default;
  world(world_state * state_):state(state_) { }
  void draw(graphic_renderer * gr, world & w) { state->draw(gr, w); }
  bool update(int game_time, world & w) {
    if (!state) {
      throw std::runtime_error("world state not set");
    }
    if (!state->update(game_time, w)) return false; 
    return true;
  }
  void set_state(world_state * state_) { state = state_; }
  std::vector<std::shared_ptr<entity>> get_entities() { return entities; }
private:
    world_state * state;
    std::vector<std::shared_ptr<entity>> entities; 
};
#endif
