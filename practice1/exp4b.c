#include <stdio.h>
#include <limits.h>

struct process
{
    int pid ,AT, BT, remaining_time, CT, TAT, WT;
};

void calculate(struct process p[], int n, int qt)
{
    int complete = 0, time = 0, found;
    while (complete != n)
    {
        found = 0;
        for (int i = 0; i < n; i++)
        {
            if(p[i].AT <= time && p[i].remaining_time > 0)
            {
                found = 1;
                if(p[i].remaining_time > qt)
                {
                    time += qt;
                    p[i].remaining_time-=qt;
                }
                else{
                    time += p[i].remaining_time;
                    p[i].CT = time;
                    p[i].TAT = p[i].CT - p[i].AT;
                    p[i].WT = p[i].TAT - p[i].BT;
                    p[i].remaining_time = 0;
                    complete++;
                }
            }
        }
        if(!found)
        {
            time++;
        }
    }
}

void display(struct process p[], int n)
{
    printf("\n\nPID\tAT\tBT\tET\tTAT\tWT");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i].pid, p[i].AT,p[i].BT, p[i].CT, p[i].TAT, p[i].WT);
    }
    printf("\n");
}

int main()
{
    int n, qt;
    printf("Enter number of processes and time quantum: ");
    scanf("%d%d", &n, &qt);

    struct process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT and BT for process %d: ", i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].remaining_time = p[i].BT;
    }

    calculate(p, n, qt);

    display(p, n);

    return 0;
}