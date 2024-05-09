#!/bin/bash

comparisons_sum=0
worst_case=0
best_case=1000000
numbers=21
iterations=10

for i in $(seq 1 $iterations); do
    output_number=$(./PmergeMe `shuf -i 1-100000 -n $numbers | tr "\n" " "` | grep -m 1 [Cc]omparisons | awk -F " " '{print $NF}')
    if ((output_number < best_case)); then
        best_case=($output_number)
    fi
    if ((output_number > worst_case)); then
        worst_case=($output_number)
    fi
    # echo "round $i: $output_number"
    comparisons_sum=$((comparisons_sum + output_number))
    # echo "comparisons_sum: $comparisons_sum"
    echo "Comparisons: $output_number, with $numbers numbers"
    numbers=$(expr $numbers '*' 2);
done

echo "|-----------------------|"
echo "| Der ultimative Tester |"
echo "|-----------------------|"
echo " > numbers: $numbers"
echo " > iterations: $iterations"
echo " > worst_case: $worst_case"
echo " > best_case: $best_case"
echo " > average: $((comparisons_sum / iterations))"
echo "|-----------------------|"