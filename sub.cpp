#include <iostream>
#include "src/core/module/module.hpp"
#include "src/core/context/context.hpp"
#include <cstdio>
#include "src/core/utilities/execution.hpp"
class ExampleModule : public Module {
public:
    std::string name() const override {
        return "SUBFINDER_MODULE";
    }

    void run(Context& context) override {
        std::cout << "[*] running subfinder module\n";
        Execution executor;
        std::string cmd = "subfinder -d "+ context.target +" -silent";
        std::string output = executor.execute(cmd);
        context.subdomains_raw = output;     
        
        std::cout << "[+] subfinder module finished\n";
    }
};


extern "C" Module* create() {
    return new ExampleModule();
}