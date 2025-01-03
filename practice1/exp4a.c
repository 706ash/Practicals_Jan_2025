#include <stdio.h>
#include <limits.h>

struct process
{
    int pid ,AT, BT, remaining_time, CT, TAT, WT;
};

void calculate(struct process p[], int n)
{
    int complete = 0,  mintime = INT_MAX, shortest = -1, time = 0;
    while (complete != n)
    {
        for (int i = 0; i < n; i++)
        {
            if(p[i].AT <= time && p[i].remaining_time > 0 && p[i].remaining_time < mintime)
            {
                mintime = p[i].remaining_time;
                shortest = i;
            }
        }
        if(shortest == -1)
        {
            time++;
            continue;
        }

        p[shortest].remaining_time--;
        mintime = p[shortest].remaining_time ? p[shortest].remaining_time : INT_MAX;

        if(p[shortest].remaining_time == 0)
        {
            p[shortest].CT = time + 1;
            p[shortest].TAT = p[shortest].CT - p[shortest].AT;
            p[shortest].WT = p[shortest].TAT - p[shortest].BT;
            complete++;
        }
        time++;
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
        int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter AT and BT for process %d: ", i + 1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].remaining_time = p[i].BT;
    }

    calculate(p, n);

    display(p, n);

    return 0;
}