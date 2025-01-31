#include <iostream>

int split(int arr[],int lb,int ub) {
    int pivot,p,q;
    pivot= arr[lb];
    p=lb+1;
    q=ub;

    while(p<q) {

while (arr[p]<pivot) {
    p++;
}
        while (arr[q]>pivot) {
            q--;
        }

            if(p<q) {
                int temp=arr[p];
                arr[p]=arr[q];
                arr[q]=temp;
            }


    }

    int temp2=arr[lb];
    arr[lb]=arr[q];
    arr[q]=temp2;

    return q;
}



void quick_sort(int arr[],int lb,int ub) {
    if(ub>lb) {

        int s=split(arr,lb,ub);
        quick_sort(arr,lb,s-1);
        quick_sort(arr,s+1,ub);

    }

}

int main() {
    int arr[]={9,1,2,7,5};
    int n= sizeof(arr)/sizeof(arr[0]);

    printf("the array is: \n");
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]);

    }

    quick_sort(arr,0,n-1);

    printf("the sorted array is : \n");
    for (int i=0;i<n;i++) {
        printf("%d ",arr[i]);
    }

    

}
