/**
 * @file sort.cpp
 * @yzheng
 * @implementation of sorting algorithm
 * @version 0.1
 * @date 2019-10-03
 *
 * @copyright Copyright (c) 2019
 *
 */
#include "sort.h"
#include <random>

inline void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

inline int leftChild(int i) {
    return (i << 1) + 1;
}

inline int rightChild(int i) {
    return (i << 1) + 2;
}

void bubbleSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    int n = arr.size();
    for (int i = 0; i != n - 1; ++i) {
        for (int j = 0; j != n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    int n = arr.size();
    for (int i = 0; i != n - 1; ++i) {
        for (int j = i + 1; j != 0; --j) {
            if (arr[j - 1] > arr[j]) {
                swap(arr[j - 1], arr[j]);
            } else {
                break;
            }
        }
    }
}

void selectSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    int n = arr.size();
    for (int i = 0; i != n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j != n; ++j) {
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void countSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    int n = arr.size();
    int minNum = arr[0];
    int maxNum = arr[0];
    int countSize;
    for (auto num : arr) {
        maxNum = (maxNum < num) ? num : maxNum;
        minNum = (minNum > num) ? num : minNum;
    }
    countSize = maxNum - minNum + 1;
    std::vector<int> temp(arr);
    std::vector<int> counting(countSize);
    for (int i = 0; i != n; ++i) {
        counting[arr[i] - minNum]++;
    }
    for (int i = 1; i != countSize; ++i) {
        counting[i] += counting[i - 1];
    }
    for (int i = n - 1; i >= 0; --i) {
        arr[counting[temp[i] - minNum]-- - 1] = temp[i];
    }
}

void radixSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    int n = arr.size();
    int maxNum = arr[0];
    std::vector<std::vector<int>> bucket(10);
    for (auto num : arr) {
        maxNum = (maxNum < num) ? num : maxNum;
    }
    for (int mod = 10, div = 1; maxNum != 0; mod *= 10, div *= 10, maxNum /= 10) {
        for (int i = 0; i < n; ++i) {
            int num = (arr[i] % mod) / div;
            bucket[num].push_back(arr[i]);
        }
        int idx = 0;
        for (int i = 0; i < 10; ++i) {
            int size = bucket[i].size();
            for (int j = 0; j < size; ++j) {
                arr[idx++] = bucket[i][j];
            }
            bucket[i].clear();
        }
    }
}

/* ----------------------------------- merge sort -----------------------------------*/

void merge(std::vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int i = 0, j = 0;
    std::vector<int> temp_left, temp_right;

    for (int i = 0; i != n1; ++i) {
        temp_left.push_back(arr[left + i]);
    }
    for (int j = 0; j != n2; ++j) {
        temp_right.push_back(arr[mid + 1 + j]);
    }
    while (i != n1 && j != n2) {
        if (temp_left[i] < temp_right[j]) {
            arr[left++] = temp_left[i++];
        } else {
            arr[left++] = temp_right[j++];
        }
    }
    while (i != n1) {
        arr[left++] = temp_left[i++];
    }
    while (j != n2) {
        arr[left++] = temp_right[j++];
    }
}

void mergeSortHelper(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    mergeSortHelper(arr, 0, arr.size() - 1);
}

/* ----------------------------------- quick sort -----------------------------------*/

int partition(std::vector<int> &arr, int left, int right) {
    std::uniform_int_distribution<int> u(left, right);
    std::default_random_engine e;
    swap(arr[u(e)], arr[right]);
    int target = arr[right];
    int i = left - 1;
    for (int j = left; j != right; ++j) {
        if (arr[j] <= target) {
            swap(arr[++i], arr[j]);
        }
    }
    swap(arr[++i], arr[right]);
    return i;
}

void quickSortHelper(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        int q = partition(arr, left, right);
        quickSortHelper(arr, left, q - 1);
        quickSortHelper(arr, q + 1, right);
    }
}

void quickSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    quickSortHelper(arr, 0, arr.size() - 1);
}

/* ----------------------------------- heap sort -----------------------------------*/

void maxHeapify(std::vector<int> &arr, int idx, int n) {
    int left = leftChild(idx);
    int right = rightChild(idx);
    int largest = idx;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != idx) {
        swap(arr[largest], arr[idx]);
        maxHeapify(arr, largest, n);
    }
}

void heapSort(std::vector<int> &arr) {
    if (arr.empty()) {
        return;
    }
    int n = arr.size();
    for (int i = n / 2; i >= 0; --i) {
        maxHeapify(arr, i, n);
    }
    for (int i = n - 1; i >= 0; --i) {
        swap(arr[0], arr[i]);
        maxHeapify(arr, 0, i);
    }
}
