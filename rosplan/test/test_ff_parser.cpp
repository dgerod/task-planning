
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
#include <iostream>
#include <gtest/gtest.h>

#include "rosplan_dispatch_msgs/ActionDispatch.h"
#include "rosplan_planning_system/PlanningEnvironment.h"
#include "rosplan_planning_system/FFPlanParser.h"

using namespace KCL_rosplan;

TEST(FFPlanParser, plan_file_empty) {
    
    FFPlanParser planParser;
    
    std::string dataPath("../rosplan/test/prf-db/test_empty_");
    PlanningEnvironment environment;
    size_t freeActionID;
    
    planParser.reset();
    planParser.preparePlan(dataPath, environment, freeActionID);
    ASSERT_EQ(planParser.action_list.size(), 0);
}


TEST(FFPlanParser, plan_not_solved) {
        
    FFPlanParser planParser;
    
    std::string dataPath("../rosplan/test/prf-db/test_error_");
    PlanningEnvironment environment;
    size_t freeActionID;
    
    planParser.reset();
    planParser.preparePlan(dataPath, environment, freeActionID);
    ASSERT_EQ(planParser.action_list.size(), 0);
}

TEST(FFPlanParser, plan_with_one_action) {
    
    
    FFPlanParser planParser;
    
    std::string dataPath("../rosplan/test/prf-db/test_1-action_");
    PlanningEnvironment environment;
    size_t freeActionID = 10;
    
    planParser.reset();
    planParser.preparePlan(dataPath, environment, freeActionID);
    ASSERT_EQ(planParser.action_list.size(), 1);
    
    ASSERT_EQ(planParser.action_list[0].action_id, 10);
    ASSERT_STREQ(planParser.action_list[0].name.c_str(), "goto_place");    
    //ASSERT_STREQ(planParser.action_list[0].parameters[0].c_str(), "c1");

}

TEST(FFPlanParser, plan_with_two_actions) {
    
    
    FFPlanParser planParser;
    
    std::string dataPath("../rosplan/test/prf-db/test_2-actions_");
    PlanningEnvironment environment;
    size_t freeActionID = 20;
    
    planParser.reset();
    planParser.preparePlan(dataPath, environment, freeActionID);
    ASSERT_EQ(planParser.action_list.size(), 2);
        
    ASSERT_EQ(planParser.action_list[0].action_id, 20);
    ASSERT_STREQ(planParser.action_list[0].name.c_str(), "goto_place");    
    //ASSERT_STREQ(planParser.action_list[0].parameters[0], "c1");
    
    ASSERT_EQ(planParser.action_list[1].action_id, 21);
    ASSERT_STREQ(planParser.action_list[1].name.c_str(), "find_object");    
    //ASSERT_STREQ(planParser.action_list[1].parameters[0], "v1");
    //ASSERT_STREQ(planParser.action_list[1].parameters[1], "c1");
}
