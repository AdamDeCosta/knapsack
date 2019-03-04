//
//  util.hpp
//  knapsack
//
//  Created by Adam DeCosta on 2/26/19.
//  Copyright © 2019 Adam DeCosta. All rights reserved.
//

#ifndef util_hpp
#define util_hpp

#include <iostream>
#include <fstream>
#include "Item.hpp"
#include <string>
#include <vector>

struct TestCase {
    int mMaxWeight;
    int mNumItems;
    std::vector<Item> items;
};

std::vector<std::ifstream*> loadTestFiles(std::string files);
std::vector<TestCase> loadTestCases(const std::vector<std::ifstream*>& testFiles);
void cleanUpTestFiles(std::vector<std::ifstream*>& testFiles);

#endif /* util_hpp */
