#include <stdio.h>
#include <string.h>

int find_longest(char *a)
{
    int max_half = 0;
    int max = 0;
    int len = strlen(a);
    for (int i = 0; i < len - max_half; ++i) {
        int j, k;
        for (j = i + 1, k = i; k >= 0 && j < len && a[j] == a[k]; j++, k--);
        if (j - k - 1 > max) {
            max = j - k - 1;
            max_half = j - i - 1;
        }
        for (j = i + 1, k = i - 1; k >= 0 && j < len && a[j] == a[k]; j++, k--);
        if (j - k - 1 > max) {
            max = j - k - 1;
            max_half = j - i - 1;
        }
    }
    return max;
}

int main()
{
    char a[200010];
    while (scanf("%s", a) != EOF) 
        printf("%d\n", find_longest(a));
}
