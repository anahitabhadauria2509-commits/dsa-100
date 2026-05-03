#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
    int count[max + 1];
    memset(count, 0, sizeof(count));
    for (int i = 0; i < n; i++) count[arr[i]]++;
    for (int i = 0, j = 0; i <= max; i++)
        while (count[i]--) arr[j++] = i;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr, 7);
    for(int i=0; i<7; i++) printf("%d ", arr[i]);
    return 0;
}





