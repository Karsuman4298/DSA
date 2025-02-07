#include<stdio.h>

int main() {
    int n;
    printf("enter the number\n");
    scanf("%d",&n);

    if(n%7==0 || n%10==7) {
        printf("%d is the buzz number\n",n);
    }
    else {
        printf("%d is not a buzz nnumber",n);
    }
}
