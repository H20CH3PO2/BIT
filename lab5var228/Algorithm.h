#ifndef ALGORITHM
#define ALGORITHM
// qsort ะตััั
typedef int(*cmp_t)(const void *, const void *);
void heapSort(void* arr, int n, int size, cmp_t cmp);
#endif