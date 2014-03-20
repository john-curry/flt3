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
}

void graphic_renderer::visit(std::shared_ptr<selection_element> g) {
}

void graphic_renderer::visit(std::shared_ptr<dialog_element> g) {
}


