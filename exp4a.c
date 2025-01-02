#include <stdio.h>
#include <limits.h>

struct Process {
    int pid, arrival, burst, remaining, completion, turnaround, waiting;
};

void calculateTimes(struct Process proc[], int n) {
    int complete = 0, time = 0, minTime = INT_MAX, shortest = -1;
    
    while (complete != n) {
        // Find the process with the minimum remaining burst time
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival <= time && proc[i].remaining > 0 && proc[i].remaining < minTime) {
                minTime = proc[i].remaining;
                shortest = i;
            }
        }

        // If no process can be executed at this time, increment time
        if (shortest == -1) {
            time++;
            continue;
        }

        // Execute the shortest process
        proc[shortest].remaining--;
        minTime = proc[shortest].remaining ? proc[shortest].remaining : INT_MAX;

        // If the process is completed
        if (proc[shortest].remaining == 0) {
            complete++;
            proc[shortest].completion = time + 1;
            proc[shortest].turnaround = proc[shortest].completion - proc[shortest].arrival;
            proc[shortest].waiting = proc[shortest].turnaround - proc[shortest].burst;
        }

        time++;
    }
}

void printProcesses(struct Process proc[], int n) {
    printf("\n\nPID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].arrival, proc[i].burst,
                proc[i].completion, proc[i].turnaround, proc[i].waiting);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival and burst time for process %d: ", i + 1);
        scanf("%d%d", &proc[i].arrival, &proc[i].burst);
        proc[i].pid = i + 1;
        proc[i].remaining = proc[i].burst;
    }

    calculateTimes(proc, n);
    printProcesses(proc, n);
    return 0;
}
