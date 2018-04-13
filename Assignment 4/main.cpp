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
        std::cout<<values[i]<<"\n";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    fileHandler("/Users/nekosama/Desktop/Assignment 4/Assignment 4/random.txt");
    sortthis.InsertionSort(pikachu, 10000);
    printArray(pikachu);
    std::cout<<sortthis.GetInsertionSortCounter()<<"\n";
    return 0;
}
