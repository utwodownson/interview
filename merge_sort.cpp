#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(int *src, int n);

void merge(int *src, int left, int mid, int right) {
    int k = 0, i = left, j = mid + 1;
    int n = right - left + 1;
    int *temp = (int *) malloc(sizeof(int) * n);
    if (temp == NULL) // forget
        return;

    while (i <= mid && j <= right) 
        temp[k++] = src[i] <= src[j] ? src[i++] : src[j++];
    while (i <= mid)
        temp[k++] = src[i++];
    while (j <= right)
        temp[k++] = src[j++];
    for (int p = 0; p < k; ++p)
        src[left + p] = temp[p];

    if (temp != NULL)
        free(temp);
}

void mergesort(int *src, int left, int right) {
    if (left < right) {
        int mid = left + ((right - left) >> 1);
        mergesort(src, left, mid);
        mergesort(src, mid + 1, right);
        merge(src, left, mid, right);
    }
}

int main()
{
    int src[6] = { 3, 5, 2, 1, 4, 6 };
    int len = 6; 
    print(src, len);
    mergesort(src, 0, len - 1);
    print(src, len);
}

void print(int *src, int n)
{
    printf("the array : ");
    for (int i = 0; i < n; ++i) {
        printf("%d", src[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}

