# Sorting Algorithm

## Complexity

This repo covers 8 sorting algorithms and folowing table shows the time complexity and space complexity.

| Algorithm  |   Average case |      Best case |     Worst case |      Space complexity | Stability |
| ---------- | -------------: | -------------: | -------------: | --------------------: | --------: |
| BubbleSort |       $O(n^2)$ |       $O(n^2)$ |       $O(n^2)$ |                $O(1)$ |    Stable |
| InsertSort |       $O(n^2)$ |         $O(n)$ |       $O(n^2)$ |                $O(1)$ |    Stable |
| SelectSort |       $O(n^2)$ |       $O(n^2)$ |       $O(n^2)$ |                $O(1)$ |  Unstable |
| MergeSort  |  $O(n\log{n})$ |  $O(n\log{n})$ |  $O(n\log{n})$ |                $O(n)$ |    Stable |
| QuickSort  |  $O(n\log{n})$ |  $O(n\log{n})$ |       $O(n^2)$ | $O(\log{n})$ - $O(n)$ |  Unstable |
| HeapSort   |  $O(n\log{n})$ |  $O(n\log{n})$ |  $O(n\log{n})$ |                $O(1)$ |  Unstable |
| CountSort  |       $O(n+k)$ |       $O(n+k)$ |       $O(n+k)$ |              $O(n+k)$ |    Stable |
| RadixSort  | $O(n\times k)$ | $O(n\times k)$ | $O(n\times k)$ |              $O(n+k)$ |    Stable |

## Benchmark

Following table shows the benchmark of a random generated array $a_n\in[0, 2^{31})$ and $n$ is the size of the $a_n$

| Algorithm  | $n=10^3$ | $n=10^4$ | $n=10^5$ | $n=10^6$ | $n=10^7$ | $n=10^8$ | $n=10^9$ |
| ---------- | -------: | -------: | -------: | -------: | -------: | -------: | -------: |
| BubbleSort |    0.000 |    0.102 |   12.454 | 1257.439 |        / |        / |        / |
| InsertSort |    0.001 |    0.034 |    2.986 |  300.183 |        / |        / |        / |
| SelectSort |    0.000 |    0.028 |    2.575 |  256.156 |        / |        / |        / |
| MergeSort  |    0.000 |    0.004 |    0.039 |    0.368 |    4.186 |   42.702 |  440.231 |
| QuickSort  |    0.000 |    0.000 |    0.007 |    0.078 |    0.893 |    9.899 |  107.552 |
| HeapSort   |    0.000 |    0.001 |    0.007 |    0.120 |    3.295 |   69.678 | 1256.327 |
| CountSort  |    7.541 |    6.898 |    6.924 |    8.112 |    9.409 |   31.252 |        / |
| RadixSort  |    0.000 |    0.000 |    0.008 |    0.066 |    0.638 |    6.432 |        / |

Since bubble sort, insertion sort and selection sort are much slower than other sorting algorithms, there is no test on them. Counting sort and radix sort require too much memory when $n=10^9$, so there is no data for them too. To verify the advantage of linear time sorting algorithm, another test limits the range of $a_n\in[0, 10^{4})$ and the results is shown below.

| Algorithm | $n=10^3$ | $n=10^4$ | $n=10^5$ | $n=10^6$ | $n=10^7$ | $n=10^8$ |
| --------- | -------: | -------: | -------: | -------: | -------: | -------: |
| MergeSort |    0.003 |    0.006 |    0.036 |    0.360 |    3.969 |   39.222 |
| QuickSort |    0.000 |    0.000 |    0.006 |    0.114 |    5.471 |  491.028 |
| HeapSort  |    0.000 |    0.000 |    0.009 |    0.108 |    2.554 |   48.310 |
| CountSort |    0.000 |    0.000 |    0.000 |    0.006 |    0.102 |    1.323 |
| RadixSort |    0.000 |    0.000 |    0.006 |    0.036 |    0.355 |    3.494 |