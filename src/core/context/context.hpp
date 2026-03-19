#include <string>
#include <vector>

class Context {
private:
    std::string target;
    std::vector<std::string> urls;
    std::vector<std::string> subdomains;

public:
    std::string getTarget();
    std::vector<std::string> getUrls();
    std::vector<std::string> getSubdomains();
    void setTarget(std::string givenTarget);
    void addSubdomain(std::string subdomain);
    void addUrl(std::string url);
};