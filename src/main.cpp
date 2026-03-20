#include <iostream>
#include "loader/loader.hpp"
#include "core/context/context.hpp"
#include "core/engine.hpp"
int main() {
   

    Context mainCtx;
    Engine engine(mainCtx);
    engine.load();
    mainCtx.addUrl("example.com");
    mainCtx.setTarget("truemorgantest.hack");
    mainCtx.addSubdomain("admin-very-secret-env.truemorgan.xyz");
    engine.run();

    

    return 0;
}