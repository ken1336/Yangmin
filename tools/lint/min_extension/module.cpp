#include <iostream>
#include <memory>
#include "internal_module.hpp"


#include "../../models/ietf-yang-metadata@2016-08-05.h"
#include "../../models/yang@2017-02-20.h"
#include "../../models/ietf-inet-types@2013-07-15.h"
#include "../../models/ietf-yang-types@2013-07-15.h"
#include "../../models/ietf-datastores@2017-08-17.h"
#include "../../models/ietf-yang-library@2019-01-04.h"
namespace min
{
namespace internal
{


constexpr internal_modules_s internal_modules[] = {
    {"ietf-yang-metadata", "2016-08-05", (const char *)ietf_yang_metadata_2016_08_05_yin, 0, LYS_IN_YIN},
    {"yang", "2017-02-20", (const char *)yang_2017_02_20_yin, 1, LYS_IN_YIN},
    {"ietf-inet-types", "2013-07-15", (const char *)ietf_inet_types_2013_07_15_yin, 0, LYS_IN_YIN},
    {"ietf-yang-types", "2013-07-15", (const char *)ietf_yang_types_2013_07_15_yin, 0, LYS_IN_YIN},
    /* ietf-datastores and ietf-yang-library must be right here at the end of the list! */
    {"ietf-datastores", "2017-08-17", (const char *)ietf_datastores_2017_08_17_yin, 0, LYS_IN_YIN},
    {"ietf-yang-library", IETF_YANG_LIB_REV, (const char *)ietf_yang_library_2019_01_04_yin, 1, LYS_IN_YIN}};


InternalModule::InternalModule(const lys_module *module)
{
    this->module = std::make_unique<lys_module>(*module);
    
}
InternalModule::InternalModule(ly_ctx* ctx){
    // for(auto i = 0; i<4; i++){
    //     lys_parse_mem(ctx, min::internal::internal_modules[i].data, min::internal::internal_modules[i].format);
    // }
    auto in = lys_parse_mem(ctx, min::internal::internal_modules[5].data, min::internal::internal_modules[5].format);
    this->module = std::make_unique<lys_module>(*in);
    
}
void InternalModule::test(){
    std::cout<<"test"<<std::endl;
}
void InternalModule::printModuleData(int dept)
{
   
    auto iter = this->module->data;
    int num = 0;
    std::cout<<"----------iter start----------"<<std::endl;
    printSubNode(iter,0);
    // while(iter){
        
    //     for (auto i = 0; i < dept; i++){
    //      std::cout << "  ..  ";
    //     }
        
    //     std::cout<<iter->name<<std::endl;
    //     if(iter->name){
    //         printSubNode(iter->child,dept+1);
    //     }
        
        
    //     if(iter->next){
    //         iter = iter->next;
    //     }else{
    //         std::cout<<"----------iter end----------"<<std::endl;
    //         return;
    //     }
    // }

    std::cout<<"----------iter end----------"<<std::endl;
    return;
    

}

void InternalModule::printSubModule(lys_module* subModule, int dept)
{
}

void InternalModule::printSubNode(lys_node* node, int dept)
{
    
    auto iter = node;

    while(iter){
        for (auto i = 0; i < dept; i++){
         std::cout << "  ..  ";
        }
            std::cout<<"flags: "<<iter->flags;
            if(iter->flags >= 0 && iter->flags <= 64 )
                std::cout<<"  "<<iter->nodetype<<" : "<<iter->name<<std::endl;
            else{
                std::cout<<"  skip--"<<std::endl;
                return;
            }
                
           // std::cout<<iter->dsc<<std::endl;
        if(iter->child){
            printSubNode(iter->child,dept+1);
        }
        
        
        if(iter->next){
            iter = iter->next;
        }else{
            return;
        }
    }

    return;

   
}
} // namespace internal
} // namespace min