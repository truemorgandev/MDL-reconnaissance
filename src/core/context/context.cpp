#include "context.hpp"

std::string Context::getTarget(){
    return target;
}

std::vector<std::string> Context::getSubdomains(){
    return subdomains;
}

std::vector<std::string> Context::getUrls(){
    return urls;
}

void Context::setTarget(std::string givenTarget){
    target = givenTarget;
}

void Context::addSubdomain(std::string subdomain){
    subdomains.push_back(subdomain);
}

void Context::addUrl(std::string url){
    subdomains.push_back(url);
}

