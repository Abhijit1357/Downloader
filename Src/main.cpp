#include "curl.hpp"
#include "json.hpp"
#include "config.hpp"
#include <iostream>
#include <string>

int main() {
    // Config file load karein
    Config config("config.json");

    // Curl object banayein
    Curl curl;

    // URL set karein
    std::string url = config.getString("anilab.url");

    // Curl request bhejein
    std::string response = curl.get(url);

    // JSON parse karein
    Json json;
    json.parse(response);

    // JSON data extract karein
    std::string title = json.getString("title");
    std::string description = json.getString("description");

    // Data print karein
    std::cout << "Title: " << title << std::endl;
    std::cout << "Description: " << description << std::endl;

    return 0;
}
