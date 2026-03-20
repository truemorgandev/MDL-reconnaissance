#include <iostream>
#include "src/core/module/module.hpp"
#include "src/core/context/context.hpp"
#include <cstdio>
#include "src/core/utilities/execution.hpp"
class ExampleModule : public Module {
public:
    std::string name() const override {
        return "START_MODULE";
    }

    void run(Context& context) override {
        std::cout << "[*] Welcome to mdl-recon framework!\n";
        std::cout << "[*] Enter target domain\n";
        std::cin>> context.target;
        std::cout << "[*] Enter rate limit (rps)\n";
        std::cin>>context.ratelimit;
    }
};


extern "C" Module* create() {
    return new ExampleModule();
}