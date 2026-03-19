#include <iostream>
#include <vector>
#include "loader/loader.hpp"

int main() {
    Loader loader;
    auto modules = loader.loadModules();

    for (auto& m : modules) {
        std::cout << "Module: " << m.module->name() << std::endl;
        m.module->run();
    }

    return 0;
}