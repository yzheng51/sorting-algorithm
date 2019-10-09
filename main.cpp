#include <chrono>
#include <iomanip>
#include <iostream>
#include <random>
#include "sort.h"

const int tabWidth = 12;  // control the width of output table
const int N_MIN = 1e3;
const int N_MAX = 1e5;

void timing(void (*sortFunc)(std::vector<int> &), std::vector<int> arr);
void test(void (*sortFunc)(std::vector<int> &), std::vector<int> &arr);

int main(int argc, char const *argv[]) {
    std::uniform_int_distribution<int> u(0, INT_MAX);
    std::default_random_engine e;

    // table format
    std::cout << std::left;
    std::cout << std::setw(tabWidth) << "Array Size"
              << std::setw(tabWidth) << "BubbleSort"
              << std::setw(tabWidth) << "InsertSort"
              << std::setw(tabWidth) << "SelectSort"
              << std::setw(tabWidth) << "MergeSort"
              << std::setw(tabWidth) << "QuickSort"
              << std::setw(tabWidth) << "HeapSort"
              << std::setw(tabWidth) << "CountSort"
              << std::setw(tabWidth) << "RadixSort" << std::endl;
    std::cout << "---------------------------"
              << "---------------------------"
              << "---------------------------"
              << "---------------------------" << std::endl;

    // run sorting algorithm with each array size
    for (int N = N_MIN; N <= N_MAX; N *= 10) {
        std::vector<int> arr;
        arr.reserve(N);
        for (int i = 0; i != N; ++i) {
            arr.push_back(u(e));
        }

        std::cout << "N=" << std::setw(tabWidth) << N;
        timing(bubbleSort, arr);
        timing(insertSort, arr);
        timing(selectSort, arr);
        timing(mergeSort, arr);
        timing(quickSort, arr);
        timing(heapSort, arr);
        timing(countSort, arr);
        timing(radixSort, arr);
        std::cout << std::endl;
    }

    // test the sorting algorithm
    // std::vector<int> arr{9, -2, 5, 6, -18, 7, 16, 10, 19, -2, -7, 29, -8, -11, 13, 9, 73, 4, -6, 1};
    // std::vector<int> arr{3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48};
    // test(heapSort, arr);
    return 0;
}

/**
 * @a function to compute the sorting time of passed-in function sortFunc
 *
 * @param sortFunc - a user-defined function which can be inserSort, quickSort, etc
 * @param arr - this function will make a copy of input array since only time is considered
 */
void timing(void (*sortFunc)(std::vector<int> &), std::vector<int> arr) {
    std::vector<int> temp(arr);
    auto start = std::chrono::system_clock::now();
    sortFunc(temp);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << std::setiosflags(std::ios::fixed)
              << std::setprecision(3);                    // set precision
    std::cout << std::setw(tabWidth) << elapsed.count();  // print time in seconds
}

/**
 * @a function to test the correctness of the sorting algorithm
 *
 * @param sortFunc - a user-defined function which can be inserSort, quickSort, etc
 * @param arr - input array
 */
void test(void (*sortFunc)(std::vector<int> &), std::vector<int> &arr) {
    std::cout << "Input array is: ";
    for (auto num : arr) {
        std::cout << num << " ";
    }
    sortFunc(arr);
    std::cout << std::endl
              << "Sorted array is: ";
    for (auto num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}
