#ifndef EVENT_H
#define EVENT_H
#include <string>
struct event {
  event(std::string name_, std::string type_):
        name(name_), type(type_) { }
  std::string name;
  std::string type;
};

bool operator==(const event &lhs, const event &rhs);
bool operator!=(const event &lhs, const event &rhs);

#endif
