#include<iostream>
#include<cassert>
#include "libyang.h"
#include "commands.h"
#include "context.h"
#include "min_extension/internal_module.hpp"

int main(){

    
    auto ctx = ly_ctx_new(NULL, 0);
    if (!ctx) {
        fprintf(stderr, "Failed to create context.\n");
        return 1;
    }
     //commands[i].func((const char *)"cmd_add");

    
    

    std::cout<<"internal modules count:"<<ctx->internal_module_count<<std::endl;
   


    for (auto i = 0; i < ctx->internal_module_count; i++) {
        auto module = lys_parse_mem(ctx, min::internal::internal_modules[i].data, min::internal::internal_modules[i].format);
        assert(module);

        //module->implemented = internal_modules[i].implemented;
        std::cout<<"internal module name: "<<module->name<<std::endl;
        
    }
    
    commands[0].func("ietf-yang-library");
    
    ly_ctx_destroy(ctx, NULL);
}