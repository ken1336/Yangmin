#include <iostream>
#include <memory>
#include "internal_module.hpp"

#include<resolve.h>
#include<parser.h>

#define LYD_WHEN       0x04
#define LYD_WHEN_TRUE  0x02
#define LYD_WHEN_FALSE 0x01
#define LYD_WHEN_DONE(status) (!((status) & LYD_WHEN) || ((status) & (LYD_WHEN_TRUE | LYD_WHEN_FALSE)))
// #include<ietf-yang-metadata@2016-08-05.h>
// #include<yang@2017-02-20.h>
// #include<ietf-inet-types@2013-07-15.h>
// #include<ietf-yang-types@2013-07-15.h>
// #include<ietf-datastores@2017-08-17.h>
// #include<ietf-yang-library@2019-01-04.h>
#include "../../models/ietf-yang-metadata@2016-08-05.h"
#include "../../models/yang@2017-02-20.h"
#include "../../models/ietf-inet-types@2013-07-15.h"
#include "../../models/ietf-yang-types@2013-07-15.h"
#include "../../models/ietf-datastores@2017-08-17.h"
#include "../../models/ietf-yang-library@2019-01-04.h"

static struct lyd_node *
lyb_new_node(const struct lys_node *schema)
{
    struct lyd_node *node;

    switch (schema->nodetype) {
    case LYS_CONTAINER:
    case LYS_LIST:
    case LYS_NOTIF:
    case LYS_RPC:
    case LYS_ACTION:
        node = (lyd_node*)calloc(sizeof(struct lyd_node), 1);
        break;
    case LYS_LEAF:
    case LYS_LEAFLIST:
        node = (lyd_node*)calloc(sizeof(struct lyd_node_leaf_list), 1);

        if (((struct lys_node_leaf *)schema)->type.base == LY_TYPE_LEAFREF) {
            node->validity |= LYD_VAL_LEAFREF;
        }
        break;
    case LYS_ANYDATA:
    case LYS_ANYXML:
        node = (lyd_node*)calloc(sizeof(struct lyd_node_anydata), 1);
        break;
    default:
        return NULL;
    }
    //LY_CHECK_ERR_RETURN(!node, LOGMEM(schema->module->ctx), NULL);

    /* fill basic info */
    node->schema = (struct lys_node *)schema;
    if (resolve_applies_when_ex(schema, 0, NULL)) {
        /* this data are considered trusted so if this node exists, it means its when must have been true */
        node->when_status = LYD_WHEN | LYD_WHEN_TRUE;
    }
    node->prev = node;

    return node;
}
namespace min
{
namespace internal
{


constexpr internal_modules_s internal_modules[] = {
    {"ietf-yang-metadata", "2016-08-05", (const char *)ietf_yang_metadata_2016_08_05_yin, 0, LYS_IN_YIN},
    {"yang", "2017-02-20", (const char *)yang_2017_02_20_yin, 1, LYS_IN_YIN},
    {"ietf-inet-types", "2013-07-15", (const char *)ietf_inet_types_2013_07_15_yin, 0, LYS_IN_YIN},
    {"ietf-yang-types", "2013-07-15", (const char *)ietf_yang_types_2013_07_15_yin, 0, LYS_IN_YIN},
    /* ietf-datastores and ietf-yang-library must be right here at the end of the list! */
    {"ietf-datastores", "2017-08-17", (const char *)ietf_datastores_2017_08_17_yin, 0, LYS_IN_YIN},
    {"ietf-yang-library", IETF_YANG_LIB_REV, (const char *)ietf_yang_library_2019_01_04_yin, 1, LYS_IN_YIN}};

InternalModule::InternalModule(const lys_module *module) : BaseModule::BaseModule(module)
{
    //this->module = std::make_unique<lys_module>(*module);
}
InternalModule::InternalModule(ly_ctx *ctx): BaseModule::BaseModule(ctx)
{
    // for(auto i = 0; i<4; i++){
    //     lys_parse_mem(ctx, min::internal::internal_modules[i].data, min::internal::internal_modules[i].format);
    // }
    //auto in = lys_parse_mem(ctx, min::internal::internal_modules[5].data, min::internal::internal_modules[5].format);
    //this->module = std::make_unique<lys_module>(*in);
}



void InternalModule::test()
{
    
    //lys_print_file(stdout,this->getModule().get(),LYS_OUT_TREE,lys_data_path(this->getModule().get()->data),this->getModule().get()->data->ext_size,4);
    //lys_print_file(stdout,this->module.get(),LYS_OUT_TREE,lys_data_path(this->module.get()->data),this->module.get()->data->ext_size,4);
    //std::cout<<lys_data_path(this->module.get()->data->child)<<std::endl;
    //auto xml = lyxml_parse_mem(this->getContext().get(),"<ietf-netconf><get-config></source></get-config></ietf-netconf>",1);
    //
    std::cout<<"lyd_node size:"<<sizeof(lyd_node)<<std::endl;
    std::cout<<"lyd_node_leaf_list size:"<<sizeof(lyd_node_leaf_list)<<std::endl;
    std::cout<<"lyd_node_anydata size:"<<sizeof(lyd_node_anydata)<<std::endl;
    char *mem;
    struct lyd_node *node;
    auto ctx = this->getContext().get();
    //node = lyd_new_yangdata(this->getModule().get(),"ietf-netconf",this->getModule()->name);
    //node = lyd_new(NULL,this->getModule().get(), "l");
    //node = lyd_new(NULL, this->getModule().get()->, "source");
    //resolve_applies_when(this->getModule().get()->data, 0, NULL);
//     char* name = (char*)this->getModule().get()->data->name;
//    std::cout<<this->getModule().get()->data->name<<std::endl;
//     node = lyd_new(NULL,this->getModule().get(),name);
    node = lyb_new_node(this->getModule().get()->data); //get-config
    
    auto subnode = lyb_new_node(this->getModule().get()->data->child->child);   //source
    auto subnode2 = lyb_new_node(this->getModule().get()->data->child->child->next);       //filter
    auto subnode3 = lyb_new_node(this->getModule().get()->data->child->child->child->child->child); //candidate
    std::cout<<lys_data_path(this->getModule().get()->data->child->child->child->child->child)<<std::endl;
    std::cout<<lys_data_path(this->getModule().get()->data->child->child->child->child->next->child)<<std::endl;
    
    auto subnode4 = lyb_new_node(this->getModule().get()->data->child->child->child->child->next->child);


    lyd_node_leaf_list* tt = (lyd_node_leaf_list*)subnode3;
    
    std::cout<<"value type: "<<tt->value_type<<std::endl;
    lyd_insert(node,subnode);
    lyd_insert_after(subnode,subnode2);
    lyd_insert(subnode,subnode3);
    lyd_insert(subnode,subnode4);
    //lyd_insert(subnode,subnode2);
    //std::cout<<"abc: "<<this->getModule().get()->ref<<std::endl;
    //node = lyd_parse_mem(ctx,this->getModule().get()->ref,LYD_XML,1);
    if (lyd_print_mem(&mem, node, LYD_XML, LYP_WITHSIBLINGS)) {
       
    }
    //node->next
    std::cout<<"aa:"<<mem<<std::endl;
    //std::cout<<"bb: "<<lyd_path(node)<<std::endl;
    //auto xml = lyxml_parse_mem(ctx, mem, LYXML_PARSE_NOMIXEDCONTENT);
    //lyxml_print_file(stdout, xml,1);
}

// void InternalModule::printModuleData(int dept)
// {

//     auto iter = this->getModule()->data;
//     int num = 0;
//     std::cout << "----------iter start----------" << std::endl;
//     //printSubNode(iter, 0);
//     printPathNode(iter,0);
//     std::cout << "----------iter end----------" << std::endl;
//     return;
// }

// void InternalModule::printSubModule(lys_module *subModule, int dept)
// {
// }

// void InternalModule::printPathNode(lys_node *node, int dept)
// {
//     auto iter = node;

//     while(iter)
//     {
//         printIndent(dept);
//         std::cout<<lys_data_path(iter)<<std::endl;
//         if (iter->child)
//         {
            
//             printPathNode(iter->child, dept + 1);
//         }

//         if (iter->next)
//         {
//             iter = iter->next;
//         }
//         else
//         {
//             return;
//         }
//     }
// }
// void InternalModule::printSubNode(lys_node *node, int dept)
// {

//     auto iter = node;

//     while (iter)
//     {
//         printIndent(dept);
//         //std::cout<<"nodetype: "<<iter->nodetype
//         //if(iter->flags >= 0 && iter->flags <= 64 )
//         if (iter->nodetype != 33 && iter->nodetype != LYS_UNKNOWN && iter->nodetype != LYS_CHOICE && iter->nodetype < 0x10000)
//         {
//             std::cout << "  " << iter->nodetype << " : " << iter->name << std::endl;
//             // for (auto i = 0; i < dept; i++)
//             // {
//             //     std::cout << "  ..  ";
//             // }
//             // std::cout<<iter->dsc<<std::endl;
//         }

//         else
//         {
//             std::cout << "  skip--" << std::endl;
//             return;
//         }

//         // std::cout<<iter->dsc<<std::endl;
//         if (iter->child)
//         {
//             printSubNode(iter->child, dept + 1);
//         }

//         if (iter->next)
//         {
//             iter = iter->next;
//         }
//         else
//         {
//             return;
//         }
//     }

//     return;
// }

InternalModule::~InternalModule(){};
} // namespace internal
} // namespace min