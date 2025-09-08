#include <stdio.h>
struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Arrival Time of P%d: ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("Enter Burst Time of P%d: ", p[i].pid);
        scanf("%d", &p[i].bt);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int time = 0;
    float avgTAT = 0, avgWT = 0;

    for (int i = 0; i < n; i++) {
        if (time < p[i].at) {
            time = p[i].at;
        }
        p[i].ct = time + p[i].bt;
        time = p[i].ct;

        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        avgTAT += p[i].tat;
        avgWT += p[i].wt;
    }


    printf("\n------------------------------------------------------------\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("------------------------------------------------------------\n");

    printf("Average Turnaround Time = %.2f\n", avgTAT / n);
    printf("Average Waiting Time = %.2f\n", avgWT / n);


    printf("\nGantt Chart:\n|");
    for (int i = 0; i < n; i++) {
        printf("  P%d  |", p[i].pid);
    }
    printf("\n0");
    for (int i = 0; i < n; i++) {
        printf("   %d   ", p[i].ct);
    }
    printf("\n");

    return 0;
}

