#ifndef WORLD_STATE_TEST_H
#define WORLD_STATE_TEST_h
#include "world_state.h"
#include "view.h"
#include "graphic_renderer.h"
#include "assetsheet.h"

class world_state_test : public world_state {
  public:
    world_state_test(std::string assets):
      state_view(assetsheet(assets).get_assets()) { }
    
    void draw(graphic_renderer * gr, world & w) override { 
      state_view.accept(gr);
    }

    bool update(int game_time, world & w) override { return true; }
  private:
    view state_view;
};

#endif
