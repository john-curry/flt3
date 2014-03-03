#ifndef JSON_CONVERTER_H
#define JSON_CONVERTER_H
#include <string>
#include <stdexcept>
#include <memory>
#include <json/reader.h>
#include "graphic_element.h"
class json_converter {
public:
  virtual std::shared_ptr<graphic_element> make_element(std::string, Json::Value v) = 0;
  virtual int get_version() = 0;
protected:
  // assuming that an empty field is a bad thing
  bool check_field(std::string field, Json::Value * v) {
    return (!((*v)[field]).empty());
  }
  Json::Value * safe_get(std::string field, Json::Value * v) {
    if (check_field(field, v)) return v;
    else {                                                      
      // assuming that there is an id field in the json value
      throw std::runtime_error("field: " + field + " is not in element of type " + (*v)["id"].asString());
    }
  }
};
#endif
