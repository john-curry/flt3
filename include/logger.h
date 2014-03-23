#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
#include <iostream>
namespace {
  class logger {
    public:
      logger() { logfile.open("flt3.log", std::ofstream::app); }
      ~logger() { logfile.close(); }
      void log_string_with_level(const std::string & level, const std::string & str, bool to_std_out = false) {
        // log to file
        logfile << "[ " << level << " ] " << str << std::endl;
        // std::cout log
        if (to_std_out) {
          std::cout << "[ " << level << " ] " << str << std::endl;
        }
      }
    private:
      std::ofstream logfile;
  };
}

namespace log {
  logger logger_;
  void message(const std::string & msg);
  void error  (const std::string & err);
}
#endif

