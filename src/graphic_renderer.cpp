#include <stdexcept>
#include "graphic_renderer.h"

void graphic_renderer::visit(message_element * g) {
  SDL_Rect loc; loc.x = g->x; loc.y = g->y;
  TTF_Font* font = TTF_OpenFont(("assets/" + g->font).c_str(), g->fontsize);
  SDL_Color c = { 255, 255, 255 };
  SDL_Surface * text = TTF_RenderText_Blended(
    font, g->message.c_str(), c);
  if (!font) { 
  } else {
    SDL_BlitSurface(text, NULL, screen.get(), &loc);
  }
  SDL_FreeSurface(text);
}

void graphic_renderer::visit(picture_element * g) {
  SDL_Surface * pic;
  SDL_Rect loc; loc.x = g->x; loc.y = g->y;
  pic = IMG_Load(("assets/" + g->file).c_str());
  if (!pic) {
  } else {
    SDL_BlitSurface(pic, NULL, screen.get(), &loc);
  }
  SDL_FreeSurface(pic);
}

void graphic_renderer::visit(entity * g) {
  SDL_Surface * pic;
  SDL_Rect loc; loc.x = g->x; loc.y = g->y;
  pic = IMG_Load(("assets/" + g->file).c_str());
  if (!pic) {
    throw std::runtime_error("could not load picture: " + g->file);
  } else {
    SDL_BlitSurface(pic, NULL, screen.get(), &loc);
  }
  SDL_FreeSurface(pic);
}
