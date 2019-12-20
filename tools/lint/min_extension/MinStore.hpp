#include <context.h>
#include <iostream>
#include <string>
#include <memory>
#include <cassert>

namespace min
{

namespace context
{
class Store
{
public:
    virtual void InitRoot() = 0;
};

} // namespace context
} // namespace min