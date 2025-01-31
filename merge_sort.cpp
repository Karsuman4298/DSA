#include<stdio.h>
#include<algorithm>
using namespace std;

void merge(int a[],int b[],int lb,int mid ,int ub) {
    int i= lb;
    int k= mid+1;
    int l= lb;
    int j=ub;

    while(i<=mid && k<=ub) {
        if(a[i]<a[k]) {
            b[l++]= a[i++];

        }
        else {
            b[l++]=a[k++];

        }
    }

        while(k<=j) {
            b[l++]=a[k++];
        }


        while(i<=mid) {
            b[l++]=a[i++];
        }
    
   for(int k=lb;k<=ub;k++) {
        a[k]=b[k];

    }
}


void merge_sort(int a[],int b[],int lb,int ub) {
if(ub>lb) {
    int mid= (lb+ub)/2;

    merge_sort(a,b,lb,mid);
    merge_sort(a,b,mid+1,ub);

    merge(a,b,lb,mid,ub);
}
}


int main() {

    int a []={2,1,8,5,0,4};
    int n = sizeof(a)/sizeof(a[0]);
    int b[n];

printf("the array is :");
    for (int i=0;i<n;i++) {
        printf("%d ",a[i]);

    }
    printf("\n");
    merge_sort(a,b,0,n-1);


        printf("the sorted array is :");
        for (int i=0;i<n;i++) {
            printf("%d ",a[i]);
        }
    }
