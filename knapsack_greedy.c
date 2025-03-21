#include <stdio.h>

void b_sort(float ratio[], int W[], int profit[], int items[], int n) {
    float tempR;
    int tempW, tempP, tempI;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {

                tempR = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempR;


                tempW = W[j];
                W[j] = W[j + 1];
                W[j + 1] = tempW;


                tempP = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = tempP;


                tempI = items[j];
                items[j] = items[j + 1];
                items[j + 1] = tempI;
            }
        }
    }
}


void print_ratio(float arr[], int n) {
    printf("\nsorted ratios:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}


void print_sorted_items(int items[], int W[], int profit[], int n) {
    printf("\nsorted items:\n");
    for (int i = 0; i < n; i++) {
        printf("item %d: weight = %d, profit = %d\n", items[i], W[i], profit[i]);
    }
}

int main() {
    int M= 5;
    int items[] = {1, 2, 3, 4, 5};
    int W[] = {3, 3, 2, 5, 1};
    int profit[] = {10, 15, 10, 20, 8};
    float ratio[5];
    int n = 5;


    for (int i = 0; i < n; i++) {
        ratio[i] = (float)profit[i] / W[i];
    }


    printf("initial Ratios:\n");
    for (int i = 0; i < n; i++) {
        printf(" item %d: ratio = %.2f\n", items[i], ratio[i]);
    }

    b_sort(ratio, W, profit, items, n);
    print_ratio(ratio, n);
    print_sorted_items(items, W, profit, n);

    float total_profit=0.0;
    for(int i=0;i<n;i++) {
       if(M>0 && W[i]<=M) {
           M=M-W[i];
          total_profit+=profit[i];
       }
        else {
            total_profit+= ratio[i] * M;
            break;
        }

    }
    printf("%.2f",total_profit);
}


/*initial Ratios:
 item 1: ratio = 3.33
 item 2: ratio = 5.00
 item 3: ratio = 5.00
 item 4: ratio = 4.00
 item 5: ratio = 8.00

sorted ratios:
8.00 5.00 5.00 4.00 3.33

sorted items:
item 5: weight = 1, profit = 8
item 2: weight = 3, profit = 15
item 3: weight = 2, profit = 10
item 4: weight = 5, profit = 20
item 1: weight = 3, profit = 10
28.00*/







