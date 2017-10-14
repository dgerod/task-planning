
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <iostream>
#include <gtest/gtest.h>

#include "test/rosplan_dispatch_msgs/ActionDispatch.h"
#include "rosplan_planning_system/PlanningEnvironment.h"
#include "rosplan_planning_system/FFPlanParser.h"

using namespace KCL_rosplan;

TEST(FFPlanParser, checkHeader) {
    
    FFPlanParser planParser;
    
    std::string dataPath;
    PlanningEnvironment environment;
    size_t freeActionID;
    
    planParser.reset();
    planParser.preparePlan(dataPath, environment, freeActionID);
}
