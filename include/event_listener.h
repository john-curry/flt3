#ifndef EVENT_LISTNER_H
#define EVENT_LISTNER_H
#include <string>
#include <map>
#include <functional>
#include "event.h"

class event_listener {
  public:
    event_listener(std::string name_):name(name_) { }
    virtual void action_preformed(event e) = 0;
    virtual std::string get_name() = 0;
    std::string name;
};

class functional_listener : public event_listener {
  public:
    functional_listener(std::string name_, std::function<void (event)> callback_):
      event_listener(name_), callback(callback_) { }
    void action_preformed(event e) { callback(e); }
    std::string get_name() override 
      { return event_listener::name; }
  private:
    std::function<void (event)> callback;
};

class listener_pool {
public:
  listener_pool() = default;
  void add_listener(event_listener*);
  void remove_listener(event_listener*);
  void notify(event e);
private:
  std::map<std::string, event_listener*> listeners;
};
#endif
