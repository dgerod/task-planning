
#ifndef rosplan_action_dispatch
#define rosplan_action_dispatch

#include "diagnostic_msgs/KeyValue.h"

namespace rosplan_dispatch_msgs {

    class ActionDispatch
    {
    public:
        std::string name;
        std::vector<diagnostic_msgs::KeyValue> parameters;
    };
}

#endif
