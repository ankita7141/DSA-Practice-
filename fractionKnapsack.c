#include<stdio.h>
void knapsack(int n,float weight[],float profit[],float capacity){
    float x[20];
    float totalprofit=0;
    float remaining=capacity;
    int i;
    for(i=0;i<n;i++){
        x[i]=0.0;


    }
    for(i=0;i<n;i++){
        if(weight[i]<=remaining){
            x[i]=1.0;
            totalprofit+=profit[i];
            remaining-=weight[i];
        }
        else{
            x[i]=remaining/profit[i];
            totalprofit+=x[i]*profit[i];
            break;
        }
    }
    printf("result vector\n");
    for(i=0;i<n;i++)
        printf("%f",x[i]);
        printf("totalprofit:%f",totalprofit);

    
}
int main(){
    float weight[20],profit[20],capacity,temp,ratio[20];
    int n,i,j;
    printf("enter num of items:\n");
    scanf("%d",&n);
    printf("enter weight and profit:\n");
    for(i=0;i<n;i++){
        scanf("%f%f",&weight[i],&profit[i]);

    }
    printf("enter capacity\n");
    scanf("%f",&capacity);
    for(i=0;i<n;i++)
        ratio[i]=profit[i]/weight[i];
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                if(ratio[i]<ratio[j]){
                    temp=ratio[i];
                    ratio[i]=ratio[j];
                    ratio[j]=temp;
                     temp=weight[i];
                    weight[i]=weight[j];
                    weight[j]=temp;
                     temp=profit[i];
                    profit[i]=profit[j];
                    profit[j]=temp;

                }
            }
        }
    knapsack(n,weight,profit,capacity);
    return 0;
}