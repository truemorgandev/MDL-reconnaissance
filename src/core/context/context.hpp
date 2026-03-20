#pragma once
#include <string>
#include <vector>

class Context {
public:
    std::string target;
    std::string subdomains_raw;
    int ratelimit;
};

