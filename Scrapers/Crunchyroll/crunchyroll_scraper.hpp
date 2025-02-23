#ifndef CRUNCHYROLL_SCRAPER_HPP
#define CRUNCHYROLL_SCRAPER_HPP

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>

class CrunchyrollScraper {
public:
    CrunchyrollScraper(const std::string& url);
    ~CrunchyrollScraper();

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

#endif  // CRUNCHYROLL_SCRAPER_HPP
