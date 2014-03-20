#include <iostream>
#include "graphic_logger.h"
#include "picture_element.h"
#include "message_element.h"
#include "selection_element.h"
#include "entity.h"
#include "dialog_element.h"
#include "logger.h"
void graphic_logger::visit(std::shared_ptr<picture_element > g) {
//  log::message("logging picture_element");
}
void graphic_logger::visit(std::shared_ptr<message_element > g) {
  log::message("logging message_element");
}

void graphic_logger::visit(std::shared_ptr<entity > g) {
  log::message("logging entity");
}

void graphic_logger::visit(std::shared_ptr<selection_element > g) {
  log::message("logging selection element");
}
void graphic_logger::visit(std::shared_ptr<dialog_element > g) {
  log::message("logging dialog_element");
}

