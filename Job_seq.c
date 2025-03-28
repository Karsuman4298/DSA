#include <stdio.h>

void jobSequencing(int n, char jobId[], int deadline[], int profit[]) {
    int i, j;
    int maxDeadline = 0;


    for (i = 0; i < n; i++) {
        if (deadline[i] > maxDeadline)
            maxDeadline = deadline[i];
    }


    int slot[maxDeadline];
    char result[maxDeadline];

    for (i = 0; i < maxDeadline; i++)
        slot[i] = 0;

    int totalProfit = 0;

    for (i = 0; i < n; i++) {

        for (j = deadline[i] - 1; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                result[j] = jobId[i];
                totalProfit += profit[i];
                break;
            }
        }
    }

    printf("Scheduled Jobs: ");
    for (i = 0; i < maxDeadline; i++) {
        if (slot[i])
            printf("%c ", result[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);
}

int main() {
    char jobId[] = {'A', 'B', 'C', 'D', 'E'};
    int deadline[] = {2, 1, 2, 1, 3};
    int profit[] = {100, 19, 27, 25, 15};
    int n = sizeof(jobId) / sizeof(jobId[0]);

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (profit[j] < profit[j+1]) {

                int temp = profit[j];
                profit[j] = profit[j+1];
                profit[j+1] = temp;

                temp = deadline[j];
                deadline[j] = deadline[j+1];
                deadline[j+1] = temp;

                char c = jobId[j];
                jobId[j] = jobId[j+1];
                jobId[j+1] = c;
            }
        }
    }

    jobSequencing(n, jobId, deadline, profit);

}
