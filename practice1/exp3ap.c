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

void calculate(struct process p[], int n)
{
    int time =0;
    for (int i = 0; i < n; i++)
    {
        if(time < p[i].AT){
            time = p[i].AT;
        }
        
        p[i].ET = time + p[i].BT;
        p[i].TAT = p[i].ET - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;        
        time = p[i].ET;
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
    }

    qsort(p, n, sizeof(struct process), comparebyarrival);

    calculate(p, n);

    display(p, n);
    

    return 0;

}