#include "logger.h"
#include <ctime>
namespace {
  bool DEBUG = true;
  std::string get_timestamp() {
      // declaration
      time_t rawtime;
      struct tm * timeinfo;
      char buffer[80];
      // initialization
      time(&rawtime);
      timeinfo = localtime(&rawtime);
      // do work
      strftime(buffer, 80, "%c", timeinfo);
      return std::string(buffer); 
  }
}
namespace log {
  void error(const std::string & e) {
      if (DEBUG) 
        logger_.log_string_with_level(std::string("ERROR"), std::string(get_timestamp() + " " +  e), true);
  }

  void message(const std::string & e) {
      if (DEBUG) 
        logger_.log_string_with_level(std::string("MESSAGE"), std::string(get_timestamp() + " " + e));
  }
}
