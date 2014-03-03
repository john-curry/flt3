#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "view.h"
#include "graphic_logger.h"
#include "graphic_renderer.h"
#include "graphic_mover.h"
#include "picture_element.h"
#include "message_element.h"
#include "version_one_converter.h"
#include "assetsheet.h"
#include "entity.h"
#include "world.h"
#include "world_state.h"
#include "world_state_test.h"
using namespace std;
int main() {
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
    return -1;
  }
  TTF_Init();
  auto screen = std::shared_ptr<SDL_Surface>(
    SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE));
  if (!screen) { return -1; }
  
  auto wst = new world_state_test("assets/title_view.json");
  auto gl  = new graphic_renderer(screen);
  world w(wst);
  SDL_Event e;
  bool running = true;
  while (running) {
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
        case SDL_QUIT:
          running = false;
        break;
      } 
      SDL_FillRect(screen.get(), NULL, 0x000000);
      w.update(100, w);
      w.draw(gl, w);
      SDL_Flip(screen.get());
      SDL_Delay(100); 
    }
  }
  delete wst;
  TTF_Quit();
  SDL_Quit();
  return 0;
}
