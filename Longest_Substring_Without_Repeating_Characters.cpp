#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find_longest(char *a)
{
    bool visit[256];
    memset(visit, false, sizeof(visit));

    int max = 0, i = 0, j = 0;
    while (j < strlen(a)) {
        while (j < strlen(a) && !visit[a[j]])  // forget the j < len
            visit[a[j++]] = true;

        if (max < j - i) 
            max = j - i;

        do {
            visit[a[i]] = false;
        } while (a[i++] != a[j]);
    }
    return max;
}

int main()
{
    char a[10010];
    while (scanf("%s", a) != EOF) 
        printf("%d\n", find_longest(a));
}
