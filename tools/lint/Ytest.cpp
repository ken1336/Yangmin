#include<iostream>
#include<cassert>
#include "libyang.h"
#include "commands.h"
#include "context.h"
#include "./min_extension/internal_module.hpp"
#include"./min_extension/Context.hpp"
volatile uint8_t verbose = 0;
int main(){

    
    min::context::Context ctx{};


    
    
    
    
    ctx.add_model("../ietf-netconf.yang");
    ctx.add_model("../ietf-interfaces.yang");
    ctx.print_list(stdout,LYD_XML);
    auto module = ctx.getModuleByIndex(7);
    std::cout<<module->getName()<<std::endl;
    module->printModuleData(0);
    
    //module->test();
    ctx.print_xml();
    //ly_modules_list list= ctx->models;

    //std::cout<<"---------------------------------------"<<list.parsed_submodules_count<<"----------------------"<<std::endl;
    //std::cout<<"---------------------------------------"<<list.parsing_sub_modules_count<<"----------------------"<<std::endl;
    for(auto i = 0; i< 7; i++){
        //std::cout<<ctx->models.list[i]->name<<std::endl;
        //std::cout<<list.list[i]->name<<std::endl;
        //ly_ctx_unset_searchdirs(ctx,i);
    }
    
    //min::internal::InternalModule iModule2{list.list[6]};
    
    //iModule2.printModuleData();
    //commands[1].func("ietf-netconf.yang");
    
    
    
   
    
}