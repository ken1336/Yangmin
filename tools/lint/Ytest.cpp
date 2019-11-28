#include<iostream>
#include<cassert>
#include "libyang.h"
#include "commands.h"
#include "context.h"
#include "./min_extension/internal_module.hpp"
#include"./min_extension/execute.hpp"

int main(){

    
    auto ctx = ly_ctx_new(NULL, 0);
    if (!ctx) {
        fprintf(stderr, "Failed to create context.\n");
        return 1;
    }
     //commands[i].func((const char *)"cmd_add");

    
    

    std::cout<<"internal modules count:"<<ctx->internal_module_count<<std::endl;
    min::internal::InternalModule iModule{ctx};
    
    std::cout<<iModule.getName()<<std::endl;
    iModule.printModuleData();

    
    min::execute::command cmd{ctx};
    cmd.model_add("ietf-netconf.yang");
    ly_modules_list list= ctx->models;
    std::cout<<"---------------------------------------list----------------------"<<std::endl;
    std::cout<<"---------------------------------------"<<list.parsed_submodules_count<<"----------------------"<<std::endl;
    std::cout<<"---------------------------------------"<<list.parsing_sub_modules_count<<"----------------------"<<std::endl;
    for(auto i = 0; i< 7; i++){
        std::cout<<list.list[i]->name<<std::endl;
    }
    
    min::internal::InternalModule iModule2{list.list[6]};
    
    iModule2.printModuleData();
    //commands[1].func("ietf-netconf.yang");
    
    std::cout<<"---------------------------------------clean----------------------"<<std::endl;
    std::cout<<ctx->dict.hash_tab->cb_data<<std::endl;
    lydict_remove(ctx,(const char*)ctx->dict.hash_tab->cb_data);
    ly_ctx_destroy(ctx, NULL);
}