#include <stdio.h>
#include <stdlib.h>

struct process
{
    int pid, AT, BT, ET, TAT, WT;
};

int comparebyarrival(const void *a, const void *b)
{
    return ((struct process *)a)->AT - ((struct process *)b)->AT; 
}

int comparebypid(const void *a, const void *b) 
{
    return ((struct process *)a)->pid - ((struct process *)b)->pid; 
}

int comparebyburst(const void *a, const void *b) 
{
    return ((struct process *)a)->BT - ((struct process *)b)->BT; 
}

void calculate(struct process p[], int n)
{
    int time =0, completed = 0;
    while (completed < n)
    {
        qsort(p, n, sizeof(struct process), comparebyburst);
        int i;
        for (i = 0; i < n; i++)
        {
            if(p[i].AT <= time && p[i].ET == 0)
            {
                p[i].ET = time + p[i].BT;
                p[i].TAT = p[i].ET - p[i].AT;
                p[i].WT = p[i].TAT - p[i].BT;        
                completed++;
                time = p[i].ET;
                break;
            }
        }
        if(i == n)
        {
            time++;     
        }
    }
    
}

void display(struct process p[], int n)
{
    qsort(p, n, sizeof(struct process), comparebypid);
    printf("\n\nPID\tAT\tBT\tET\tTAT\tWT");
    for (int i = 0; i < n; i++)
    {
        printf("\n%d\t%d\t%d\t%d\t%d\t%d", p[i].pid, p[i].AT,p[i].BT, p[i].ET, p[i].TAT, p[i].WT);
    }
    
}

int main()
{
    int n;
    printf("\nEnter the no of processes: ");
    scanf("%d", &n);
    
    struct process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i+1;
        printf("\nEnter the AT and BT of process %d: ", i+1);
        scanf("%d%d", &p[i].AT, &p[i].BT);
        p[i].ET = 0; //had forgotten this
    }

    qsort(p, n, sizeof(struct process), comparebyarrival);

    calculate(p, n);

    display(p, n);
    

    return 0;

}