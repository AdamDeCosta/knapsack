//
//  Item.hpp
//  knapsack
//
//  Created by Adam DeCosta on 2/19/19.
//  Copyright © 2019 Adam DeCosta. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <iostream>

class Item
{
    
private:
    int mValue;
    int mWeight;
    
public:
    
    Item();
    Item(int weight, int value);
    
    int getValue();
    int getWeight();
    
    void setValue(int value);
    void setWeight(int weight);
    
    friend std::ostream& operator<<(std::ostream& os, const Item& item);
    
};

#endif /* Item_hpp */
