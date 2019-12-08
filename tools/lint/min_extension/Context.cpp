#include "Context.hpp"
#include <string>
#include<cassert>


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <libgen.h>


static LYS_INFORMAT 
get_schema_format(const char *path)
{
     char *ptr;

    if ((ptr = strrchr((char*)path, '.')) != NULL) {
        ++ptr;
        if (!strcmp(ptr, "yin")) {
            return LYS_IN_YIN;
        } else if (!strcmp(ptr, "yang")) {
            return LYS_IN_YANG;
        } else {
            fprintf(stderr, "Input file in an unknown format \"%s\".\n", ptr);
            return LYS_IN_UNKNOWN;
        }
    } else {
        fprintf(stdout, "Input file \"%s\" without extension - unknown format.\n", path);
        return LYS_IN_UNKNOWN;
    }
}



namespace min
{

namespace context
{

Context::Context(const ly_ctx *ctx)
{
   
    this->ctx = (ly_ctx*)ctx;
    
    
}
Context::Context()
{
    ctx = ly_ctx_new(NULL, 0);
    assert(ctx);

    
    for(auto i = 0; i< ctx->internal_module_count; i++){
       std::cout<<"-----------------------------------"<<ctx->models.list[i]->name<<" created"<<std::endl;
    }
    
}
Context::~Context(){
    
    for(auto i = moduleIndex; i< moduleIndex+addedModuleCount; i++){
        
        ly_ctx_remove_module(ctx->models.list[i],NULL);
    }
    //
    
    ly_ctx_destroy(ctx, NULL);
}

ly_ctx* Context::getContext()
{
    return ctx;
}
std::shared_ptr<min::internal::InternalModule> Context::getModuleByIndex(int index)
{
    return std::make_shared<min::internal::InternalModule>(this->ctx->models.list[index]);
  
}

void Context::print_xml(){

    size_t length;
    char *addr;
    LYS_INFORMAT format = LYS_IN_YANG;
    
    //lyp_mmap(ctx, 0, format == LYS_IN_YANG ? 1 : 0, &length, (void **)&addr);
    //std::cout<<getModuleByIndex(6)-><<std::endl;
    //lyxml_parse_mem(ctx, data, LYXML_PARSE_NOMIXEDCONTENT);
}


//not yet used
void Context::add_module(const char* arg){

    if(auto in = _add_module(arg)){
        auto in_ptr = std::make_shared<const lys_module*>(in);
        //module_map.insert()
    }
        //module_map.insert(arg,);
}


int Context::add_model(const char* arg){
{
    
    
    int path_len, ret = 1, index = 0;
    char *path, *dir, *s, *arg_ptr;
    const char * const *searchpaths;
    const struct lys_module *model;
    LYS_INFORMAT format = LYS_IN_UNKNOWN;

    if (strlen(arg) < 5) {
        
        return 1;
    }

    arg_ptr = strdup(arg /* ignore "add" */);

    for (s = strstr(arg_ptr, "-i"); s ; s = strstr(s + 2, "-i")) {
        if (s[2] == '\0' || s[2] == ' ') {
            ly_ctx_set_allimplemented(ctx);
            s[0] = s[1] = ' ';
        }
    }
    s = arg_ptr;

    while (arg_ptr[0] == ' ') {
        ++arg_ptr;
    }
    if (strchr(arg_ptr, ' ')) {
        path_len = strchr(arg_ptr, ' ') - arg_ptr;
    } else {
        path_len = strlen(arg_ptr);
    }
    path = strndup(arg_ptr, path_len);

    searchpaths = ly_ctx_get_searchdirs(ctx);
    if (searchpaths) {
        for (index = 0; searchpaths[index]; index++);
    }
    
    while (path) {
        std::cout<<"input path: "<<path<<std::endl;
        format = get_schema_format(path);
        if (format == LYS_IN_UNKNOWN) {
            free(path);
            goto cleanup;
        }

        dir = strdup(path);
        ly_ctx_set_searchdir(ctx, dirname(dir));
        model = lys_parse_path(ctx, path, format);
        ly_ctx_unset_searchdirs(ctx, index);
        std::cout<<"-----------------------------------------------------"<<path<<std::endl;
        //print_list(stdout,context.get(),LYD_XML);
        free(path);
        free(dir);

        if (!model) {
            std::cout<<"--------------------------model not found---------------------------"<<path<<std::endl;
            /* libyang printed the error messages */
            goto cleanup;
        }

        /* next model */
        arg_ptr += path_len;
        while (arg_ptr[0] == ' ') {
            ++arg_ptr;
        }
        if (strchr(arg_ptr, ' ')) {
            path_len = strchr(arg_ptr, ' ') - arg_ptr;
        } else {
            path_len = strlen(arg_ptr);
        }

        if (path_len) {
            path = strndup(arg_ptr, path_len);
        } else {
            path = NULL;
        }
    }
    if (format == LYS_IN_UNKNOWN) {
        /* no schema on input */
        //cmd_add_help();
        goto cleanup;
    }

    addedModuleCount++;
    ret = 0;
    
cleanup:
    free(s);
    ly_ctx_unset_allimplemented(ctx);

    return ret;
    
}
}

int Context::print_list(FILE *out, LYD_FORMAT outformat)
{
    struct lyd_node *ylib;
    uint32_t idx = 0, has_modules = 0;
    uint8_t u;
    const struct lys_module *mod;


    if (outformat != LYD_UNKNOWN) {
        ylib = ly_ctx_info(ctx);
        if (!ylib) {
            fprintf(stderr, "Getting context info (ietf-yang-library data) failed.\n");
            return 1;
        }

        lyd_print_file(out, ylib, outformat, LYP_WITHSIBLINGS | LYP_FORMAT);
        lyd_free_withsiblings(ylib);
        return 0;
    }

    /* iterate schemas in context and provide just the basic info */
    fprintf(out, "List of the loaded models:\n");
    while ((mod = ly_ctx_get_module_iter(ctx, &idx))) {
        has_modules++;

        /* conformance print */
        if (mod->implemented) {
            fprintf(out, "\tI");
        } else {
            fprintf(out, "\ti");
        }

        /* module print */
        fprintf(out, " %s", mod->name);
        if (mod->rev_size) {
            fprintf(out, "@%s", mod->rev[0].date);
        }

        /* submodules print */
        if (mod->inc_size) {
            fprintf(out, " (");
            for (u = 0; u < mod->inc_size; u++) {
                fprintf(out, "%s%s", !u ? "" : ",", mod->inc[u].submodule->name);
                if (mod->inc[u].submodule->rev_size) {
                    fprintf(out, "@%s", mod->inc[u].submodule->rev[0].date);
                }
            }
            fprintf(out, ")");
        }

        /* finish the line */
        fprintf(out, "\n");
    }

    if (!has_modules) {
        fprintf(out, "\t(none)\n");
    }

    return 0;
}
const lys_module* Context::_add_module(const char* arg){
    int path_len, ret = 1, index = 0;
    char *path, *dir, *s, *arg_ptr;
    const char * const *searchpaths;
    const struct lys_module *model;
    LYS_INFORMAT format = LYS_IN_UNKNOWN;

    if (strlen(arg) < 5) {
        
        return NULL;
    }

    arg_ptr = strdup(arg /* ignore "add" */);

    for (s = strstr(arg_ptr, "-i"); s ; s = strstr(s + 2, "-i")) {
        if (s[2] == '\0' || s[2] == ' ') {
            ly_ctx_set_allimplemented(ctx);
            s[0] = s[1] = ' ';
        }
    }
    s = arg_ptr;

    while (arg_ptr[0] == ' ') {
        ++arg_ptr;
    }
    if (strchr(arg_ptr, ' ')) {
        path_len = strchr(arg_ptr, ' ') - arg_ptr;
    } else {
        path_len = strlen(arg_ptr);
    }
    path = strndup(arg_ptr, path_len);

    searchpaths = ly_ctx_get_searchdirs(ctx);
    if (searchpaths) {
        for (index = 0; searchpaths[index]; index++);
    }
    
    while (path) {
        std::cout<<"input path: "<<path<<std::endl;
        format = get_schema_format(path);
        if (format == LYS_IN_UNKNOWN) {
            free(path);
            goto cleanup;
        }

        dir = strdup(path);
        ly_ctx_set_searchdir(ctx, dirname(dir));
        model = lys_parse_path(ctx, path, format);
        ly_ctx_unset_searchdirs(ctx, index);
        std::cout<<"-----------------------------------------------------"<<path<<std::endl;
        //print_list(stdout,context.get(),LYD_XML);
        free(path);
        free(dir);

        if (!model) {
            std::cout<<"--------------------------model not found---------------------------"<<path<<std::endl;
            /* libyang printed the error messages */
            goto cleanup;
        }

        /* next model */
        arg_ptr += path_len;
        while (arg_ptr[0] == ' ') {
            ++arg_ptr;
        }
        if (strchr(arg_ptr, ' ')) {
            path_len = strchr(arg_ptr, ' ') - arg_ptr;
        } else {
            path_len = strlen(arg_ptr);
        }

        if (path_len) {
            path = strndup(arg_ptr, path_len);
        } else {
            path = NULL;
        }
    }
    if (format == LYS_IN_UNKNOWN) {
        /* no schema on input */
        //cmd_add_help();
        goto cleanup;
    }

    addedModuleCount++;
    ret = 0;
    
cleanup:
    free(s);
    ly_ctx_unset_allimplemented(ctx);

    return model;
}
} // namespace execute
} // namespace min
