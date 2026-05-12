#include <stdio.h>
#include <stdbool.h>
#define rtl 1
#define ltr 0

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int searchArr(int a[],int n, int mobile){
    for(int i=0;i<n;i++){
        if(a[i]==mobile){
            return i;
        }
    }
}

int getMobile(int a[],int dir[],int n){
    int mobile_prev=0;
    int mobile=0;
    for(int i=0;i<n;i++){
        if(dir[a[i]-1]==rtl && i!=0){
            if(a[i]>a[i-1]&&a[i]>mobile_prev){
                mobile=a[i];
                mobile_prev=mobile;
            }
        }
        if(dir[a[i]-1]==ltr && i!=n-1){
            if(a[i]>a[i+1]&&a[i]>mobile_prev){
                mobile=a[i];
                mobile_prev=mobile;
            }
        }
    }
    if( mobile ==0 && mobile_prev==0){
        return 0;
    }
    else{
        return mobile;
    }

}
int printOneperm(int a[], int dir[], int n){
    int mobile = getMobile(a, dir, n);
    int pos = searchArr(a, n, mobile);

    if(dir[a[pos]-1] == rtl && pos > 0){
        swap(&a[pos], &a[pos-1]);
    }
    else if(dir[a[pos]-1] == ltr && pos < n-1){
        swap(&a[pos], &a[pos+1]);
    }

    for(int i=0; i<n; i++){
        if(a[i] > mobile){
            dir[a[i]-1] = (dir[a[i]-1] == ltr ? rtl : ltr);
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int fact(int n){
        int res=1;
        for(int i=1;i<=n;i++) res*=i;
        return res;
    }
void printPermuation(int n){
    int a[n];
    int dir[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
        printf("%d",a[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        dir[i]=rtl;
    }
    for(int i=1;i<fact(n);i++){
        printOneperm(a,dir,n);
    }
}

int main(){
    printPermuation(3);
    return 0;
}