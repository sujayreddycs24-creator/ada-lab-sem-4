#include <stdio.h>

double horners(int arr[],int x,int n){
    double result=arr[0];
    for( int i=1;i<n;i++){
        result= result*x + arr[i];
    }
    return result;
}                                         
int main(){
    int arr[]={1,3,1,5,-1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x;
    printf("Enter x value to compute:");
    scanf("%d", &x);
    double result=horners(arr,x,n);
    printf("The result at point %d is %.2f",x,result);
    return 0;

}