#ifndef  VERSION_ONE_CONVERTER_H
#define  VERSION_ONE_CONVERTER_H
#include <json/reader.h>
#include <string>
#include <stdexcept>
#include "picture_element.h"
#include "message_element.h"
#include "json_converter.h"

class version_one_converter : public json_converter {
  public:
    version_one_converter() = default;
    std::shared_ptr<graphic_element> make_element(std::string type, Json::Value v) override;
    std::shared_ptr<graphic_element> make_picture(std::string field, Json::Value);
    std::shared_ptr<graphic_element> make_message(std::string field, Json::Value);
    int get_version() override { return 1; }
};
#endif
