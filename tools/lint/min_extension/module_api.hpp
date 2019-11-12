#ifndef _MIN_MODULE_API_H
#define _MIN_MODULE_API_H


#include<iostream>
#include "../commands.h"
namespace min
{
    namespace api
    {



        COMMAND commands[] = {
        {"help", cmd_help, NULL, "Display commands description"},
        {"add", cmd_add, cmd_add_help, "Add a new model from a specific file"},
        {"load", cmd_load, cmd_load_help, "Load a new model from the searchdirs"},
        {"print", cmd_print, cmd_print_help, "Print a model"},
        {"data", cmd_data, cmd_data_help, "Load, validate and optionally print instance data"},
        {"xpath", cmd_xpath, cmd_xpath_help, "Get data nodes satisfying an XPath expression"},
        {"list", cmd_list, cmd_list_help, "List all the loaded models"},
        {"feature", cmd_feature, cmd_feature_help, "Print/enable/disable all/specific features of models"},
        {"searchpath", cmd_searchpath, cmd_searchpath_help, "Print/set the search path(s) for models"},
        {"clear", cmd_clear, cmd_clear_help, "Clear the context - remove all the loaded models"},
        {"verb", cmd_verb, cmd_verb_help, "Change verbosity"},
#ifndef NDEBUG
        {"debug", cmd_debug, cmd_debug_help, "Display specific debug message groups"},
#endif
        {"quit", cmd_quit, NULL, "Quit the program"},
        /* synonyms for previous commands */
        {"?", cmd_help, NULL, "Display commands description"},
        {"exit", cmd_quit, NULL, "Quit the program"},
        {NULL, NULL, NULL, NULL}
};
        class ApiProvider
        {
            public:
                inline void* call_cmd_help(const char *arg) {return cmd_help(*arg);}
                
        };
    }
}





#endif 
