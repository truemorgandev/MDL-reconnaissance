#include <iostream>
#include "loader/loader.hpp"
#include "core/context/context.hpp"

int main() {
    Loader loader;
    auto modules = loader.loadModules();

    Context ctx;

    std::string input;
    std::cout << "Enter target domain: ";
    std::cin >> input;
    ctx.setTarget(input);

    for (auto& m : modules) {
        std::cout << "Module: " << m.module->name() << std::endl;
        m.module->run(ctx);
    }

    std::cout << "\nCollected subdomains:\n";
    for (const auto& sub : ctx.getSubdomains()) {
        std::cout << sub << '\n';
    }

    return 0;
}