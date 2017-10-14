/**
 * This file describes the planning environment.
 * The domain is parsed from the PDDL domain file.
 * The problem instance is fetched from the Knowledge Base.
 */
#include <iostream>
#include <string>
#include <map>
#include <vector>

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

	};
} // close namespace

#endif
