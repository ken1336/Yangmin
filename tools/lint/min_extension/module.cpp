#include <iostream>
#include <memory>
#include "module.hpp"

namespace min
{

namespace module
{
BaseModule::BaseModule(const lys_module *module)
{
    this->module = std::make_shared<lys_module>(*module);
}

BaseModule::BaseModule(ly_ctx* ctx)
{
    this->ctx = std::make_shared<ly_ctx>(*ctx);
}

void BaseModule::test()
{
    
    lys_print_file(stdout,this->getModule().get(),LYS_OUT_TREE,lys_data_path(this->getModule().get()->data),this->getModule().get()->data->ext_size,4);
    //lys_print_file(stdout,this->module.get(),LYS_OUT_TREE,lys_data_path(this->module.get()->data),this->module.get()->data->ext_size,4);
    //std::cout<<lys_data_path(this->module.get()->data->child)<<std::endl;
}


void BaseModule::printIndent(int dept)
{
    for (auto i = 0; i < dept; i++)
        {
            std::cout << "  ..  ";
        }
}

void BaseModule::printModuleData(int dept)
{

    auto iter = this->getModule()->data;
    int num = 0;
    std::cout << "----------iter start----------" << std::endl;
    //printSubNode(iter, 0);
    printPathNode(iter,0);
    std::cout << "----------iter end----------" << std::endl;
    return;
}

void BaseModule::printSubModule(lys_module *subModule, int dept)
{
}

void BaseModule::printPathNode(lys_node *node, int dept)
{
    auto iter = node;

    while(iter)
    {
        printIndent(dept);
        std::cout<<lys_data_path(iter)<<std::endl;
        if (iter->child)
        {
            
            printPathNode(iter->child, dept + 1);
        }

        if (iter->next)
        {
            iter = iter->next;
        }
        else
        {
            return;
        }
    }
}
void BaseModule::printSubNode(lys_node *node, int dept)
{

    auto iter = node;

    while (iter)
    {
        printIndent(dept);
        //std::cout<<"nodetype: "<<iter->nodetype
        //if(iter->flags >= 0 && iter->flags <= 64 )
        if (iter->nodetype != 33 && iter->nodetype != LYS_UNKNOWN && iter->nodetype != LYS_CHOICE && iter->nodetype < 0x10000)
        {
            std::cout << "  " << iter->nodetype << " : " << iter->name << std::endl;
            // for (auto i = 0; i < dept; i++)
            // {
            //     std::cout << "  ..  ";
            // }
            // std::cout<<iter->dsc<<std::endl;
        }

        else
        {
            std::cout << "  skip--" << std::endl;
            return;
        }

        // std::cout<<iter->dsc<<std::endl;
        if (iter->child)
        {
            printSubNode(iter->child, dept + 1);
        }

        if (iter->next)
        {
            iter = iter->next;
        }
        else
        {
            return;
        }
    }

    return;
}

void BaseModule::setModule(lys_module *module)
{
    this->module = std::make_shared<lys_module>(*module);
}

std::shared_ptr<lys_module> BaseModule::getModule()
{
    return this->module;
}
} // namespace module
} // namespace min