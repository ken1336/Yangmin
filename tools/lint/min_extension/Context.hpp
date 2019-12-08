#ifndef _MIN_EXECUTE_H
#define _MIN_EXECUTE_H


extern "C" {
#include<context.h>
#include <tree_schema.h>
#include <tree_data.h>
#include <xpath.h>
#include "libyang.h"
#include"parser.h"
}


#include <memory>
#include<iostream>
#include <hash_map>
#include<string>

#include"internal_module.hpp"
namespace min
{

namespace context
{

class Context
{

private:
    ly_ctx* ctx;
    int moduleIndex =6;
    int addedModuleCount = 0;
    __gnu_cxx::hash_map<std::string,std::shared_ptr<const lys_module*>> module_map; //not yet used

public:
    Context(const ly_ctx *ctx);
    Context();
    ly_ctx* getContext();

    std::shared_ptr<min::internal::InternalModule> getModuleByIndex(int index); 
    int add_model(const char* arg);
    int print_list(FILE *out, LYD_FORMAT outformat);
    void print_xml();

    ~Context();


    const lys_module* _add_module(const char* arg); //not yet used
    void add_module(const char* arg); //not yet used

};
} // namespace execute
} // namespace min

#endif