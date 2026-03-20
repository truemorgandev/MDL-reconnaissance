#include <curl/curl.h>
#include <iostream>
#include "src/core/module/module.hpp"
#include "src/core/context/context.hpp"
#include "src/core/utilities/envparser.hpp"
#include <sstream>


const std::string tgtoken = getenv("TELEGRAM_BOT_TOKEN");
const std::string tg_id = getenv("TELEGRAM_ID");
void sendMessage(std::string message){
    CURL* curl = curl_easy_init();
    if(!curl) return;

    char* encoded = curl_easy_escape(curl, message.c_str(), message.size());

    std::string url = "https://api.telegram.org/bot" + tgtoken + "/sendMessage";
    std::string fields = "chat_id=" + tg_id + "&text=" + encoded;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields.c_str());

    curl_easy_perform(curl);

    curl_free(encoded);
    curl_easy_cleanup(curl);
}

class TelegramBotModule : public Module{
public:
    std::string name() const override {
        return "telegrambot";
    }
    
    void run(Context &context) override { 
        std::stringstream urls;
    
        for (size_t i = 0; i < context.getUrls().size(); ++i) {
            if (i != 0) {
                urls << " ";
            }
            urls << context.getSubdomains()[i];
        }
        
        std::stringstream subdomains;
    
        for (size_t i = 0; i < context.getSubdomains().size(); ++i) {
            if (i != 0) {
                subdomains << " ";
            }
            subdomains<< context.getSubdomains()[i];
        }
        sendMessage("Target: ");
        sendMessage(context.getTarget());
        sendMessage("URLS: ");
        sendMessage(urls.str());
        sendMessage("Subdomains: ");
        sendMessage(subdomains.str());
    }
    
};

extern "C" Module*  create() {
    return new TelegramBotModule();
}

