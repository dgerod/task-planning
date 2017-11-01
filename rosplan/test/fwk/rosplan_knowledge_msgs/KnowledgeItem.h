
#ifndef rosplan_knowledge_knowledge_item
#define rosplan_knowledge_knowledge_item

#include <string.h>
#include "diagnostic_msgs/KeyValue.h"

namespace rosplan_knowledge_msgs {

    class KnowledgeItem
    {
    public:
        // A knowledge item used to represent a piece of the world model in ROSPlan
        enum { INSTANCE=0, FACT=1, FUNCTION=2 };        
        unsigned int knowledge_type;
        
        // instance knowledge_type
        std::string instance_type;
        std::string instance_name;
        
        // attribute knowledge_type
        std::string attribute_name;
        std::vector<diagnostic_msgs::KeyValue> values;
    };
}

#endif


