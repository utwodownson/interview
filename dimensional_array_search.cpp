#include <stdio.h>
#include <string.h>

#define MAX 1005

int map[MAX][MAX];

bool find_num(int x, int y, int num) {
    memset(map, 0, sizeof(map));
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            scanf("%d", &map[i][j]);
    int i = 0, j = y - 1;
    while (i >= 0 && i < x && j >= 0 && j < y) {
        if (num < map[i][j]) 
            j = j - 1;
        else if (map[i][j] < num) 
            i = i + 1;
        else
            return true;
    }
    return false;
}


int main()
{
    int x, y, num;
    while (scanf("%d%d", &x, &y) != EOF) {
        scanf("%d", &num);
        if (find_num(x, y, num)) 
            printf("Yes\n");
        else    
            printf("No\n");
    }
}
