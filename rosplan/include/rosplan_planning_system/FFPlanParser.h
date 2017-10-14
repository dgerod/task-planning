#include "ros/ros.h"
#include "diagnostic_msgs/KeyValue.h"
#include "PlanningEnvironment.h"
#include "PlanParser.h"

#ifndef KCL_ff_plan_parser
#define KCL_ff_plan_parser

namespace KCL_rosplan {

	/* Plan Parsing class definition for Fast Forward planner*/
	class FFPlanParser: public PlanParser
	{

	private:
		
		/* plan knowledge filter */
		std::vector<std::string> filter_objects;
		std::vector<std::vector<std::string> > filter_attributes;

		void toLowerCase(std::string &str);
		unsigned int split(const std::string &txt, std::vector<std::string> &strs, char ch);
		void parseDomain();
		
        void processPDDLParameters(rosplan_dispatch_msgs::ActionDispatch &msg, std::vector<std::string> &params, PlanningEnvironment &environment);

	public:

		virtual ~FFPlanParser();

		/* post process plan */
		double total_plan_duration;

		/* virtual methods */
		void reset();
		void preparePlan(std::string &dataPath, PlanningEnvironment &environment, size_t freeActionID);
		void generateFilter(PlanningEnvironment &environment);
	};
}
#endif
