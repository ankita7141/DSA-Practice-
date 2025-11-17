#include<stdio.h>
void merge(int arr[],int l,int m,int r){
    int i=l,j=m+1,k=0;
    int temp[r-l+1];
    // Merging the two halves into temp[]
    while(i<=m && j<=r){
        if (arr[i]<arr[j]){
            temp[k++]=arr[i++];

        }
        else{
            temp[k++]=arr[j++];

        }
    }
    // Copying remaining elements 
    while(i<=m){
        temp[k++]=arr[i++];
    }
    while(j<=r){
        temp[k++]=arr[j++];
    }
    // Copying back to original array
    for(i=l,k=0;i<=r;i++,k++){
        arr[i]=temp[k];
    }
}
    void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);//left half
        mergeSort(arr,m+1,r);//right half
        merge(arr,l,m,r);//merging
    }
}

int main(){
    int arr[100],n,i;
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,1,n);
    printf("Sorted array:\n");
    for(i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}