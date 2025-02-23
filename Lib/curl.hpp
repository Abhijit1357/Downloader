#ifndef CURL_HPP
#define CURL_HPP

#include <curl/curl.h>
#include <string>

class Curl {
public:
    Curl();
    ~Curl();

    std::string get(const std::string& url);
    std::string post(const std::string& url, const std::string& data);

private:
    CURL* curl;
    CURLcode res;
};

#endif  // CURL_HPP
