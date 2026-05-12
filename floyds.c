#include <stdio.h>
#define INF 999

int min(int a, int b){
    return (a < b) ? a : b;
}

void floyds_alg(int a[100][100], int n){   // use fixed size or dynamic allocation
    int d[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j] = a[i][j];
        }
    }

    // Floyd–Warshall
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // Print result
    printf("Shortest distance matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(d[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);

    int a[100][100];
    printf("Enter matrix values (use %d for INF):\n", INF);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    floyds_alg(a,n);
    return 0;
}
