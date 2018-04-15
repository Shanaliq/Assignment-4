//
//  main.cpp
//  Assignment 4
//
//  Created by Nekosama on 4/12/18.
//  Copyright © 2018 Nekosama. All rights reserved.
//


#include <iostream>
#include "Sorting.h"
#include <fstream>
#include <string>
using namespace std;
int pikachu[10000] = {};
Sorting sortthis;

void fileHandler(string file){ // handles the file input.
    int count = 0;
    int input;
    std::fstream fs;
    fs.open(file);
    if(fs.is_open())
    {
        fs >> input;
        while(!fs.eof())
        {
            pikachu[count] = input;
            count++;
            fs >> input;
        }
        
    }
    else{
        std::cout<<"Failed to open the input file"<<std::endl;
        exit(0);
    }
}

void printArray(int values[]){
    for(int i = 0; i<10000; i++){
        std::cout<<values[i]<<" ";
    }
}

int main(int argc, const char * argv[]) {
    int continueLoop = 1;
    char userInputChar;
    int userInputNum;
    fileHandler("/Users/nekosama/Desktop/Assignment 4/Assignment 4/random.txt");
    std::cout << "insertion-sort (i) merge-sort (m) quick-sort (q)\n";
    while (continueLoop == 1) {
        std::cout << "Enter the algorithm: ";
        cin >> userInputChar;
        switch (userInputChar) {
            case 'i': {
                sortthis.InsertionSort(pikachu, 10000);
                std::cout<<"Insertion sort: ";
                printArray(pikachu);
                std::cout << "\n    Total # comparisons: "<< sortthis.GetInsertionSortCounter()<<"\n";
                break;
            }
            case 'm': {
                sortthis.MergeSort(pikachu, 0, 9999);
                std::cout<<"Merge sort: ";
                printArray(pikachu);
                std::cout << "\n    Total # comparisons: "<< sortthis.GetInsertionSortCounter()<<"\n";
                break;
            }
            case 'q': {
                break;
            }
        }
    }
    
    
    
    
}
