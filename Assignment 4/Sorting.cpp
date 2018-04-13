//
//  SM.cpp
//  Assignment 4
//
//  Created by Nekosama on 4/12/18.
//  Copyright © 2018 Nekosama. All rights reserved.
//

#include "Sorting.h"

Sorting::Sorting(){
    InsertionSortCounter = 0;
}

Sorting::~Sorting(){
    
}

void Sorting::Swap(int value[], int valueOne, int valueTwo){
    int temp = 0;
    temp = value[valueOne];
    value[valueOne]= value[valueTwo];
    value[valueTwo] = temp;
}

void Sorting::InsertItem(int value [], int start, int end){
    bool finished = false;
    int current = end;
    bool moreToSearch =(current != start);

    while(moreToSearch && !finished){
            InsertionSortCounter ++;
        if(value[current]<value[current-1]){
            Swap(value,current,(current-1));
            current--;
            moreToSearch = (current != start);
        }
        else{
            finished = true;
        }
    }
}

void Sorting::InsertionSort(int values[], int numValues){
    for(int count = 0; count< numValues; count++){
        InsertItem(values,0,count);
    }
}

int Sorting::GetInsertionSortCounter(){
    return InsertionSortCounter;
}

