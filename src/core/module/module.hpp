#include <string>
#include <vector>
class Module {

public:
    virtual std::string name() const = 0; 
    virtual void run() = 0;
    virtual ~Module() = default;
};