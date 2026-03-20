#include "context/context.hpp"
#include "loader/loadedModule.hpp"
#include "utilities/envparser.hpp"
#include "loader/loader.hpp"
class Engine {
private:
    std::vector<LoadedModule> modules;
    Context& context;
public:   
    void run(){
        for (auto& m : modules) {
        std::cout << "Module: " << m.module->name() << std::endl;
        m.module->run(context);
        }
    };

    void load(){
        loadEnv(".env");  
        Loader loader;
        this->modules = loader.loadModules();
        
    }

    Engine(Context& contexts) : context(contexts) {
        context = contexts;
    }

};