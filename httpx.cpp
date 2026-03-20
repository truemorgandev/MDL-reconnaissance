#include <iostream>
#include "src/core/module/module.hpp"
#include "src/core/context/context.hpp"
#include <cstdio>
#include "src/core/utilities/execution.hpp"
#include <fstream>
#include <string>
class ExampleModule : public Module {
public:
    std::string name() const override {
        return "HTTPX_MODULE";
    }

    void run(Context& context) override {
        std::cout << "[*] running httpx module\n";

        Execution executor;
        std::string cmd = "httpx -t 1 -rl "+ std::to_string(context.ratelimit) + " -l subs.txt";
        std::cout << cmd<< "\n";
        std::string output = executor.execute(cmd);
        std::cout << output<<std::endl;
        std::cout << "[+] httpx module finished\n";
    }
};


extern "C" Module* create() {
    return new ExampleModule();
}