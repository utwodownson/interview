#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(char *src, int n) {
    printf("the array : ");
    for (int i = 0; i < n; ++i) {
        printf("%d", src[i]);
        if (i != n - 1)
            printf(" ");
    }
}

int main()
{
    int src[] = { 3, 5, 2, 1, 4, 6 };
    //int len = strlen(src);
    int len = 6;
    print(src, len);
}

