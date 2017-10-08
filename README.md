
# Task Planning

Some AI planners that work with PDDL and examples.

## Fast Forward

FF is a very successful forward-chaining heuristic search planner producing sequential plans.

Usage: `./ff -o <domain file> -f <problem file>`

References: 
* https://github.com/guillaume-chevalier/AI-Planning-Solver-Shakeys-World-PDDL
* https://www.ida.liu.se/%7ETDDC17/info/labs/lab4_planning.en.shtml

## Interference Progression Planner

IPP is a descendant of Graphplan and it produces optimal parallel plans.

Usage: `./ipp -o <domain file> -f <problem file>`

References: 
* https://github.com/guillaume-chevalier/AI-Planning-Solver-Shakeys-World-PDDL
* https://www.ida.liu.se/%7ETDDC17/info/labs/lab4_planning.en.shtml

## Forward-chaining Temporal Planner 

Its name derives from the fact that it incorporates ideas from partial-order planning. This binary is the one provided by ROSPlan but it is developed by _A. Coles_ of the KCL. 

Usage: `./popf <domain file> -f <problem file>`

References: 
* https://github.com/KCL-Planning/ROSPlan
* https://nms.kcl.ac.uk/andrew.coles
* http://www.inf.kcl.ac.uk/research/groups/planning

