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
    MergeSortCounter = 0;
    QuickSortCounter = 0;
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
    InsertionSortCounter = 0;
    for(int count = 0; count< numValues; count++){
        InsertItem(values,0,count);
    }
}

int Sorting::GetInsertionSortCounter(){
    return InsertionSortCounter;
}

int Sorting::GetMergeSortCounter(){
    return MergeSortCounter;
}


void Sorting::MergeSort(int values[], int first, int last){
    if (first < last){
        int middle = (first + last)/2;
        MergeSort(values, first, middle);
        MergeSort(values, middle+1, last);
        Merge(values, first, middle, middle+1, last);
    }
}

void Sorting::Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast){
    int tempArray[10000];
    int index = leftFirst;
    int saveFirst = leftFirst;
    
    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if(values[leftFirst] < values[rightFirst])
        {
            MergeSortCounter++;
            tempArray[index]= values[leftFirst];
            leftFirst++;
        }
        else
        {
            MergeSortCounter++;
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }
    
    while(leftFirst <= leftLast)
    {
        tempArray[index]=values[leftFirst];
        leftFirst++;
        index++;
    }
    while(rightFirst<= rightLast){
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }
    for(index = saveFirst; index <= rightLast; index++){
        values[index]= tempArray[index];
    }
}

void Sorting::QuickSort(int values[], int first, int last){
    int splitPoint;
    if (first < last){
        Split(values, first, last, splitPoint);
        QuickSort(values, first, splitPoint-1);
        QuickSort(values, splitPoint+1, last);
    }
}

void Sorting::Split(int values[], int first, int last, int &splitpoint){
    int splitVal = values[first];
    int saveFirst = first;
    bool onCorrectSide;
    first++;
    do
    {
        onCorrectSide = true;
        while(onCorrectSide)
            if(values[first]>splitVal){
                QuickSortCounter++;
                onCorrectSide = false;
            }
            else{
                QuickSortCounter++;
                first++;
                onCorrectSide = (first < last);
            }
        onCorrectSide=(first <= last);
        while(onCorrectSide)
            if(values[last]<=splitVal){
                QuickSortCounter++;
                onCorrectSide= false;
            }
            else{
                QuickSortCounter++;
                last--;
                onCorrectSide = (first <= last);
            }
        if(first < last){
            Swap(values, first, last);
            first ++;
            last --;
        }
    }while(first <= last);
    splitpoint = last;
    Swap(values, saveFirst, splitpoint);
}

int Sorting::GetQuickSortCounter(){
    return QuickSortCounter;
}




