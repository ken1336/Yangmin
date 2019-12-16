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
#include<context.h>
#include <iostream>
#include <string>
#include <memory>
#include<cassert>
#define IETF_YANG_LIB_REV "2019-01-04"

namespace min
{

namespace module
{
class BaseModule
{

private:
    std::shared_ptr<lys_module> module;
    std::shared_ptr<ly_ctx> ctx; 
    // virtual void printSubModule(const lys_module &subModule, int dept) =0;
    void setModule(lys_module *module);
    

protected:
    void printIndent(int dept);
public:
    BaseModule(const lys_module *module);
    BaseModule(ly_ctx* ctx);
    
    void printModuleData(int dept = 0);
    void printSubNode(lys_node* node, int dept);
    void printSubModule(lys_module* subModule, int dept = 0);
    void printPathNode(lys_node* node, int dept);
    
    void test();

    //Getter
    std::shared_ptr<lys_module> getModule();
    std::shared_ptr<ly_ctx> getContext();
    inline std::string getName() { return module->name; };
    
    
};

} // namespace module
} // namespace min

#endif