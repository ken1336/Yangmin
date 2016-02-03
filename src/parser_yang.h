/**
 * @file parser_yang.h
 * @author Pavol Vican
 * @brief Parsers for libyang
 *
 * Copyright (c) 2015 CESNET, z.s.p.o.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name of the Company nor the names of its contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 */

#ifndef LY_PARSER_YANG_H_
#define LY_PARSER_YANG_H_

#include <stdlib.h>
#include <string.h>

#include "tree_schema.h"
#include "resolve.h"
#include "common.h"
#include "context.h"

#define LY_ARRAY_SIZE 16

int yang_read_common(struct lys_module *module,char *value, int type, int line);

int yang_read_prefix(struct lys_module *module, void *save, char *value,int type,int line);

/**
 * @brief Get free member of array
 *
 * @param[in/out] ptr Pointer to the array.
 * @param[in/out] act_size Pointer to the current size of array.
 * @param[in] type Type of array.
 * @param[in] sizeof_struct
 * @return first free member of array, NULL on error.
 */
void *yang_elem_of_array(void **ptr, uint8_t *act_size, int type, int sizeof_struct);

int yang_fill_import(struct lys_module *module, struct lys_import *imp, char *value, int line);

int yang_read_description(struct lys_module *module, void *node, char *value, int type, int line);

int yang_read_reference(struct lys_module *module, void *node, char *value, int type, int line);


#endif /* LY_PARSER_YANG_H_ */
