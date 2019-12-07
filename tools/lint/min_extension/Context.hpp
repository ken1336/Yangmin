#ifndef _MIN_EXECUTE_H
#define _MIN_EXECUTE_H


extern "C" {
#include<context.h>
#include <tree_schema.h>
#include <tree_data.h>
#include <xpath.h>

}


#include <memory>
#include<iostream>
namespace min
{

namespace context
{

class Context
{

private:
    std::shared_ptr<ly_ctx> context;
    int moduleIndex =6;

public:
    Context(const ly_ctx *ctx);
    Context();
    int model_add(const char* arg);
    int print_list(FILE *out, LYD_FORMAT outformat);
    std::shared_ptr<ly_ctx> getContext();

    ~Context();

};
} // namespace execute
} // namespace min

#endif