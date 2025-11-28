#!/bin/bash

test_push_swap() {
    local size=$1
    local iterations=$2
    local max=0
    local min=999999
    local worst=""
    local best=""
    local total=0

    echo "=== Testing with $size numbers ($iterations iterations) ==="
    
    for i in $(seq 1 $iterations); do
        ARG=$(shuf -i 1-$size | tr '\n' ' ')
        count=$(./push_swap $ARG | wc -l)
        total=$((total + count))
        
        if [ $count -gt $max ]; then
            max=$count
            worst=$ARG
            echo "  New max: $max (iteration $i)"
        fi
        if [ $count -lt $min ]; then
            min=$count
            best=$ARG
            echo "  New min: $min (iteration $i)"
        fi
    done

    avg=$((total / iterations))
    
    echo ""
    echo "=== RESULTS FOR $size NUMBERS ==="
    echo "Best:    $min operations"
    echo "Worst:   $max operations"
    echo "Average: $avg operations"
    echo ""
    echo "BEST_$size=\"$best\""
    echo ""
    echo "WORST_$size=\"$worst\""
    echo "================================"
    echo ""
}

# Test 100 nombres (1000 iterations)
test_push_swap 100 1000

# Test 500 nombres (500 iterations - plus long)
test_push_swap 500 500