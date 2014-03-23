#include "event_listener.h"
#include "helper.h"
#include "logger.h"
#include <utility>
#include <stdexcept>
void listener_pool::add_listener(event_listener * el) {
  if (el->get_name().empty()) {
    throw std::runtime_error("error, unamed event listener");
  }
  ptr_helper::chk_null(el);
  log::message("adding event_listener");
  log::message(el->get_name());
  listeners.insert(std::pair<std::string, event_listener*>(el->get_name(), el));
  log::message("listener added");
}

void listener_pool::remove_listener(event_listener * el) {
  listeners.erase(el->get_name());
}

void listener_pool::notify(event e) {
  for (auto & el : listeners) {
    el.second->action_preformed(e);
  }
}
