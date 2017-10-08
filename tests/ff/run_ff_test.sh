#!/bin/bash
# Executes a test as a domain and problem pddl files.
# Usage: ./run_ff_tests.sh 'test_name'

timeout 10 ../../planners/ff -o $1_domain.pddl $1_problem.pddl > $1_plan.txt

echo "--------------------------"
echo "Returned plan"
echo "--------------------------"
cat  $1_plan.txt
echo "--------------------------"
echo "DONE."
