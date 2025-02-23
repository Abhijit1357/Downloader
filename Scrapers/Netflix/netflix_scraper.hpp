#ifndef NETFLIX_SCRAPER_HPP
#define NETFLIX_SCRAPER_HPP

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>

class NetflixScraper {
public:
    NetflixScraper(const std::string& url);
    ~NetflixScraper();

    std::string getMovieTitle();
    std::string getMovieDescription();
    std::string getMovieImage();
    std::string getMovieVideo();

private:
    CURL* curl;
    std::string url;
    std::string html;
    Json::Value jsonData;
};

#endif  // NETFLIX_SCRAPER_HPP
