#include "execute.hpp"
#include <string>
namespace min
{

namespace execute
{

command::command(ly_ctx *ctx)
{
    this->context = std::make_unique<ly_ctx>(*ctx);
}
int command::model_add(const char* arg){
{
    int path_len, ret = 1, index = 0;
    char *path, *dir, *s, *arg_ptr;
    const char * const *searchpaths;
    const struct lys_module *model;
    LYS_INFORMAT format = LYS_IN_UNKNOWN;

    if (strlen(arg) < 5) {
        
        return 1;
    }

    arg_ptr = strdup(arg + 3 /* ignore "add" */);

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
        format = get_schema_format(path);
        if (format == LYS_IN_UNKNOWN) {
            free(path);
            goto cleanup;
        }

        dir = strdup(path);
        ly_ctx_set_searchdir(ctx, dirname(dir));
        model = lys_parse_path(ctx, path, format);
        ly_ctx_unset_searchdirs(ctx, index);
        free(path);
        free(dir);

        if (!model) {
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
        cmd_add_help();
        goto cleanup;
    }
    ret = 0;

cleanup:
    free(s);
    ly_ctx_unset_allimplemented(ctx);

    return ret;
}
}

} // namespace execute
} // namespace min
