#include "graphic_mover.h"
#include "picture_element.h"
#include "message_element.h"
#include "entity.h"
void graphic_mover::visit(picture_element * g) {
  g->x += 2;
}
void graphic_mover::visit(message_element * g) {
}
void graphic_mover::visit(entity * g) {
 }
