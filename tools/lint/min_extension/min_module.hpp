#ifndef _MIN_MODULE_MODULE_H
#define _MIN_MODULE_MODULE_H

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

#include <iostream>
#include <string>
#include <memory>
#define IETF_YANG_LIB_REV "2019-01-04"

namespace min
{

namespace module
{
class MinModule
{

private:
    std::unique_ptr<lys_module> module;

    // virtual void printSubModule(const lys_module &subModule, int dept) =0;
    void setModule(lys_module *module);

public:
    MinModule(const lys_module *module);
    MinModule(){};
    // virtual void printModuleData(int dept = 0) =0;
    // virtual void printSubNode(lys_node *node, int dept) =0;
    // virtual void printSubModule(lys_module *subModule, int dept = 0) =0;
    // virtual void test() =0;
    inline std::string getName() { return module->name; };
    
    
};

} // namespace module
} // namespace min

#endif