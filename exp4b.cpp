#include <stdio.h>

int main() {
    int n, i, qt, time = 0, completed = 0;
    printf("\nEnter the number of processes and the time quantum: ");
    scanf("%d%d", &n, &qt);
    
    int arrival_time[n], burst_time[n], remaining_time[n], waiting_time[n], turnaround_time[n], completion_time[n];

    // Taking input for arrival and burst time of processes
    for (i = 0; i < n; i++) {
        printf("\nEnter the arrival and burst time of process %d: ", i + 1);
        scanf("%d%d", &arrival_time[i], &burst_time[i]);
        remaining_time[i] = burst_time[i];  // Copy burst time to remaining time
    }

    // Round Robin scheduling logic
    while (completed < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && arrival_time[i] <= time) {
                found = 1; // A process is ready to execute
                if (remaining_time[i] > qt) {
                    time += qt;
                    remaining_time[i] -= qt;
                } else {
                    time += remaining_time[i];
                    turnaround_time[i] = time - arrival_time[i];
                    waiting_time[i] = time - burst_time[i] - arrival_time[i];
                    completion_time[i] = time;
                    remaining_time[i] = 0;
                    completed++; // Process is completed
                }
            }
        }
        if (!found) {
            // If no process is ready, move time forward to the next arrival
            time++;
        }
    }

    // Display results
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, arrival_time[i], burst_time[i], completion_time[i], waiting_time[i], turnaround_time[i]);
    }

    return 0;
}
