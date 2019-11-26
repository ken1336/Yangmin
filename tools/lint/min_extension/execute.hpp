#ifndef _MIN_EXECUTE_H
#define _MIN_EXECUTE_H

#include "../../src/tree_schema.h"
#include "../../src/tree_data.h"
#include "../../src/xpath.h"

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
    command(ly_ctx *ctx);
    int model_add(const char* arg);

};
} // namespace execute
} // namespace min

#endif