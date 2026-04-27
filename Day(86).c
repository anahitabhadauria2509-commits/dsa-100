#include <stdio.h>

long long floorSqrt(long long x) {
    if (x == 0 || x == 1) return x;
    long long start = 1, end = x, ans;
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        if (mid * mid == x) return mid;
        if (mid * mid < x) { start = mid + 1; ans = mid; }
        else end = mid - 1;
    }
    return ans;
}

int main() {
    printf("Sqrt of 11: %lld", floorSqrt(11));
    return 0;
}





