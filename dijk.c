#include <stdio.h>
#define n 5
#define inf 999

void dijkstra(int cost[n][n],int src){
    int dis[n];
    int vis[n];
    for(int i=0;i<n;i++){
        dis[i]=cost[src][i];
        vis[i]=0;

    }
    dis[src]=0;
    vis[src]=1;
    for(int i=1;i<n;i++){
        int min=inf;
        int u=-1;
        for(int j=0;j<n;j++){
            if(vis[j]==0 && dis[j]<min){
                min=dis[j];
                u=j;
            }
        }
        if(u==-1){
            break;
        }
        vis[u]=1;
        for(int j=0;j<n;j++){
            if(vis[j]==0 && dis[u]+cost[u][j]<dis[j]){
                dis[j]=dis[u]+cost[u][j];
            }
        }
    }
    printf("distance from:\n");
    for(int i=0;i<n;i++){
        printf("%d to %d = %d\n",src,i,dis[i]);
    }
}
int main(){
    int graph[5][5] = {
        {0,2,inf,6,inf},
        {2,0,3,8,5},
        {inf,3,0,inf,7},
        {6,8,inf,0,9},
        {inf,5,7,9,0}
    };

    dijkstra(graph,0);
    return 0;
}