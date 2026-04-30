#include <stdio.h>

int isFeasible(int arr[], int n, int m, int cur_min) {
    int students = 1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > cur_min) return 0;
        if (sum + arr[i] > cur_min) {
            students++;
            sum = arr[i];
            if (students > m) return 0;
        } else sum += arr[i];
    }
    return 1;
}

int main() {
    int arr[] = {12, 34, 67, 90}, n = 4, m = 2;
    int sum = 0, max = 0;
    for(int i=0; i<n; i++) { sum += arr[i]; if(arr[i]>max) max = arr[i]; }
    int low = max, high = sum, ans = sum;
    while(low <= high) {
        int mid = low + (high-low)/2;
        if(isFeasible(arr, n, m, mid)) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    printf("Min Pages: %d", ans);
    return 0;
}





