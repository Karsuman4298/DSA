#include<stdio.h>


void bubble_sort(int arr[],int n) {
    int i,j,temp;

    for(int i=0;i<n-1;i++) {

        for(j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

            }
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

    bubble_sort(arr,n);

    printf("\n array after sorting : \n");
    print_arr(arr,n);

}


/*    array before sorting :
3 2 1 5 9
 array after sorting :
1 2 3 5 9   */




