#include <stdio.h>

void merge(int arr[], int str, int mid, int end) {
    int n1 = mid - str + 1;
    int n2 = end - mid;

    int left[n1], right[n2];

    for(int i = 0; i < n1; i++)
        left[i] = arr[str + i];
    for(int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = str;

    while(i < n1 && j < n2) {
        if(left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while(i < n1) {
        arr[k++] = left[i++];
    }

    while(j < n2) {
        arr[k++] = right[j++];
    }
}

void merge_sort(int arr[], int str, int end) {
    if(str < end) {
        int mid = str + (end - str) / 2;
        merge_sort(arr, str, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, str, mid, end);
    }
}

int main() {
    int arr[6] = {1, 4, 2, 6, 7, 3};
    int size = 6;

    merge_sort(arr, 0, size - 1);

    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
