#include <stdio.h>
#include <string.h>

int head[1000];

struct node
{
    int to;
    int w;
    int next;
};

node Edge[2000];

int cnt = 0;
void addEdge(int from, int to)
{
    Edge[cnt].to = to;
    Edge[cnt].next = head[from];
    head[from] = cnt++;
}


void dfs(int j)
{
    
}

int main()
{
    memset(head, -1, sizeof(head));
}
