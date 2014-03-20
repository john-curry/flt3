#include "logger.h"
#include <ctime>
#include <fstream>
#include <iostream>
namespace { 
  const bool DEBUG = true;
  const std::string get_timestamp() {
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
  void log_string_with_level(const std::string & level, const std::string & e) {
    std::ofstream logfile("flt3.log", std::fstream::app);
    std::string timestamp = get_timestamp();
    logfile << level << " [" << timestamp << "] " << e << std::endl;
    std::cout << level << " [" << timestamp << "] " << e << std::endl;
    logfile.close();
  }
}

namespace log {

  void error(const std::string & e) {
    if (DEBUG) 
      log_string_with_level("ERROR", e);
  }

  void message(const std::string & e) {
    if (DEBUG) 
      log_string_with_level("MESSAGE", e);
  }
}
