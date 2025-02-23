#include "curl.hpp"

Curl::Curl() {
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    }
}

Curl::~Curl() {
    if(curl) {
        curl_easy_cleanup(curl);
    }
}

std::string Curl::get(const std::string& url) {
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            return "";
        }
        return response;
    }
    return "";
}

std::string Curl::post(const std::string& url, const std::string& data) {
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            return "";
        }
        return response;
    }
    return "";
}

static size_t writeMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    std::string& response = *reinterpret_cast<std::string*>(userp);
    response.assign(contents, size * nmemb);
    return size * nmemb;
}
