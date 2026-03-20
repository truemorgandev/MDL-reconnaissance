#pragma once
#include <string>
#include <vector>

class Context {
private:
    std::string target;
    std::vector<std::string> urls;
    std::vector<std::string> subdomains;
    int ratelimit;

public:
    const std::string& getTarget() const {
        return target;
    }

    const std::vector<std::string>& getUrls() const {
        return urls;
    }

    const std::vector<std::string>& getSubdomains() const {
        return subdomains;
    }

    void setTarget(const std::string& givenTarget) {
        target = givenTarget;
    }

    void addSubdomain(const std::string& subdomain) {
        subdomains.push_back(subdomain);
    }

    void addUrl(const std::string& url) {
        urls.push_back(url);
    }

    void setRateLimit(int ratelimit){
        this->ratelimit;
    }
};