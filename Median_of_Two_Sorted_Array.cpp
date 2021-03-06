/* here are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

long findK(long A[], long m, long B[], long n, long k) {
    while (k > 1 && m > 0 && n > 0) {
        long ka = k * m / (m + n);
        long kb = k * n / (m + n);
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

long findMedianSortedArrays(long A[], long m, long B[], long n) {
    // Start typing your C/C++ solution below
    // DO NOT write long long main() function
    //long long ka = (m + n + 1) / 2, kb = (m + n) / 2 + 1;
    //prlong longf("%lf\n", (findK(A, m, B, n, ka) + findK(A, m, B, n, kb)) / 2.0);
    //return (findK(A, m, B, n, ka) + findK(A, m, B, n, kb)) / 2.0;
    long k = (m + n) / 2 + 1;
    return findK(A, m, B, n, k);
}

int main()
{
    long A[10000], B[10000];
    long m, n;
    scanf("%ld", &m);
    for (int i = 0; i < m; ++i)
        scanf("%ld", &A[i]);
    scanf("%ld", &n);
    for (int i = 0; i < n; ++i)
        scanf("%ld", &B[i]);
    printf("%ld\n", findMedianSortedArrays(A, m, B, n));
    /*
    long long A[] = { 1, 3, 5, 7, 9 };
    long long B[] = { 2, 4, 6, 8 };

    long long C[] = { 1, 2, 3, 4, 5 };
    long long D[] = { 6, 7, 8, 9 };

    long long E[] = { 1, 2, 3 };
    long long F[] = { 4, 5, 6, 7, 8, 9 };

    long long G[] = { 7, 8, 9 };
    long long H[] = { 1, 2, 3, 4, 5, 6 };

    findMedianSortedArrays(A, 5, B, 4);
    findMedianSortedArrays(C, 5, D, 4);
    findMedianSortedArrays(E, 3, F, 6);
    findMedianSortedArrays(G, 3, H, 6);
    */
}
