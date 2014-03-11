#include <stdexcept>
#include "graphic_renderer.h"


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

void graphic_renderer::visit(message_element * g) {
  SDL_Rect loc; loc.x = g->x; loc.y = g->y;
  TTF_Font* font = TTF_OpenFont(("assets/" + g->font).c_str(), g->fontsize);
  SDL_Color c = { 255, 255, 255 };
  SDL_Surface * text = TTF_RenderText_Blended(
    font, g->message.c_str(), c);
  if (!font) { 
    throw std::runtime_error("could not open font for message element");
  } else {
    SDL_BlitSurface(text, NULL, screen.get(), &loc);
  }
  SDL_FreeSurface(text);
}

void graphic_renderer::visit(selection_element * g) {
  SDL_Color foreground = { 0, 0, 0 };
  SDL_Color background = { 255, 255, 255 };  
  SDL_Color hlbackground = { 0, 255, 0 }; 
  TTF_Font* font = TTF_OpenFont(
    "assets/Minecrafter_3.ttf", g->fontsize);
  int height  = TTF_FontHeight(font); 

  std::vector<SDL_Surface*> surfaces;
  if (!font) {
    throw std::runtime_error("could not open font for " + g->get_name());
  } else {
    for (int i = 0; i < g->options.size(); ++i) {
      SDL_Color tmp_color = background;
      if (i == g->get_selection_number()) {
        tmp_color = hlbackground;
      }
      auto surface = 
       TTF_RenderText_Shaded(
         font, 
         g->options[i].c_str(), 
         foreground, tmp_color 
       );

      SDL_Rect tmp;
      tmp.x = g->x;
      tmp.y = g->y + (i * height);
      SDL_BlitSurface(surface, NULL, screen.get(), &tmp); 
      SDL_FreeSurface(surface);
    }
  }
}

void graphic_renderer::visit(dialog_element * g) {
  SDL_Rect loc; loc.x = g->x; loc.y = g->y;
  TTF_Font* font = TTF_OpenFont(("assets/" + g->font).c_str(), g->fontsize);
  SDL_Color c = { 255, 255, 255 };
  SDL_Surface * text = TTF_RenderText_Blended(
    font, g->get_current_string().c_str(), c);
  if (!font) { 
    throw std::runtime_error("could not open font for dialog");
  } else {
    SDL_BlitSurface(text, NULL, screen.get(), &loc);
  }
  SDL_FreeSurface(text);
}


