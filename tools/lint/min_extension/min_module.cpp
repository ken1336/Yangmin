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
void MinModule::printIndent(int dept)
{
    for (auto i = 0; i < dept; i++)
        {
            std::cout << "  ..  ";
        }
}

} // namespace module
} // namespace min