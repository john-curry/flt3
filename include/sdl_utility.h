#ifndef JSONTOGRAPHIC_UTILITY_H
#define JSONTOGRAPHIC_UTILITY_H
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <string>
#include <memory>
#include "text_element.h"
#include "positionable_element.h"
TTF_Font * font_from_text_element(std::shared_ptr<text_element> te);
SDL_Rect  rect_from_positionable_element(std::shared_ptr<positionable_element> pe);
#endif
