#pragma once
#include <string>
#include "../context/context.hpp"

class Module {
public:
    virtual std::string name() const = 0;
    virtual void run(Context& ctx) = 0;
    virtual ~Module() = default;
};