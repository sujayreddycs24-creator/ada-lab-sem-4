#include <stdio.h>

typedef struct{
    int weight;
    int value;
    float ratio;

} item;

void sort(item a[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].ratio<a[j].ratio){
                item max=a[j];
                a[j]=a[i];
                a[i]=max;
            }
        }
    }
}

float fractional_knapsack(item a[],int capacity, int n){
    sort(a,n);
    float total_value=0.0;
    for(int i=0;i<n;i++){
        if(capacity>=a[i].weight){
            capacity=capacity-a[i].weight;
            total_value+=a[i].value;
            printf("Added %d value:%d weight:%d\n",i+1,a[i].value,a[i].weight);
        }
        else{
            float fraction=((float)capacity/a[i].weight)*a[i].value;
            total_value+=fraction;
            printf("Added %d value:%f fraction of weight:%f\n",i+1,fraction,((float)capacity/a[i].weight));
            break;
        }
    }
    return total_value;
}

int main(){
    int n;
    printf("enter n");
    scanf("%d",&n);
    item a[n];
    int capacity;
    printf("Enter capacity:");
    scanf("%d",&capacity);
    printf("Enter value, weight for:\n");
    for(int i=0;i<n;i++){
        printf("%d:",i+1);
        scanf("%d %d",&a[i].value,&a[i].weight);
        a[i].ratio=(float)a[i].value/a[i].weight;
    }
    float result=fractional_knapsack(a,capacity,n);
    printf("Total profit: %f",result);

    return 0;
}
