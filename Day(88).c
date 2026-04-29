#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int isPossible(int stalls[], int n, int k, int dist) {
    int count = 1, last = stalls[0];
    for (int i = 1; i < n; i++) {
        if (stalls[i] - last >= dist) {
            count++;
            last = stalls[i];
        }
    }
    return count >= k;
}

int main() {
    int stalls[] = {1, 2, 8, 4, 9}, n = 5, k = 3;
    qsort(stalls, n, sizeof(int), compare);
    int low = 1, high = stalls[n-1] - stalls[0], ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, n, k, mid)) { ans = mid; low = mid + 1; }
        else high = mid - 1;
    }
    printf("Max Min Distance: %d", ans);
    return 0;
}





