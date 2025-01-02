#include <stdio.h>
#include <stdlib.h>

struct Process {
    int pid, AT, BT, ET, TAT, WT;
};

int compareByArrival(const void *a, const void *b) {
    return ((struct Process *)a)->AT - ((struct Process *)b)->AT;
}

int compareByBurst(const void *a, const void *b) {
    return ((struct Process *)a)->BT - ((struct Process *)b)->BT;
}

int compareByPid(const void *a, const void *b) {
    return ((struct Process *)a)->pid - ((struct Process *)b)->pid;
}

void calculateSJF(struct Process p[], int n) {
    int time = 0, completed = 0;
    while (completed < n) {
        qsort(p, n, sizeof(struct Process), compareByBurst);

        int i;
        for (i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].ET == 0) {
                p[i].ET = time + p[i].BT;
                p[i].TAT = p[i].ET - p[i].AT;
                p[i].WT = p[i].TAT - p[i].BT;
                time = p[i].ET;
                completed++;
                break;
            }
        }
        if (i == n) {
            time++; // increment time if no process is ready
        }
    }
}

void display(struct Process p[], int n) {
    qsort(p, n, sizeof(struct Process), compareByPid);

    printf("\nPID\tAT\tBT\tET\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].AT, p[i].BT, p[i].ET, p[i].TAT, p[i].WT);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT and BT for process %d: ", i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].ET = 0;
    }

    qsort(p, n, sizeof(struct Process), compareByArrival);
    calculateSJF(p, n);
    display(p, n);

    return 0;
}
