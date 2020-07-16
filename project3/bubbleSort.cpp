#include <iostream>
#include <time.h>
#include <math.h>
#include "bubbleSort.h"

using namespace std;

bubbleSort :: bubbleSort(){}

bubbleSort :: bubbleSort(size_t size, size_t array[]){
    compares = 0;
    swaps = 0;
    clock_t start = clock();
    int isItDone = 1;
    for(size_t i = 0; i < size-1; i++){
        isItDone = 1;
        for(size_t j = 0; j < size - i - 1; j++){
            compares++;
            if(compare(array[j], array[j+1]) == true){
                swap(array[j], array[j+1]);
                swaps++;
                isItDone = 0;
            }
        }
        if(isItDone == 1){
            break;
        }
    }
    duration = clock()-start;
}

bool bubbleSort :: compare(size_t a, size_t b){
    if(a > b){
    return true;
    }
    else{
        return false;
    }
}

void bubbleSort :: printStats(){
    cout << "Comparisons Done: " << compares << endl<< "Swaps Done: " <<  swaps << endl << "Time Taken to Complete in Seconds: " << (float(duration))/CLOCKS_PER_SEC;
}