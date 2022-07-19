### Sorting algorithms and their time complexity

---

| Sorting Algorithm                                                                      | Worst Case Time Complexity | Best Case Time Complexity | Best Case Time Complexity |
| -------------------------------------------------------------------------------------- | -------------------------- | ------------------------- | ------------------------- |
| Bubble sort                                                                            | O(n^2)                     | O(n^2)                    | O(n)                      |
| Insertion sort                                                                         | O(n^2)                     | O(n^2)                    | O(n)                      |
| Selection sort                                                                         | O(n^2)                     | O(n^2)                    | O(n^2)                    |
| Quick sort using `lumoto` partition                                                    | O(n^2)                     | O(nlog(n))                | O(nlog(n))                |
| Shell sort using the [Knuth](https://en.wikipedia.org/wiki/Shellsort "Knuth") sequence |                            |                           |
| Counting sort. `k` is the maximum number + 1                                           | O(n+k)                     | O(n+k)                    | O(n+k)                    |
| Merge sort                                                                             | O(log(n))                  | O(nlog(n))                | O(nlog(n))                |
| Heap sort                                                                              | O(nlog(n))                 | O(nlog(n))                | O(nlog(n))                |
| Radix sort. `d` is the length of the maximum number                                    | O(d\*n)                    | O(d\*n)                   | O(d\*n)                   |
| Bitonic sort                                                                           |                            |                           |                           |
| Quick sort using `hoare` partition                                                     | O(n^2)                     | O(nlog(n))                | O(nlog(n))                |
