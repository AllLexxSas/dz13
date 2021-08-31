#include <stdio.h>
const int n = 6;

int matrix[n][n] = {
    {0,1,1,0,0,0},
    {0,0,0,1,1,1},
    {0,0,0,0,0,1},
    {1,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,0,1,0},
};

int vis[n] = {0};

void depth_travers(int st)
{
    int r;
    printf("%d",st);
    vis[st] = 1;
    for(r = 0; r<n; ++r)
    {
        if(matrix[st][r] == 1 && !vis[r])
        depth_travers(r);
    }
}

int main()
{
    depth_travers(0);
    return 0;
}
