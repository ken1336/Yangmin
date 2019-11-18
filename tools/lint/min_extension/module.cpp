#include <iostream>
#include "./internal_module.hpp";

namespace min
{
namespace internal
{
InternalModule::InternalModule(lys_module &module)
{
    this->module = module;
}

void InternalModule::printModuleData(lys_node &data, int dept = 0)
{

    auto node = data;

    for (auto i = 0; i < dept; i++){
        std::cout << "    ";
    }    
    std::cout<<"data: "<<node.name<<std::endl;
    while(node.next){
        node = node.next;
        for (auto i = 0; i < dept; i++){
        std::cout << "    ";
    }    
    std::cout<<"data: "<<node.name<<std::endl;
    }
}
} // namespace internal
} // namespace min