#include "netflix_scraper.hpp"
#include <curl/curl.h>
#include <json/json.h>

NetflixScraper::NetflixScraper(const std::string& url) {
    this->url = url;
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
}

NetflixScraper::~NetflixScraper() {}

std::string NetflixScraper::getMovieTitle() {
    Json::Value jsonData;
    Json::Reader jsonReader;
    jsonReader.parse(html, jsonData);
    return jsonData["title"].asString();
}

std::string NetflixScraper::getMovieDescription() {
    Json::Value jsonData;
    Json::Reader jsonReader;
    jsonReader.parse(html, jsonData);
    return jsonData["description"].asString();
}

std::string NetflixScraper::getMovieImage() {
    Json::Value jsonData;
    Json::Reader jsonReader;
    jsonReader.parse(html, jsonData);
    return jsonData["image"].asString();
}

std::string NetflixScraper::getMovieVideo() {
    Json::Value jsonData;
    Json::Reader jsonReader;
    jsonReader.parse(html, jsonData);
    return jsonData["video"].asString();
}

static size_t writeMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    std::string& html = *reinterpret_cast<std::string*>(userp);
    html.assign(contents, size * nmemb);
    return size * nmemb;
}
