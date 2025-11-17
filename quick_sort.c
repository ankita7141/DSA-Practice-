#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int str, int end){
    int i = str - 1;
    int pivot = arr[end];

    for(int j = str; j < end; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[j], &arr[i]);
        }
    }
    

    i++;
    swap(&arr[end], &arr[i]);
    return i;
}

void quick_sort(int arr[], int str, int end){
    if(str < end){
        int pivot_index = partition(arr, str, end);
        quick_sort(arr, str, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, end);
    }
}

int main(){
    int arr[6] = {1, 4, 2, 6, 7, 3};
    int size = 6;

    quick_sort(arr, 0, size - 1);

    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
