#include <stdio.h>
#include <string.h>
#include <stdlib.h>

long long count = 0;

void merge(int *num, int left, int mid, int right)
{
    int *temp = (int *) malloc(sizeof(int) * (right - left + 1));
    int i = left, j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (num[i] <= num[j]) 
            temp[k++] = num[i++];
        else {
            temp[k++] = num[j++];
            count += mid - i + 1; // num[i] > num[j] 那么i 到 mid都比j大，逆序数是mid - i + 1
        }
    }

    while (i <= mid) 
        temp[k++] = num[i++];
    while (j <= right) 
        temp[k++] = num[j++];
    for (int p = 0; p < k; ++p)
        num[left + p] = temp[p];
}

void mergesort(int *num, int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergesort(num, left, mid);
        mergesort(num, mid + 1, right);
        merge(num, left, mid, right);
    }
}

int main()
{
    int n;
    int num[100100];
    while (scanf("%d", &n) != EOF) {
        count = 0;
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; ++i) 
            scanf("%d", &num[i]);
        mergesort(num, 0, n - 1);
        printf("%lld\n", count);
    }
}
