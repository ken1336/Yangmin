#include<iostream>
#include<cassert>
#include "libyang.h"
#include "commands.h"
#include "context.h"
#include "./min_extension/internal_module.hpp"

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


    commands[1].func("ietf-netconf.yang");
    
    ly_ctx_destroy(ctx, NULL);
}