#pragma once

class quickSort{
    public:
    quickSort();
    quickSort(size_t size, size_t array[]);
    void sortQuickly(size_t low, size_t high, size_t array[]);
    size_t partition(size_t low, size_t high, size_t array[]);
    void printArray(size_t size, size_t array[]);
    void printStats();

    private:
    size_t swaps;
    size_t compares;
    clock_t duration;
};