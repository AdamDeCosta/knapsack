//
//  grokking.cpp
//  knapsack
//
//  Created by Adam DeCosta on 2/19/19.
//  Copyright © 2019 Adam DeCosta. All rights reserved.
//

#include "grokking.hpp"

int knapsack(int maxWeight, int numItems, std::vector<Item> items)
{
    // Base cases
    if (numItems <= 0 || maxWeight <= 0)
        return 0;
    if (numItems == 1 && items.at(0).getWeight() <= maxWeight)
        return items.at(0).getValue();
    // END Base cases
    
    std::vector<std::vector<int>> grid;
    grid.resize(numItems);
    
    // Fill first column
    for (auto i = 0; i < numItems; i++)
    {
        grid.at(i).resize(maxWeight+1);
    }

    // Fill first row
    for (int i = 1; i <= maxWeight; i++)
    {
        if (items.at(0).getWeight() <= i)
        {
            grid.at(0).at(i) = items.at(0).getValue();
        }
        else
        {
            grid.at(0).at(i) = grid.at(0).at(i-1);
        }
    }
    
    // Fill rest of grid
    int i, j;
    for (i = 1; i < numItems; i++)
    {
        for (j = 1; j <= maxWeight; j++)
        {
            if (items.at(i).getWeight() > j)
            {
                grid.at(i).at(j) = grid.at(i-1).at(j);
            }
            else
            {
                grid.at(i).at(j) = std::max(grid.at(i-1).at(j), items.at(i).getValue() + grid.at(i-1).at(j - items.at(i).getWeight()));
            }
        }
    }
    
    // Print grid
    /* Uncomment to print out the grid
    for (auto weights : grid)
    {
        for (auto maxValue: weights)
        {
            std::cout << "[ " << maxValue << " ]";
        }
        std::cout << std::endl;
    }
    */


    return grid.at(numItems - 1).at(maxWeight);
}
