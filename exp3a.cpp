#include <stdio.h>
#include <stdlib.h>
struct Process {
    int pid, AT, BT, ET, TAT, WT;
};

int compareByArrival(const void *a, const void *b) {
    return ((struct Process *)a)->AT - ((struct Process *)b)->AT;
}

int compareByPid(const void *a, const void *b) {
    return ((struct Process *)a)->pid - ((struct Process *)b)->pid;
}

void calculate(struct Process p[], int n) {
    int time = 0;
    printf("\n\n|%d", time);
    for (int i = 0; i < n; i++) {
        if(time < p[i].AT) 
        {
            time = p[i].AT;
            printf("  %d|",time);
        } 
        
        p[i].ET = time + p[i].BT;
        printf(" P%d %d|",p[i].pid,p[i].ET);
        p[i].TAT = p[i].ET - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
        time = p[i].ET;
    }
    printf("\n\n");
}

void display(struct Process p[], int n) {
    qsort(p, n, sizeof(struct Process), compareByPid);
    printf("\nPID\tET\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].ET, p[i].TAT, p[i].WT);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT and BT of process %d: ", i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
    }
    qsort(p, n, sizeof(struct Process), compareByArrival);
    calculate(p, n);
    display(p, n);

    return 0;
}
