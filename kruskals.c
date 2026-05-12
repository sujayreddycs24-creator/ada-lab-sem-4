#include <stdio.h>

int find(int v,int parent[5]){
    while(parent[v]!=v){
        v=parent[v];
    }
    return v;
}

int unionSets (int i,int j,int parent[5])
{
    if(i<j){
        parent[i]=i;
    }
    else{
        parent[i]=j;
    }
}

void kruskal(int n,int a[5][5]){
    int count=0;
    int sum=0;
    int k=0;
    int t[n][3],parent[n];
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    while(count!=n-1){
        int min=999;
        int u=-1,v=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]<min && a[i][j]!=0){
                    min=a[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        int c=find(u,parent);
        int d=find(v,parent);
        if(c!=d){
            unionSets (c,d,parent);
            t[k][0]=u;
            t[k][1]=v;
            t[k][2]=a[u][v];
            k++;
            sum+=min;
            count++;
            }
        a[u][v]=a[v][u]=999;
        }
        if(count==n-1){
            printf("Spanning tree edges from\n");
            for(int i=0;i<k;i++){
                printf("%d to %d weight: %d\n",t[i][0],t[i][1],t[i][2]);
                
            }
            printf("MST weight: %d",sum);
        }
}

int main(){
    int graph[5][5] = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };

    kruskal(5,graph);
}