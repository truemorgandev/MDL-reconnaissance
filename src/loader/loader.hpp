#pragma once

#include <vector>
#include "loadedModule.hpp"

class Loader {
public:
    std::vector<LoadedModule> loadModules();
};