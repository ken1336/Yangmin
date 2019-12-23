#include "LibyangWrapper.hpp"

namespace min
{
namespace wrapper
{
bool LibyangWrapper::isInLYS_NODE(LYS_NODE type)
{
    switch (type)
    {
    case LYS_UNKNOWN:   /**< uninitialized unknown statement node */
    case LYS_CONTAINER: /**< container statement node */
    case LYS_CHOICE:    /**< choice statement node */
    case LYS_LEAF:      // = 0x0004,     /**< leaf statement node */
    case LYS_LEAFLIST:  // = 0x0008, /**< leaf-list statement node */
    case LYS_LIST:      //= 0x0010,     /**< list statement node */
    case LYS_ANYXML:    //= 0x0020,   /**< anyxml statement node */
    case LYS_CASE:      //= 0x0040,     /**< case statement node */
    case LYS_NOTIF:     //= 0x0080,    /**< notification statement node */
    case LYS_RPC:       //= 0x0100,      /**< rpc statement node */
    case LYS_INPUT:     //= 0x0200,    /**< input statement node */
    case LYS_OUTPUT:    // = 0x0400,   /**< output statement node */
    case LYS_GROUPING:  // = 0x0800, /**< grouping statement node */
    case LYS_USES:      //= 0x1000,     /**< uses statement node */
    case LYS_AUGMENT:   //= 0x2000,  /**< augment statement node */
    case LYS_ACTION:    //= 0x4000,   /**< action statement node */
    case LYS_ANYDATA:   //= 0x8020,  /**< anydata statement node, in tests it can be used for both #LYS_ANYXML and #LYS_ANYDATA */
    case LYS_EXT:       //= 0x10000      /**< complex extension instance, ::lys_ext_instance_complex */
        return true;
    default:
        return false;
    }
}
} // namespace wrapper
} // namespace min
