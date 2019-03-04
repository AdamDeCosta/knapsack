//
//  util.cpp
//  knapsack
//
//  Created by Adam DeCosta on 2/26/19.
//  Copyright © 2019 Adam DeCosta. All rights reserved.
//

#include "util.hpp"

std::vector<std::ifstream*> loadTestFiles(std::string files)
{
    std::vector<std::ifstream*> testFileStreams;
    std::ifstream fin{files};
    
    std::string fileName;
    
    while(!fin.eof())
    {
        std::getline(fin, fileName, '\n');
        
        if (fileName == "") // Stops it from returning the last line as a filename.
            continue;
        
        // Allows the ifstreams to leave the scope of this function
        std::ifstream* testCaseInputStream = new std::ifstream{fileName};
        
        testFileStreams.push_back(testCaseInputStream);
    }
    
    fin.close();
    
    return testFileStreams;
}

std::vector<TestCase> loadTestCases(const std::vector<std::ifstream*>& testFiles) {
    std::vector<TestCase> testCases;
    
    std::string itemName;
    
    int maxWeight,
        numItems,
        itemValue,
        itemWeight;
    
    for (auto testFile : testFiles)
    {
        *testFile >> maxWeight >> numItems;
        std::vector<Item> items;
        items.reserve(numItems);
        
        for (int i = 0; i < numItems; i++)
        {
            *testFile >> itemName >> itemWeight >> itemValue;
            
            items.push_back(Item{itemWeight, itemValue});
        }
        
        testCases.push_back(TestCase{maxWeight, numItems, items});
    }
    
    return testCases;
}

void cleanUpTestFiles(std::vector<std::ifstream*>& testFiles)
{
    for (auto it = testFiles.begin(); it != testFiles.end(); it++)
    {
        (*it)->close();
        delete (*it);
        (*it) = nullptr;
    }
    
    testFiles.clear();
}
