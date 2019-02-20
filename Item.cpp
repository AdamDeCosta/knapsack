//
//  Item.cpp
//  knapsack
//
//  Created by Adam DeCosta on 2/19/19.
//  Copyright © 2019 Adam DeCosta. All rights reserved.
//

#include "Item.hpp"

int Item::getValue() {
    return mValue;
}

int Item::getWeight() {
    return mWeight;
}

void Item::setValue(int value) {
    mValue = value;
}

void Item::setWeight(int weight) {
    mWeight = weight;
}

Item::Item() {
    mWeight = 0;
    mValue  = 0;
}

Item::Item(int weight, int value) {
    mWeight = weight;
    mValue  = value;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << "weight: " << item.mWeight << ", value: " << item.mValue;
    return os;
}
