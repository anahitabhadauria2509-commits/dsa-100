#include <stdio.h>
#include <stdlib.h>

struct Interval { int s, e; };
int compare(const void* a, const void* b) { return ((struct Interval*)a)->s - ((struct Interval*)b)->s; }

void mergeIntervals(struct Interval arr[], int n) {
    qsort(arr, n, sizeof(struct Interval), compare);
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (arr[index].e >= arr[i].s) {
            if (arr[index].e < arr[i].e) arr[index].e = arr[i].e;
        } else {
            index++;
            arr[index] = arr[i];
        }
    }
    for (int i = 0; i <= index; i++) printf("[%d, %d] ", arr[i].s, arr[i].e);
}

int main() {
    struct Interval arr[] = {{1,3}, {2,4}, {5,7}, {6,8}};
    mergeIntervals(arr, 4);
    return 0;
}





