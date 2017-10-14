#ifndef diagnostic_msgs_keyvalue
#define diagnostic_msgs_keyvalue

#include <string>

namespace diagnostic_msgs {

    class KeyValue
    {
    public:
        std::string key;
        std::string value;
    };
}

#endif

