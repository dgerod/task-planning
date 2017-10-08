
# task-planning

Some AI planners that work with PDDL and examples.

## Planners

* Fast Forward (ff)
* Interference Progression Planner (ipp)

### Fast Forward

FF is a very successful forward-chaining heuristic search planner producing sequential plans.

Usage: ./ff -o <domain file> -f <problem file>

References: [1](https://github.com/guillaume-chevalier/AI-Planning-Solver-Shakeys-World-PDDL) and [2](https://www.ida.liu.se/%7ETDDC17/info/labs/lab4_planning.en.shtml)

### Interference Progression Planner

IPP is a descendant of Graphplan and it produces optimal parallel plans.

Usage: ./ipp -o <domain file> -f <problem file>

References: [1](https://github.com/guillaume-chevalier/AI-Planning-Solver-Shakeys-World-PDDL) and [2](https://www.ida.liu.se/%7ETDDC17/info/labs/lab4_planning.en.shtml)

