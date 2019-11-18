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

#include "../src/tree_schema.h"
#include "../../models/ietf-yang-metadata@2016-08-05.h"
#include "../../models/yang@2017-02-20.h"
#include "../../models/ietf-inet-types@2013-07-15.h"
#include "../../models/ietf-yang-types@2013-07-15.h"
#include "../../models/ietf-datastores@2017-08-17.h"
#include "../../models/ietf-yang-library@2019-01-04.h"

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

constexpr int LY_INTERNAL_MODULE_COUNT = 6;
constexpr internal_modules_s internal_modules[LY_INTERNAL_MODULE_COUNT] = {
    {"ietf-yang-metadata", "2016-08-05", (const char *)ietf_yang_metadata_2016_08_05_yin, 0, LYS_IN_YIN},
    {"yang", "2017-02-20", (const char *)yang_2017_02_20_yin, 1, LYS_IN_YIN},
    {"ietf-inet-types", "2013-07-15", (const char *)ietf_inet_types_2013_07_15_yin, 0, LYS_IN_YIN},
    {"ietf-yang-types", "2013-07-15", (const char *)ietf_yang_types_2013_07_15_yin, 0, LYS_IN_YIN},
    /* ietf-datastores and ietf-yang-library must be right here at the end of the list! */
    {"ietf-datastores", "2017-08-17", (const char *)ietf_datastores_2017_08_17_yin, 0, LYS_IN_YIN},
    {"ietf-yang-library", IETF_YANG_LIB_REV, (const char *)ietf_yang_library_2019_01_04_yin, 1, LYS_IN_YIN}};

class InternalModule
{

private:    
    lys_module module;
public:
    InternalModule(lys_module& module);
    void printModuleData(lys_node& data, int dept = 0);
};

} // namespace internal

} // namespace min

#endif _MIN_INTERNAL_MODULE_H