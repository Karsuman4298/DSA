#include<stdio.h>

void swap(int* a,int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify(int arr[],int n,int i) {
    int largest=i;
    int left= 2*i +1;
    int right= 2*i+2;

    if(left<n && arr[left]>arr[largest]) {
        largest= left;
    }

    if(right<n && arr[right]>arr[largest]) {
        largest=right;

    }


    if(largest != i) {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}


void heap_sort(int arr[], int n) {

    for(int i= n/2 -1;i>=0;i--) {
        heapify(arr,n,i);

        for(int i=n-1;i>0;i--) {
            swap(&arr[0],&arr[i]);

            heapify(arr,i,0);
        }
    }
}

   void print_arr(int arr[],int n) {
    for(int i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
}


int main() {
    int arr[]={34,2,67,66,45};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Array before sorting \n");
    print_arr(arr,n);
    heap_sort(arr,n);
    printf("\nArray after sorting\n");
    print_arr(arr,n);

}
