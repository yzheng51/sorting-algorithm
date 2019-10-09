/**
 * @file sort.h
 * @yzheng
 * @sorting algorithm
 * @version 0.1
 * @date 2019-10-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#include <vector>

/* basic sorting algorithm */

void bubbleSort(std::vector<int> &arr);
void insertSort(std::vector<int> &arr);
void selectSort(std::vector<int> &arr);

/* linear time sorting algorithm */

void countSort(std::vector<int> &arr);
void radixSort(std::vector<int> &arr);

/* divide and conquer sorting algorithm */

void mergeSort(std::vector<int> &arr);
void quickSort(std::vector<int> &arr);
void heapSort(std::vector<int> &arr);
