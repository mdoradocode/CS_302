#include <iostream>
#include <time.h>
#include <math.h>
#include "selectionSort.h"

using namespace std;

selectionSort :: selectionSort(){}

selectionSort :: selectionSort(size_t size, size_t array[]):compares(0), swaps(0){
    clock_t start = clock();
    size_t index;
    size_t loopEnder = 0;
    int count = 0;
    while(loopEnder != size ){ //Check if bugs arise
        index = array[loopEnder];
        size_t traverse = loopEnder;
        while(traverse != size){
            count++;
            compares++;
            if(index > array[traverse]){
                swap(index, array[traverse]); //May not work the way i would like it to
                swaps++;
            }
            traverse++;
        }
        array[loopEnder] = index;
        loopEnder++;
    }
    duration = clock() - start;
    
}

void selectionSort :: printStats(){
    cout << "Comparisons Done: " << compares << endl<< "Swaps Done: " <<  swaps << endl << "Time Taken to Complete in Seconds: " << (float(duration))/CLOCKS_PER_SEC;
}