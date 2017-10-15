/**
 * This file describes the planning environment.
 * The domain is parsed from the PDDL domain file.
 * The problem instance is fetched from the Knowledge Base.
 */
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "rosplan_knowledge_msgs/KnowledgeItem.h"

#ifndef KCL_environment
#define KCL_environment

namespace KCL_rosplan
{

    class PlanningEnvironment
    {
    public:
        PlanningEnvironment() : domain_parsed(false) {}

		/* PDDL to Knowledge Base naming map */
		std::map<std::string,std::string> name_map;

		/* domain information */
		bool domain_parsed;
		std::string domainName;
		std::vector<std::string> domain_types;
		std::map<std::string,std::vector<std::string> > domain_predicates;
		std::map<std::string,std::vector<std::string> > domain_operators;
		std::map<std::string,std::vector<std::string> > domain_operator_types;
		std::map<std::string,std::vector<std::string> > domain_functions;

		// maps operator name to a list of preconditions; stored as [pred_name, label_0, label_1, ...]
		std::map<std::string, std::vector<std::vector<std::string> > > domain_operator_precondition_map;

		/* problem information */
		std::vector<rosplan_knowledge_msgs::KnowledgeItem> instance_attributes;
		std::vector<rosplan_knowledge_msgs::KnowledgeItem> domain_attributes;
		std::vector<rosplan_knowledge_msgs::KnowledgeItem> goal_attributes;

		// maps object type name to list of object instance names
		std::map<std::string,std::vector<std::string> > type_object_map;

		// maps instance name to type name
		std::map<std::string,std::string> object_type_map;
    };
}

#endif
