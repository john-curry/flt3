#include "event_listener.h"
#include <utility>
#include <stdexcept>
void listener_pool::add_listener(event_listener * el) {
  if (el->get_name().empty()) {
    throw std::runtime_error("error, unamed event listener");
  }

  listeners.insert(std::pair<std::string, event_listener*>(el->get_name(), el));
}

void listener_pool::remove_listener(event_listener * el) {
  listeners.erase(el->get_name());
}

void listener_pool::notify(event e) {
  for (auto & el : listeners) {
    el.second->action_preformed(e);
  }
}
