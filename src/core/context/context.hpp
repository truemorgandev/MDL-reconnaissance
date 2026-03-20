#pragma once
#include <string>
#include <vector>

class Context {
public:
    std::string target;
};

struct Whois {
    std::vector<std::string> nameservers;
    std::string registar;
    bool dnssec;
    std::string creationDate; 
};