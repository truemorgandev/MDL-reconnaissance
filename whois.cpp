#include <iostream>
#include "src/core/module/module.hpp"
#include "src/core/context/context.hpp"
#include <cstdio>
class ExampleModule : public Module {
public:
    std::string name() const override {
        return "example";
    }

    void run(Context& context) override {
        std::cout << "[*] running whois module\n";

        std::cout << "[+] whois module finished\n";
    }
};


extern "C" Module* create() {
    return new ExampleModule();
}