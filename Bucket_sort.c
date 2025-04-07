#include<stdio.h>


void bucket_sort(int arr[], int n) {
    int range=100;
    int buckets[100]={0};
    for(int i=0;i<n;i++) {
        buckets[arr[i]]++;
    }

    int index =0;
    for(int i=0;i<range;i++) {
        while(buckets[i]>0) {
            arr[index++]=i;
            buckets[i]--;
        }
    }
}

void print_arr(int arr[],int n) {

    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }
}


int main() {
    int arr[]={34,2,67,66,45};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting \n");
    print_arr(arr,n);
    bucket_sort(arr,n);
    printf("\nArray after sorting\n");
    print_arr(arr,n);

}

/*  OUTPUT:
Array before sorting
34 2 67 66 45
Array after sorting
2 34 45 66 67
               */

