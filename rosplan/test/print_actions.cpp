
/***************************************************************************
 *  print_plan.cpp - print plan as PDDL to output
 *
 *  Created: Wed Mar 22 14:40:56 2017
 *  Copyright  2017  Tim Niemueller [www.niemueller.de]
 ****************************************************************************/

/*  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the authors nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

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

void
print_actions(const std::vector<rosplan_dispatch_msgs::ActionDispatch> actions)
{
    
    for(size_t adx=0; adx<actions.size(); adx++) {
        std::string s;
        for(size_t pdx=0; pdx<actions[adx].parameters.size(); pdx++) {
            s += " " + actions[adx].parameters[pdx].value;
        }
        printf("%7.3f: (%s %s)  [%.3f]\n", actions[adx].dispatch_time, actions[adx].name.c_str(), s.c_str(), actions[adx].duration);
    }
}

int
main(int argc, char **argv)
{   
    std::string dataPath(argv[1]);
    PlanningEnvironment environment;
    size_t freeActionId = 0;
    
    FFPlanParser planParser;
    planParser.reset();
    planParser.preparePlan(dataPath, environment, freeActionId);
    
    print_actions(planParser.action_list);
    
    return 0;
}
