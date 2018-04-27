#include <string>
#include "ros/ros.h"
#include "PlanningEnvironment.h"
#include "PlanParser.h"

#ifndef KCL_cff_plan_parser
#define KCL_cff_plan_parser

namespace KCL_rosplan { namespace cff {

    namespace str_utils {
        
        void toLowerCase(std::string &str);
        unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch);
    }

    class CFFPlanParser: public PlanParser
    {
    private:        
        std::vector<std::string> filter_objects;
        std::vector<std::vector<std::string> > filter_attributes;
        
        void processPDDLParameters(rosplan_dispatch_msgs::ActionDispatch &msg, std::vector<std::string> &params, PlanningEnvironment &environment);

    public:        
        virtual ~CFFPlanParser();

        void reset();
        void preparePlan(std::string &dataPath, PlanningEnvironment &environment, size_t freeActionID);
        void generateFilter(PlanningEnvironment &environment);
    };
    
}}

#endif
