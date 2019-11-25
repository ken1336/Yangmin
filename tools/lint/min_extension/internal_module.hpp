#ifndef _MIN_INTERNAL_MODULE_H
#define _MIN_INTERNAL_MODULE_H

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

#include<iostream>
#include<string>
#include<memory>
#define IETF_YANG_LIB_REV "2019-01-04"

namespace min
{

namespace internal
{

typedef struct internal_modules_s
{
    const char *name;
    const char *revision;
    const char *data;
    uint8_t implemented;
    LYS_INFORMAT format;
} internal_modules_s;



class InternalModule
{

private:
    
    std::unique_ptr<lys_module> module;

    void printSubModule(const lys_module& subModule,int dept);
public:
    InternalModule(const lys_module* module);
    InternalModule(ly_ctx* ctx);
    void printModuleData(int dept = 0);
    inline std::string getName(){return module->name;};
};

} // namespace internal

} // namespace min

#endif