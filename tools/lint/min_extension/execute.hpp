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

namespace execute
{

class command
{

private:
    std::unique_ptr<ly_ctx> context;

public:
    command(const ly_ctx *ctx);
    int model_add(const char* arg);

};
} // namespace execute
} // namespace min

#endif