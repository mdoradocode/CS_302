#pragma once 

class selectionSort{
    public:
    selectionSort();
    selectionSort(size_t size, size_t array[]);
    void printStats();

    private:
    size_t compares;
    size_t swaps;
    clock_t duration;
};