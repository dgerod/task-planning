#include "rosplan_planning_system/FFPlanParser.h"

#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <ctype.h>

/* implementation of rosplan_planning_system::FFPlanParser.h */
namespace KCL_rosplan {

	FFPlanParser::~FFPlanParser() {}

	void FFPlanParser::reset() {
		filter_objects.clear();
		filter_attributes.clear();
		knowledge_filter.clear();
		action_list.clear();
	}

	/*---------------------*/
	/* string manipulation */
	/*---------------------*/

	void FFPlanParser::toLowerCase(std::string &str) {
		std::transform(str.begin(), str.end(), str.begin(), tolower);
	}

	/**
	 * processes the parameters of a single PDDL action into an ActionDispatch message
	 */
	void FFPlanParser::processPDDLParameters(rosplan_dispatch_msgs::ActionDispatch &msg, std::vector<std::string> &params, PlanningEnvironment &environment) {

		// find the correct PDDL operator definition
		std::map<std::string,std::vector<std::string> >::iterator ait;
		ait = environment.domain_operators.find(msg.name);
		if(ait != environment.domain_operators.end()) {

			// add the PDDL parameters to the action dispatch
			for(size_t i=0; i<ait->second.size(); i++) {
				diagnostic_msgs::KeyValue pair;
				pair.key = ait->second[i];
				pair.value = params[i];
				msg.parameters.push_back(pair);

				// prepare object existence for the knowledge filter
				bool add = true;
				for(size_t j=0; j<filter_objects.size(); j++)
					if(0==filter_objects[j].compare(params[i])) add = false;
				if(add) filter_objects.push_back(params[i]);
			}

			// prepare object attributes for the knowledge filter
			for(size_t i=0; i<environment.domain_operator_precondition_map[msg.name].size(); i++) {
				std::vector<std::string> filterAttribute;
				std::vector<std::string> precondition = environment.domain_operator_precondition_map[msg.name][i];
				filterAttribute.push_back(precondition[0]);
				for(size_t j=1; j<precondition.size(); j++) {
                    if(j>1) filterAttribute.push_back(precondition[j]);
					// instance name
					for(size_t k=0;k<ait->second.size();k++) {
						if(0==ait->second[k].compare(precondition[j]))
							filterAttribute.push_back(params[k]);
					}
				}
				filter_attributes.push_back(filterAttribute);
			}
		} // end of operator
	}

	/*----------------------------*/
	/* Parse FF output */
	/*----------------------------*/

	/**
	 * Parse a plan written by FF
	 */
	void FFPlanParser::preparePlan(std::string &dataPath, PlanningEnvironment &environment, size_t freeActionID) {

		ROS_INFO("KCL: (FFPlanParser) Loading plan from file: %s. Initial action ID: %zu", ((dataPath + "plan.pddl").c_str()), freeActionID);
		
		// prepare plan
		reset();
		
		// load plan file
		std::ifstream infile((dataPath + "plan.pddl").c_str());
		std::string line;
		std::vector<std::string> s;
		int curr,next,nodeCount;
		bool planFound = false;
		bool planRead = false;
		
		nodeCount = freeActionID;
		
		while(!infile.eof()) {

			std::getline(infile, line);
			toLowerCase(line);

			// loop until plan is printed
			if(line.compare("ff: found legal plan as follows")==0) {
				planFound = true;
			}
			if(!planFound) continue;

			// skip dividers				
			if(line.compare("-------------------------------------------------")==0) {
				continue;
			}

		}

		infile.close();
	}
	
	/*-----------------*/
	/* Planning filter */
	/*-----------------*/

	/**
	 * populates the knowledge filter messages
	 */
	void FFPlanParser::generateFilter(PlanningEnvironment &environment) {

	}

} // close namespace
