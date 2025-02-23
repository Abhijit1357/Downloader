#ifndef TELEGRAM_BOT_HPP
#define TELEGRAM_BOT_HPP

#include <string>
#include <curl/curl.h>

class TelegramBot {
public:
    TelegramBot(const std::string& token, const std::string& chatId);
    ~TelegramBot();

    void sendMessage(const std::string& message);

private:
    std::string token;
    std::string chatId;
    CURL* curl;
};

#endif  // TELEGRAM_BOT_HPP
