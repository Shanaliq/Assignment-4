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
    int MergeSortCounter;
    int QuickSortCounter;
public:
    Sorting(); // constructor
    ~Sorting(); // destructor
    
    void Swap(int value[], int valueOne, int valueTwo); //Will take two locations and the array and swap the values of both.
    void InsertionSort(int values[], int numValues); // The call to trigger insertion sort.
    void InsertItem(int values [], int start, int end); //
    int GetInsertionSortCounter(); // the counter for Insertion Sort
    
    void MergeSort(int values[], int first, int last); // Call for Merge sort and its recursive calls
    void Merge(int values[], int leftFirst, int leftLast, int rightFirst, int rightLast); // handles the merging.
    int GetMergeSortCounter(); // Counts the number of comaprisons merge sort makes.
    
    void QuickSort(int values[], int first, int last); // Call for Quick sort. Contines the recursive call and Split call.
    void Split(int values[], int first, int last, int &splitpoint); // Splits and seperates greater from lower at from splitpoint
    int GetQuickSortCounter(); //counts the number of comparisons Quick Sort makes.
};
