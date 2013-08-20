/* There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

int findK(int A[], int m, int B[], int n, int k) {
    while (k > 1 && m > 0 && n > 0) {
        int ka = k * m / (m + n);
        int kb = k * n / (m + n);
        if (ka + kb < k) {
            if (ka < kb) ka++;
            else kb++;
        } 
        if (A[ka - 1] < B[kb - 1]) {
            A += ka;
            m -= ka;
            k -= ka;
            n = kb;
        } else if (B[kb - 1] < A[ka - 1]) {
            B += kb;
            n -= kb;
            k -= kb;
            m = ka;
        } else
            return A[ka - 1];
    }
    if (m > 0 && n > 0) return min(A[0], B[0]);
    else if (m > 0) return A[k - 1];
    else if (n > 0) return B[k - 1];
    else return 0;
}

void findMedianSortedArrays(int A[], int m, int B[], int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int ka = (m + n + 1) / 2, kb = (m + n) / 2 + 1;
    printf("%lf\n", (findK(A, m, B, n, ka) + findK(A, m, B, n, kb)) / 2.0);
}

int main()
{
    int A[] = { 1, 3, 5, 7, 9 };
    int B[] = { 2, 4, 6, 8 };

    int C[] = { 1, 2, 3, 4, 5 };
    int D[] = { 6, 7, 8, 9 };

    int E[] = { 1, 2, 3 };
    int F[] = { 4, 5, 6, 7, 8, 9 };

    int G[] = { 7, 8, 9 };
    int H[] = { 1, 2, 3, 4, 5, 6 };

    findMedianSortedArrays(A, 5, B, 4);
    findMedianSortedArrays(C, 5, D, 4);
    findMedianSortedArrays(E, 3, F, 6);
    findMedianSortedArrays(G, 3, H, 6);
}
