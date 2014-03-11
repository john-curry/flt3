#include <iostream>
#include "graphic_logger.h"
#include "picture_element.h"
#include "message_element.h"
#include "selection_element.h"
#include "entity.h"
#include "dialog_element.h"
void graphic_logger::visit(picture_element * g) {
  std::cout << "logging a picture at "
    << g->file << " with x: " << g->x << " and y: " << g->y << std::endl;
}
void graphic_logger::visit(message_element * g) {
  std::cout << "logging a message "
    << g->message << " with x: " << g->x << " and y: " << g->y << std::endl;
}

void graphic_logger::visit(entity * g) {
  std::cout << "logging " << g->name << " with file " 
    << g->file << " and type " << g->type << " and position " << "(" << g->x << "," << g->y << ")" 
      << std::endl;
}

void graphic_logger::visit(selection_element * g) {
  std::cout << "logging " << g->name 
    << " position " << "(" << g->x << "," << g->y << ")" << std::endl;
}
void graphic_logger::visit(dialog_element * g) {
  std::cout << "logging dialog element" << std::endl;
}

