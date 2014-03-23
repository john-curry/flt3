#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "world.h"
#include "world_state.h"
#include "world_state_test.h"
#include "event.h"
#include "events.h"
#include "logger.h"
#include "helper.h"
using namespace std;
int main() {
  log::message("STARTING GAME ============================");
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return -1;
  }

  TTF_Init();
  auto screen = std::shared_ptr<SDL_Surface>(
    SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE));
  if (!screen) { 
    log::error("screen failure"); 
    return -1;
  }
  world w;
  log::message("making test world state");
  auto wst = new world_state_test("assets/title_view.json", std::shared_ptr<world>(&w));
  
  log::message("setting world state");
  w.set_state(wst);

  auto gr  = new graphic_renderer(screen);
  auto pool = listener_pool();
  pool.add_listener(wst);
  SDL_Event e;
  bool running = true;
  log::message("starting game loop");
  while (running) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
        case SDL_QUIT:
          running = false;
        break;
        case SDL_KEYDOWN:
          switch (e.key.keysym.sym) {
            case SDLK_RETURN:
              log::message("controller pressed enter");
//              ep.register_event(events::controller_confirm);
            break;
            case SDLK_DOWN:
              log::message("controller pressed down");
//              ep.register_event(events::controller_down);
            break;
            case SDLK_UP:
              log::message("controller pressed up");
 //             ep.register_event(events::controller_up);
            break;
            default: break;
          }
        break;
        default: break;
      }
    }

    SDL_FillRect(screen.get(), NULL, 0x000000);
    log::message("updating world");
    w.update(100, w);
    log::message("drawing world");
    w.draw(gr, w);
    log::message("flipping screen");
    SDL_Flip(screen.get());
    SDL_Delay(100); 
  }
  TTF_Quit();
  SDL_Quit();
  return 0;
}
