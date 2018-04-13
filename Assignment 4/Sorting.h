//
//  SM.hpp
//  Assignment 4
//
//  Created by Nekosama on 4/12/18.
//  Copyright © 2018 Nekosama. All rights reserved.
//

#ifndef Sorting_h
#define Sorting_h

#include <stdio.h>

#endif /* Sorting_h */

class Sorting { //Sort Method
private:
    int InsertionSortCounter;

public:
    Sorting();
    ~Sorting();
    
    void Swap(int value[], int valueOne, int valueTwo);
    void InsertionSort(int values[], int numValues);
    void InsertItem(int values [], int start, int end);
    int GetInsertionSortCounter();
};
