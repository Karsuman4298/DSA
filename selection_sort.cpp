

#include<stdio.h>


void selection_sort(int arr[],int n) {
    int i,j,min,temp;

    for(int i=0;i<n-1;i++) {
        min =i;
        for(j=i+1;j<n;j++) {
            if(arr[j]<arr[min]) {
               min=j;
            }
        }

        if(min != i) {
            temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

}

void print_arr(int arr[],int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }

}

int main() {

    int arr[]={3,2,1,5,9};
    int n= sizeof(arr)/sizeof(arr[0]);

    printf("\n array before sorting : \n");
    print_arr(arr,n);

    selection_sort(arr,n);

    printf("\n array after sorting : \n");
    print_arr(arr,n);

}

/*  array before sorting :
    3 2 1 5 9
    array after sorting :
    1 2 3 5 9              */


