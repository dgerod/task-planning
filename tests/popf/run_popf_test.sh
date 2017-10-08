#!/bin/bash
# Executes a test as a domain and problem pddl files.
# Usage: ./run_popf_tests.sh 'test_name'

timeout 10 ../../planners/popf -n $1_domain.pddl $1_problem.pddl &> $1_plan.txt

echo "--------------------------"
echo "Returned plan"
echo "--------------------------"
cat  $1_plan.txt
echo "--------------------------"
echo "DONE."
