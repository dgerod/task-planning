
#ifndef rosplan_action_dispatch
#define rosplan_action_dispatch

#include "diagnostic_msgs/KeyValue.h"

namespace rosplan_dispatch_msgs {

    class ActionDispatch
    {
    public:
        int action_id;
        std::string name;
        std::vector<diagnostic_msgs::KeyValue> parameters;
        double duration;
        double dispatch_time;
    };
}

#endif
