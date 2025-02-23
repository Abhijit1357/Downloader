#include "json.hpp"
#include <json/json.h>
#include <string>
#include <vector>

Json::Json() {}

Json::~Json() {}

void Json::parse(const std::string& json) {
    Json::Reader reader;
    reader.parse(json, jsonData);
}

void Json::parse(const std::vector<char>& json) {
    std::string jsonString(json.begin(), json.end());
    parse(jsonString);
}

std::string Json::getString(const std::string& key) {
    return jsonData[key].asString();
}

int Json::getInt(const std::string& key) {
    return jsonData[key].asInt();
}

double Json::getDouble(const std::string& key) {
    return jsonData[key].asDouble();
}

bool Json::getBool(const std::string& key) {
    return jsonData[key].asBool();
}

Json::Value Json::getValue(const std::string& key) {
    return jsonData[key];
}
