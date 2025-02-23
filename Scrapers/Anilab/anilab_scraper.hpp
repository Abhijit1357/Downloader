#ifndef ANILAB_SCRAPER_HPP
#define ANILAB_SCRAPER_HPP

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>

class AnilabScraper {
public:
    AnilabScraper(const std::string& url);
    ~AnilabScraper();

    std::string getAnimeTitle();
    std::string getAnimeDescription();
    std::string getAnimeImage();
    std::string getAnimeVideo();

private:
    CURL* curl;
    std::string url;
    std::string html;
    Json::Value jsonData;
};

#endif  // ANILAB_SCRAPER_HPP
