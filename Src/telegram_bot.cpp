#include "telegram_bot.hpp"
#include <curl/curl.h>
#include <string>

TelegramBot::TelegramBot(const std::string& token, const std::string& chatId) {
    this->token = token;
    this->chatId = chatId;
    curl = curl_easy_init();
}

TelegramBot::~TelegramBot() {
    if(curl) {
        curl_easy_cleanup(curl);
    }
}

void TelegramBot::sendMessage(const std::string& message) {
    if(curl) {
        std::string url = "https://api.telegram.org/bot" + token + "/sendMessage";
        std::string postData = "chat_id=" + chatId + "&text=" + message;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());
        curl_easy_perform(curl);
    }
}
