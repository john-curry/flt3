#include "json_converter.h"
#include "version_one_converter.h"
std::shared_ptr<graphic_element> version_one_converter::make_element(std::string type, Json::Value v) {
  if (type == "picture") {
    return make_picture(type, v);
  }
  if (type == "message") {
    return make_message(type, v);
  }
  throw std::runtime_error("graphic element: " + type + " not supported in this converter version");
}

std::shared_ptr<graphic_element> version_one_converter::make_picture(std::string field, Json::Value v) {
  std::string pic_file = v["file"].asString();
  int x = v["x"].asInt();
  int y = v["y"].asInt();
  int w = v["w"].asInt();
  int h = v["h"].asInt();
  return std::make_shared<picture_element>(x, y, w, h, pic_file);
}


std::shared_ptr<graphic_element> version_one_converter::make_message(std::string field, Json::Value v) {
  std::string message = v["message"].asString(); // = json_converter::safe_get("message", &v)->asString();
  std::string font    = v["font"].asString();
  int fontsize = v["fontsize"].asInt();;
  int x =  v["x"].asInt();
  int y =  v["y"].asInt();
  return std::make_shared<message_element>(message, font, fontsize, x, y);
}


