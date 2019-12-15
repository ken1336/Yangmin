#ifndef _MIN_MODULE_H
#define _MIN_MODULE_H

#define _GNU_SOURCE
#include <pthread.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

#include "../../src/tree_schema.h"
#include "./module.hpp"

#include <iostream>
#include <string>
#include <memory>

namespace min
{

namespace module
{
class MinModule : public BaseModule
{
private:
    void printSubModule(const lys_module &subModule, int dept);

public:
    MinModule(const lys_module *module);
    MinModule(ly_ctx *ctx);

    // void printModuleData(int dept = 0);
    // void printSubNode(lys_node* node, int dept);
    // void printSubModule(lys_module* subModule, int dept = 0);
    // void printPathNode(lys_node* node, int dept);

    void test();

    ~MinModule();
};
} // namespace module
} // namespace min

#endif