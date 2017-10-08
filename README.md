
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

POPF name derives from the fact that it incorporates ideas from partial-order planning, this binary is the one provided by ROSPlan. However, the planner was developed by _A. Coles_. 

Usage: `./popf <domain file> <problem file>`

References: 
* https://nms.kcl.ac.uk/andrew.coles
* http://www.inf.kcl.ac.uk/research/groups/planning
* https://github.com/KCL-Planning/ROSPlan

## Contingent Fast Forward

Contingent-FF is an extension of Conformant-FF to further treat partial observability (observation actions), finding tree-shaped plans with branches; the system also includes a preliminary treatment of a simple form of non-deterministic effects. While Conformant-FF planner is a system that extends the classical FF planner with the ability to treat initial state uncertainty expressed in the form of a CNF formula. This binary is the one provided by ROSPlan but the planner was developed by _J. Hoffmann_ in collaboration with _R. Brafman_.

Usage: `./Contingent-FF -o <domain file> -f <problem file>`

References: 
* https://fai.cs.uni-saarland.de/hoffmann/cff.html
* https://github.com/KCL-Planning/ROSPlan

