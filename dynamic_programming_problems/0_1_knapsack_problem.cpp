/*
 * 0-1 Knapsack Problem: Imagine you are a thief and you want to steal things from room full of things.
 * You have a knapsack which can handle maximum capacity of weight W, and you want to fill it up such 
 * that it's worth is maximum. Being an intelligent thief, you know weights and values of each item in the room.
 * How would you fill your knapsack, such that you get the maximum possible value for your knapsack of capacity W.
 * 
 * The problem essentially boils down to whether item i would be part of your loot or not.
 * This has optimal substructure:
 * case 1: Item I is in your loot:
 *  Then the maximum value of the loot is determined by remaining n-1 items whose possible weight would be
 *  W-(weight of Item I)
 * 
 * case 2: Item I is not in your loot:
 * Then the maximum value of the loot is determined by remaining n-1 items whose possible weight would be
 * W. (i.e excluding the ith item)
 *
 * We could get all subsets of possible items in the loot, and choose the one with maximum value.
 * 
 * Since this problem will have overlapping subproblems, we could use dynamic programming to solve it.
 * So that we don't recurse to calculate the same subproblem which we have already calculated.
 * 
 */

#include <iostream>
#include <vector>

int maximum_possible_loot_value(const std::vector<int>& weights,
    const std::vector<int>& values, const int capacity)
{
    int items_count = values.size();
    std::vector<std::vector<int>> loots(items_count + 1, std::vector<int>(capacity + 1));
    for (int i = 0; i <= items_count; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0) {
                loots[i][w] = 0;
            }
            else if (weights[i-1] <= w) {
                loots[i][w] = std::max(values[i-1] + loots[i-1][w-weights[i-1]], loots[i-1][w]);
            } else {
                loots[i][w] = loots[i-1][w];
            }
        }
    }
    return loots[items_count][capacity];
}

void print_vector(const std::vector<int>& vec) {
    for (auto v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> values{40, 10, 90};
    std::vector<int> weights{20, 40, 60};
    int capacity = 100;
    std::cout << "Weights of items: ";
    print_vector(weights);
    std::cout << "Values of items: ";
    print_vector(values);
    std::cout << "Capacity :" << capacity << std::endl;
    std::cout << "Maximum possible loot value for capacity " << capacity
        << ": " << maximum_possible_loot_value(weights, values, capacity) << std::endl;
    return 0; 
}
