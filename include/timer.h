#ifndef TIMER_H
#define TIMER_H
#include <vector>
#include <ctime>
#include <functional>
#include <iostream>
#include <stdexcept>
class timer {
  public:
    timer(int millis_): end(millis_), start(std::clock()) { }
    void update() { // in millis
      clocks_since = clock() - start;
      double time_since = ((double)clocks_since / ((double)(CLOCKS_PER_SEC) / (double)(1000)));
      if (end <= time_since) {
        is_done = true;
      }
    }
    bool done() { return is_done; }

  private:
    const int end;
    const int start;
    int clocks_since = 0;
    bool is_done = false;
};

class timer_pool {
  public:
    timer_pool() = default;
    void add_timer(timer * t) { t_pool.push_back(t); } 

    void remove_timer(timer * t) {

      for (auto t_ = t_pool.begin(); 
        t_ != t_pool.end(); ++t_) {
        if (t == *t_) {
          t_pool.erase(t_);
          break;
        }
      }
    }
    void update() { 
      for (auto & t : t_pool) {
        t->update();
      }
    }

  private:
    std::vector<timer*> t_pool; 
};

#endif
