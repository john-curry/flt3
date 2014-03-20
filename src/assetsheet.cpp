#include "assetsheet.h"
#include "version_one_converter.h"
#include <stdexcept>
#include <fstream>
#include <memory>
std::vector<std::shared_ptr<graphic_element>> assetsheet::get_assets(std::shared_ptr<json_converter> converter) {
  // return elements
  std::vector<std::shared_ptr<graphic_element>> elements;
  // sanity check
  auto root = get_root();
  if (root["content"].empty()) {
    throw std::runtime_error("missing content field in assetsheet: " + file);
  } else {
    // actually do some convertion
    auto content = root["content"];
    for (auto c = content.begin(); c != content.end(); ++c) {
      std::string id = (*c)["id"].asString();
      log::message("converting id: "+ id);
      elements.push_back(converter->make_element(id, *c));
    }
  }
  return elements;
}

std::vector<std::shared_ptr<graphic_element>> assetsheet::get_assets() {
  std::shared_ptr<json_converter> converter;
  switch (get_version()) {
    case 1:
      converter = std::make_shared<version_one_converter>();
    break;
    default:
      throw std::runtime_error("assetsheet version not supported");
    break;
  }
  return get_assets(converter);
}

int assetsheet::get_version() {
  // unsafe 
  return get_root()["version"].asInt(); 
}

Json::Value assetsheet::get_root() {
  Json::Value root;
  Json::Reader reader;
  std::ifstream doc(file);
  if (!reader.parse(doc, root, false)) {
    throw std::runtime_error("error parsing assetsheet: " + file + reader.getFormattedErrorMessages());
  }
  // set encoding in case is was forgotten
  auto encoding = root.get("encoding", "UTF-8");
  return root;
}
