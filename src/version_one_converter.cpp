#include "json_converter.h"
#include "version_one_converter.h"
#include "logger.h"
#include <vector>
std::shared_ptr<graphic_element> version_one_converter::make_element(std::string type, Json::Value v) {
  if (type == "picture") {
    return make_picture(type, v);
  }
  if (type == "message") {
    return make_message(type, v);
  }
  if (type == "dialog") {
    return make_dialog(type, v);
  }
  if (type == "selection") {
    return make_selection(type, v);
  }
  throw std::runtime_error("graphic element: " + type + " not supported in this converter version");
}

std::shared_ptr<graphic_element> version_one_converter::make_picture(std::string field, Json::Value v) {
  std::string pic_file = v["file"].asString();
  int x = v["x"].asInt();
  int y = v["y"].asInt();
  int w = v["w"].asInt();
  int h = v["h"].asInt();
//  return std::make_shared<picture_element>(x, y, w, h, pic_file);
  return std::shared_ptr<picture_element>(new picture_element(x, y, w, h, pic_file));
}


std::shared_ptr<graphic_element> version_one_converter::make_message(std::string field, Json::Value v) {
  std::string message = v["message"].asString(); // = json_converter::safe_get("message", &v)->asString();
  std::string font    = v["font"].asString();
  int fontsize = v["fontsize"].asInt();;
  int x =  v["x"].asInt();
  int y =  v["y"].asInt();
  return std::make_shared<message_element>(message, x, y, fontsize, font);
  return std::shared_ptr<message_element>(new message_element(message, x, y, fontsize, font));

}


std::shared_ptr<graphic_element> version_one_converter::make_selection(std::string field, Json::Value v) {
  std::string name = v["name"].asString();
  std::string font = v["font"].asString();
  int x = v["x"].asInt();
  int y = v["y"].asInt();
  int fontsize = v["fontsize"].asInt();
  std::vector<std::string> options;
  for (auto o = v["options"].begin(); 
       o != v["options"].end(); ++o) {
    options.push_back((*o).asString());
  }
  return std::make_shared<selection_element>(name, options, x, y, font, fontsize);  
}



std::shared_ptr<graphic_element> version_one_converter::make_dialog(std::string field, Json::Value v) {
  int x = v["x"].asInt();
  int y = v["y"].asInt();
  int fontsize = v["fontsize"].asInt();
  std::string font = v["font"].asString();
  std::vector<std::string> t_block;
  for (auto o = v["dialog"].begin(); 
       o != v["dialog"].end(); ++o) {

    t_block.push_back((*o).asString());
  }
  return std::make_shared<dialog_element>(t_block, x, y, font, fontsize);
}
