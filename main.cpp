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
#include "util.hpp"
#include <vector>

const std::string TEST_CASES = "testcases.txt";

int main(int argc, const char * argv[])
{
    std::vector<std::ifstream*> testFiles = loadTestFiles(TEST_CASES);
    std::vector<TestCase> testCases = loadTestCases(testFiles);
    cleanUpTestFiles(testFiles);

    std::vector<int> results;
    results.reserve(testCases.size());
    
    // Runs the tests in the test cases
    for (auto testCase : testCases)
    {
        results.push_back(knapsack(testCase.mMaxWeight, testCase.mNumItems, testCase.items));
    }

    // Prints results
    for (auto result : results) {
        std::cout << result << std::endl;
    }
    return 0;
}
