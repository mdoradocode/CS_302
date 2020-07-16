#include <iostream>
#include <time.h>
#include <math.h>
#include "quickSort.h"

using namespace std;

quickSort :: quickSort(){}

quickSort :: quickSort(size_t size, size_t array[]):swaps(0),compares(0){
    clock_t start = clock();
    size_t low = 0;
    size_t high = (size -1);
    sortQuickly(low, high, array);
    duration = clock()-start;
}

void quickSort :: sortQuickly(size_t low, size_t high, size_t array[]){
    if(low < high){
        size_t splitIndex = partition(low, high, array);
        sortQuickly(low, splitIndex-1, array);
        sortQuickly(splitIndex+1, high, array);
    }
}

size_t quickSort :: partition(size_t low, size_t high, size_t array[]){
    size_t pivot = array[high];
    size_t index = low-1;   
    for(size_t i = low; i <= high-1; i++){
        compares++;
            if(array[i] < pivot){
            swaps++;  
            index++;
            swap(array[index], array[i]);
        }
        
    }    
    swaps++;    
    swap(array[index+1], array[high]);
    return (index+1);
}
void quickSort :: printStats(){
    cout << "Comparisons Done: " << compares << endl<< "Swaps Done: " <<  swaps << endl << "Time Taken to Complete in Seconds: " << (double(duration))/CLOCKS_PER_SEC;
}

void quickSort :: printArray(size_t howBig, size_t array[]){
    for(size_t i = 0; i < howBig; i++){
        cout << array[i] << endl;
    }
}