#include "event.h"
bool operator==(const event &lhs, const event &rhs) {
  if ((lhs.name == rhs.name) && 
      (rhs.type == lhs.type)) {
    return true;
  }
  return false;
}

bool operator!=(const event &lhs, const event &rhs) {
  if ((lhs.name != rhs.name) || 
      (rhs.type != lhs.type)) {
    return true;
  }
  return false;
}
