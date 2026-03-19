#include "loader.hpp"
#include <filesystem>
#include "loadedModule.hpp"
#include <iostream>
#include <dlfcn.h>
namespace fs = std::filesystem;

std::vector<LoadedModule> Loader::loadModules(){
    std::vector<LoadedModule> loadedModules;
    std::string dir = "/home/truemorgan/workspace/tools/crypted-rn/modules";
    std::vector<std::string> modules;
    for (const auto& entry : fs::directory_iterator(dir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".so") {
            modules.push_back(entry.path().string());
        }
    }
    
    for(size_t i = 0; i < modules.size(); i++ ){
        dlerror();
        void* handle = dlopen(modules[i].c_str(), RTLD_NOW);
        if (!handle) {
            std::cerr << "Cannot open library: " << dlerror() << '\n';
            continue;
        }
    
        auto createFunc = (Module*(*)()) dlsym(handle, "create");
        if (!createFunc) {
            std::cerr << modules[i] << " does not contain create() function: " << dlerror() << '\n';
            dlclose(handle);
            continue;
        };
        Module* module = createFunc();
        LoadedModule loadedModule = {module, handle};
        loadedModules.push_back(loadedModule);
        std::cout << "Loaded module: " << module->name() << '\n';
    }
    return loadedModules;
}