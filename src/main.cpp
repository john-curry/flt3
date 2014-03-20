#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "graphic_logger.h"
#include "graphic_renderer.h"
#include "graphic_element.h"
#include "world.h"
#include "world_state.h"
#include "world_state_test.h"
#include "event.h"
#include "events.h"
#include "selection_element.h"
#include "dialog_element.h"
#include "timer.h"
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
  if (!screen) { return -1; }
  /*
  std::vector<std::string> selections {
    "new game", "load_game"
  };
  std::vector<std::string> dialogs {
    "we are waiting for the bus", "i cant help myself"
  };
  auto selection = std::make_shared<selection_element>("selection_name", selections, 40, 40, 40);
  auto dialog    = std::make_shared<dialog_element>(dialogs, 0, 100, "Minecrafter_3.ttf", 16);

  std::vector<std::shared_ptr<graphic_element>> graphics  {
    dialog,
//    selection
  };
*/
 // view v(graphics);   
  //auto gr = new graphic_renderer(screen); 
  //auto gl = new graphic_logger();
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
              pool.notify(events::controller_confirm);
            break;
            case SDLK_DOWN:
              log::message("controller pressed down");
              pool.notify(events::controller_down);
            break;
            case SDLK_UP:
              log::message("controller pressed up");
              pool.notify(events::controller_up);
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
