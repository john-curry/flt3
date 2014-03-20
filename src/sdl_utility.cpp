#include "sdl_utility.h"
#include <stdexcept>
#include <iostream>
TTF_Font * font_from_text_element(std::shared_ptr<text_element> te) {
  std::string fontpath = "assets/" + te->get_font();
  TTF_Font * font = TTF_OpenFont((fontpath).c_str(), te->get_fontsize());
  if (!font) {
    std::cout << "cannot open font: " << te->get_font() << "at path: " << fontpath << std::endl;
    throw std::runtime_error("font is null");
  }
  return font;

}

SDL_Rect rect_from_positionable_element(std::shared_ptr<positionable_element> pe) {
  SDL_Rect ret;
  ret.x = pe->get_x(); ret.y = pe->get_y();
  return ret;
}
