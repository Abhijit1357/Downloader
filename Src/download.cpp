#include "download.hpp"
#include <curl/curl.h>
#include <fstream>

Download::Download(const std::string& url, const std::string& filePath) {
    this->url = url;
    this->filePath = filePath;
    curl = curl_easy_init();
    file = fopen(filePath.c_str(), "wb");
}

Download::~Download() {
    if(curl) {
        curl_easy_cleanup(curl);
    }
    if(file) {
        fclose(file);
    }
}

bool Download::downloadFile() {
    if(curl && file) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        CURLcode res = curl_easy_perform(curl);
        if(res == CURLE_OK) {
            return true;
        }
    }
    return false;
}

size_t writeData(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}
