#pragma once

#include "../core/module/module.hpp"

struct LoadedModule {
    Module* module;
    void* handle;
};