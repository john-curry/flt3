#ifndef ASSET_H
#define ASSET_H 
#include <string>
#include <vector>
#include <memory>
#include <json/reader.h>
#include "graphic_element.h"
#include "json_converter.h"
class assetsheet {
  public:
    assetsheet(std::string file_):file(file_) { }
    int get_version();
    std::vector<std::shared_ptr<graphic_element>> get_assets(std::shared_ptr<json_converter>);
    std::vector<std::shared_ptr<graphic_element>> get_assets();
  private:
    Json::Value get_root();
    std::string file;
};
#endif
