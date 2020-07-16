#include <iostream>
#include <fstream>
#include <random>
#include <array>

#include "bubbleSort.h"
#include "selectionSort.h"
#include "quickSort.h"

using namespace std;

void createFile(size_t howBig);
void writeArray(size_t array[], size_t howBig, string File);
void arrayToFile(size_t array[], size_t howBig);
void printArray(size_t howBig, size_t array[]);
void sortArrays(size_t bArray[], size_t sArray[], size_t qArray[], size_t howBig);
void printArrayStats(selectionSort sSort, bubbleSort bSort, quickSort qSort);


int main(){
    string fileName;
    int fileSize;
    int bestOrWorst;
    cout << "How many inputs would you like: Enter 1 for 1000, 2 for 10000, or 3 for 100000" << endl;
    cin >> fileSize;
    cout << "Would you like best case or worst case? Enter 1 for worst and 2 for best" << endl;
    cin >> bestOrWorst;
    size_t howBig;
    switch(fileSize){
        case 1:  howBig = 1000;
                    break;

        case 2: howBig = 10000;
                    break;

        case 3: howBig = 100000;
                    break;
    }
    size_t array[howBig];
    if(fileSize == 1&& bestOrWorst ==1){
        fileName = "Random Numbers1000Unsorted.txt";
    }
    if(fileSize == 2 && bestOrWorst == 1){
        fileName = "Random Numbers10000Unsorted.txt";
    }
    if(fileSize == 3 && bestOrWorst == 1){
        fileName = "Random Numbers100000Unsorted.txt";
    }
    if(fileSize == 1&& bestOrWorst ==2){
    fileName = "Random Numbers1000Sorted.txt";
    }
    if(fileSize == 2 && bestOrWorst == 2){
    fileName = "Random Numbers10000Sorted.txt";
    }
    if(fileSize == 3 && bestOrWorst == 2){
    fileName = "Random Numbers100000Sorted.txt";
}
    cout << "Bubble Sort: " << endl;
    writeArray(array, howBig, fileName);
    bubbleSort bSort(howBig, array);
    bSort.printStats();
    cout << endl << endl;

 
    cout << "Selection Sort: " << endl;
    writeArray(array, howBig, fileName);
    selectionSort sSort(howBig, array);
    sSort.printStats();
    cout << endl << endl;
    
    cout << "Quick Sort: " << endl;
    writeArray(array, howBig, fileName);
    quickSort qSort(howBig, array);
    qSort.printStats();
    cout << endl << endl;

    
    
    

}

void createFile(size_t howBig){
    ofstream oFile;
    oFile.open("Random Numbers.txt");
    random_device number; //God, I love the ability to use built in functions, thank you Erin
    mt19937 processor(number()); //seed the engine
    uniform_int_distribution<> distr(0,1000000); // get the number in a range
    for(size_t i = 0; i < howBig; i++){
        size_t holder = distr(processor); //Random Number generation
        oFile << holder << ' ';
    }
    oFile.close();
}

void writeArray(size_t array[], size_t howBig, string File){
    ifstream iFile;
    iFile.open(File);
    for(size_t i = 0; i < howBig; i++){
        iFile >> array[i];
    }
    iFile.close();
}

void arrayToFile(size_t array[], size_t howBig){
    ofstream oFile; 
    oFile.open("Random Numbers.txt");
    for(size_t i = 0; i < howBig; i++){
        size_t holder = array[i];
        oFile << holder << ' ';
    }
    oFile.close();
}
void printArray(size_t howBig, size_t array[]){
    for(size_t i = 0; i < howBig; i++){
        cout << array[i] << endl;
    }
}

void sortArrays(size_t bArray[], size_t sArray[], size_t qArray[], size_t howBig){
    bubbleSort bSort(howBig, bArray);
    selectionSort sSort(howBig, sArray);
    quickSort qSort(howBig, qArray);
}

void printArrayStats(selectionSort sSort, bubbleSort bSort, quickSort qSort){

}