//
//  grokking.cpp
//  knapsack
//
//  Created by Adam DeCosta on 2/19/19.
//  Copyright © 2019 Adam DeCosta. All rights reserved.
//

#include "grokking.hpp"

int knapsack(int maxWeight, int numItems, Item items[numItems]) {
    // Base cases
    if (numItems == 0)
        return 0;
    if (numItems == 1 && items[0].getWeight() <= maxWeight)
        return items[0].getValue();
    // END Base cases
    
    int grid[numItems][maxWeight+1];
    int i, j;
    
    // Fill first column
    for (i = 0; i < numItems; i++) {
        grid[i][0] = 0;
    }
    
    // Fill first row
    for (i = 1; i <= maxWeight; i++) {
        if (items[0].getWeight() <= i) {
            grid[0][i] = items[0].getValue();
        } else {
            grid[0][i] = grid[0][i-1];
        }
    }
    
    // Fill rest of grid
    for (i = 1; i < numItems; i++) {
        for (j = 1; j <= maxWeight; j++) {
            if (items[i].getWeight() > j) {
                grid[i][j] = grid[i-1][j];
            } else {
                grid[i][j] = std::max(grid[i-1][j], items[i].getValue() + grid[i-1][j - items[i].getWeight()]);
            }
        }
    }
    
    // Print grid
    for (i = 0; i < numItems; i++) {
        for (j = 0; j <= maxWeight; j++) {
            std::cout << "[ " << grid[i][j] << " ]";
        }
        std::cout << std::endl;
    }
    
    return grid[numItems-1][maxWeight];
}
