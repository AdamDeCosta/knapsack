//
//  main.cpp
//  knapsack
//
//  Created by Adam DeCosta on 2/19/19.
//  Copyright © 2019 Adam DeCosta. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Item.hpp"
#include "grokking.hpp"

int main(int argc, const char * argv[]) {
    std::ifstream fin("input.txt");
    
    int numItems,
        maxWeight,
        itemValue,
        itemWeight;
    
    std::string name;
    
    if (fin.is_open()) {
        fin >> maxWeight >> numItems;
        Item items[numItems];
        for (int i = 0; !fin.eof(); i++) {
            fin >> name >> itemWeight >> itemValue;
            items[i].setWeight(itemWeight);
            items[i].setValue(itemValue);
        }
        
        std::cout << knapsack(maxWeight, numItems, items) << std::endl;
        
        fin.close();
    }
    
    return 0;
}
