#include <iostream>
#include <memory>
#include "min_module.hpp"

namespace min
{

namespace module
{
MinModule::MinModule(const lys_module *module)
{
    this->module = std::make_unique<lys_module>(*module);
}



void MinModule::setModule(lys_module *module)
{
    this->module = std::make_unique<lys_module>(*module);
}

} // namespace module
} // namespace min