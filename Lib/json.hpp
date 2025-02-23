#ifndef JSON_HPP
#define JSON_HPP

#include <json/json.h>
#include <string>
#include <vector>

class Json {
public:
    Json();
    ~Json();

    void parse(const std::string& json);
    void parse(const std::vector<char>& json);

    std::string getString(const std::string& key);
    int getInt(const std::string& key);
    double getDouble(const std::string& key);
    bool getBool(const std::string& key);

    Json::Value getValue(const std::string& key);

private:
    Json::Value jsonData;
};

#endif  // JSON_HPP
