#include <stdexcept>
#include "graphic_renderer.h"
#include "helper.h"
#include "sdl_utility.h"
#include "logger.h"
void graphic_renderer::visit(std::shared_ptr<picture_element> g) {
  log::message("drawing picture element");
  using namespace ptr_helper;
  SDL_Surface * img = IMG_Load(("assets/" + g->get_file()).c_str());
  chk_null(img);
  SDL_Rect loc = rect_from_positionable_element(g);
  SDL_BlitSurface(img, NULL, screen.get(), &loc);
  SDL_FreeSurface(img);
}

void graphic_renderer::visit(std::shared_ptr<entity> g) {
  throw std::runtime_error("entity graphic_renderer method stub");
}

void graphic_renderer::visit(std::shared_ptr<message_element> g) {
  log::message("drawing message element");
  auto loc = rect_from_positionable_element(g);
  auto font = font_from_text_element(g);
  ptr_helper::chk_null(font);
  SDL_Color c = { 255, 255, 255 };
  auto text = TTF_RenderText_Blended(
    font, g->get_message().c_str(), c);
  SDL_BlitSurface(text, NULL, screen.get(), &loc);
  SDL_FreeSurface(text);
  TTF_CloseFont(font);
}

void graphic_renderer::visit(std::shared_ptr<selection_element> g) {
  log::message("drawing selection_element");
  auto font = font_from_text_element(g);
  ptr_helper::chk_null(font);
  auto start_loc = rect_from_positionable_element(g);
  int text_height = TTF_FontHeight(font);
  SDL_Color fg = { 255, 255, 255 };
  SDL_Color bg = { 0  , 0  , 0   };
  SDL_Color hbg= { 255, 0  , 0   };
  auto options = g->get_options();
  for (auto i = 0; i < options.size(); ++i) {
    auto opt = options[i];
    auto curr_color = bg;
    if (i == g->get_selection_number()) {
      curr_color = hbg;
    }
    log::message("text height ");
    SDL_Rect loc;
    loc.y = start_loc.y + (i * text_height);;
    loc.x = start_loc.x;
    auto tmp_surf = TTF_RenderText_Shaded(
      font, opt.c_str(), fg, curr_color);
    ptr_helper::chk_null(tmp_surf);
    SDL_BlitSurface(tmp_surf, NULL, screen.get(), &loc);
    SDL_FreeSurface(tmp_surf);
  }
  TTF_CloseFont(font);
}

void graphic_renderer::visit(std::shared_ptr<dialog_element> g) {
  throw std::runtime_error("dialog_element method stub for graphic_renderer");
}


