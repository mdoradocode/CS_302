#pragma once

class bubbleSort{
    public:
    bubbleSort();
    bubbleSort(size_t size, size_t array[]);
    bool compare(size_t a, size_t b);
    void printStats();
    private:
    size_t swaps;
    size_t compares;
    clock_t duration;
};
