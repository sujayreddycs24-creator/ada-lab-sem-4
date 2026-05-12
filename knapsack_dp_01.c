#include <stdio.h>
#include <stdbool.h>

int max(int a,int b){
    return (a > b) ? a : b;
}

int knapsack(int w,int wt[],int val[],int n){
    int dp[n+1][w+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(wt[i-1] <= j){
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int res = dp[n][w];
    int r=w;
    printf("Items selected: ");
    for(int i=n; i>0 && res>0; i--){
        if(res == dp[i-1][r]) {
            // Item i-1 not included
            continue;
        } else {
            // Item i-1 included
            printf("Item%d (val=%d, wt=%d) ", i, val[i-1], wt[i-1]);
            res -= val[i-1];
            r -= wt[i-1];
        }
    }
    printf("\n");
    return dp[n][w];
}

int main(){
    // int val[] = {60, 100, 120};
    // int wt[] = {10, 20, 30};
    // int W = 50;
    // int n = sizeof(val)/sizeof(val[0]);
    int n,w;
    
    printf("Enter value of n");
    scanf("%d",&n);
    printf("Enter value of w");
    scanf("%d",&w);
    int val[n];
    int wt[n];
    for(int i=0;i<n;i++){
        printf("Enter weight and value for %d\n",i+1);
        scanf("%d%d",&wt[i],&val[i]);

    }


    printf("Maximum value in Knapsack = %d\n", knapsack(w, wt, val, n));
    return 0;
}
