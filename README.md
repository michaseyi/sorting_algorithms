### Sorting algorithms and their time complexity

---

| Sorting Algorithm                                                                                          | Worst Case Time Complexity | Average Case Time Complexity | Best Case Time Complexity |
| ---------------------------------------------------------------------------------------------------------- | -------------------------- | ---------------------------- | ------------------------- |
| [Bubble sort](0-bubble_sort.c)                                                                             | O(n^2)                     | O(n^2)                       | O(n)                      |
| [Insertion sort](1-insertion_sort_list.c)                                                                  | O(n^2)                     | O(n^2)                       | O(n)                      |
| [Selection sort](2-selection_sort.c)                                                                       | O(n^2)                     | O(n^2)                       | O(n^2)                    |
| [Quick sort](3-quick_sort.c) using `lumoto` partition                                                      | O(n^2)                     | O(nlog(n))                   | O(nlog(n))                |
| [Shell sort](100-shell_sort.c) using the [Knuth](https://en.wikipedia.org/wiki/Shellsort "Knuth") sequence |                            |                              |                           |
| [Cocktail-shaker sort](101-cocktail_sort_list.c)                                                           | O(n^2)                     | O(n^2)                       | O(n)                      |
| [Counting sort](102-counting_sort.c). `k` is the maximum number + 1                                        | O(n+k)                     | O(n+k)                       | O(n+k)                    |
| [Merge sort](103-merge_sort.c)                                                                             | O(log(n))                  | O(nlog(n))                   | O(nlog(n))                |
| [Heap sort](104-heap_sort.c)                                                                               | O(nlog(n))                 | O(nlog(n))                   | O(nlog(n))                |
| [Radix sort](105-radix_sort.c). `d` is the length of the maximum number                                    | O(d\*n)                    | O(d\*n)                      | O(d\*n)                   |
| Bitonic sort                                                                                               |                            |                              |                           |
| [Quick sort](107-quick_sort_hoare.c) using `hoare` partition                                               | O(n^2)                     | O(nlog(n))                   | O(nlog(n))                |
