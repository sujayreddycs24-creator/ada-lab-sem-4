#include <stdio.h>

void prim(int n,int a[5][5]){
    int sum=0;
    int k=0;
    int t[n][3],visited[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    visited[0]=1;
    while(k<n-1){
        int min=999;
        int u;
        int v;
        for(int i=0;i<n;i++){
            if(visited[i]==1){
                for(int j=0;j<n;j++){
                    if(visited[j]==0 && a[i][j]<min){
                        if(a[i][j]!=0){
                            min =a[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }
        t[k][0]=u;
        t[k][1]=v;
        t[k][2]=a[u][v];
        visited[v] = 1; 
        k++;
        sum+=min;
        
    }
    printf("spanning tree edges\n");
    for(int i=0;i<n-1;i++){
        printf("edge from %d to %d weight: %d\n",t[i][0],t[i][1],t[i][2]);
    }
    printf("MST weight %d",sum);
}


int main() {

    int graph[5][5] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    prim(5,graph);
}