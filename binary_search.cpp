#include <stdio.h>

// j = n - 1 >> while (i <= j) j = mid - 1
// j = n >> while (i < j) j = mid

int binary_search(int *a, int n, int num) 
{
    int i = 0, j = n - 1, mid = 0; 
    while (i <= j) {
        mid = i + (j - i) / 2;
        if (num < a[mid])
            j = mid - 1;
        else if (a[mid] < num)
            i = mid + 1;
        else
            return mid;
    }
    return i;
}

int main()
{
    // int a[] = { 5, 3, 1, 2, 9, 0, 4, 7, 8, 6 };
    int a[] = { 1, 2, 3, 4, 6, 7, 8, 10, 11, 15 };
    int n = 10, num = 0;
    while (scanf("%d", &num) != EOF) {
        for (int i = 0; i < n; ++i) 
            printf("%d ", i);
        printf("\n");
        for (int i = 0; i < n; ++i) 
            printf("%d ", a[i]);
        printf("\n");
        printf("find the num in %d\n", binary_search(a, n, num)); 
    }
}
