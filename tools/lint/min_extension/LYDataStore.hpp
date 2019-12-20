#include <context.h>
#include <iostream>
#include <string>
#include <memory>
#include <cassert>

#include"MinStore.hpp"

namespace min
{

namespace context
{
class LYDataStore : public Store
{
private:
    std::shared_ptr<lyd_node*> node;
    Store& store;
public:
    void InitRoot();
    std::shared_ptr<lyd_node*> getNode();
    std::shared_ptr<lyd_node*> setNode(lyd_node* node);
    
    
};

} // namespace context
} // namespace min