#include <iostream>
#include "loader/loader.hpp"
#include "core/context/context.hpp"
#include "core/engine.hpp"
int main() {
   

    Context mainCtx;
    Engine engine(mainCtx);
    engine.load();
    engine.run();

    return 0;
    

}