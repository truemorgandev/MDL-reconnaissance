#include "src/core/module/module.hpp"
#include <array>
#include <cstdio>
#include <iostream>
#include <string>

class SubfinderModule : public Module {
public:
    std::string name() const override {
        return "subfinder";
    }

    void run(Context& ctx) override {
        const std::string& target = ctx.getTarget();

        if (target.empty()) {
            std::cerr << "[subfinder] target is empty\n";
            return;
        }

        // минимальная защита от совсем кривого ввода
        if (target.find(' ') != std::string::npos) {
            std::cerr << "[subfinder] invalid target\n";
            return;
        }

        std::string command = "subfinder -d " + target + " -silent 2>/dev/null";
        std::array<char, 4096> buffer{};

        FILE* pipe = popen(command.c_str(), "r");
        if (!pipe) {
            std::cerr << "[subfinder] failed to start subfinder\n";
            return;
        }

        int count = 0;

        while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe) != nullptr) {
            std::string line(buffer.data());

            while (!line.empty() && (line.back() == '\n' || line.back() == '\r')) {
                line.pop_back();
            }

            if (!line.empty()) {
                ctx.addSubdomain(line);
                ++count;
            }
        }

        int rc = pclose(pipe);
        if (rc != 0) {
            std::cerr << "[subfinder] subfinder exited with code " << rc << '\n';
        }

        std::cout << "[subfinder] added " << count << " subdomains\n";
    }
};

extern "C" Module* create() {
    return new SubfinderModule();
}