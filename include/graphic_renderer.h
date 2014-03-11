#ifndef GRAPHIC_RENDERER_H
#define GRAPHIC_RENDERER_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <memory>
#include "graphic_element_visitor.h"
#include "picture_element.h"
#include "message_element.h"
#include "selection_element.h"
#include "dialog_element.h"
#include "entity.h"
class graphic_renderer : public graphic_element_visitor {
  public:
    graphic_renderer(std::shared_ptr<SDL_Surface> screen_):screen(screen_) { }
    void visit(message_element*) override;
    void visit(picture_element*) override;
    void visit(entity*         ) override;
    void visit(selection_element *) override;
    void visit(dialog_element*) override;
  private:
    std::shared_ptr<SDL_Surface> screen;
};
#endif

