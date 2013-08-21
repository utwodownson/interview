#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    char s[100005];
    while (scanf("%d", &n) != EOF) {
        memset(s, 0, sizeof(s));
        gets(s);
        gets(s);
        int i = 0, j = 0, k = 0;
        while (k < n) {
            i = k;
            while (k < n && s[k] != ' ') ++k;
            for (j = k - 1; j >= i; --j)
                putchar(s[j]);
            if (k < n) 
                putchar(s[k]);
            while (k < n && s[k] == ' ') ++k;
        }
        puts("");
    }
}
