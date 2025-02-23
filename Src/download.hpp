#ifndef DOWNLOAD_HPP
#define DOWNLOAD_HPP

#include <string>
#include <curl/curl.h>

class Download {
public:
    Download(const std::string& url, const std::string& filePath);
    ~Download();

    bool downloadFile();

private:
    std::string url;
    std::string filePath;
    CURL* curl;
    FILE* file;
};

#endif  // DOWNLOAD_HPP
