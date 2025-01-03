#include <iostream>
using namespace std;

struct Bankers{
    static const int MAX_PROCESSES = 10;
    static const int MAX_RESOURCES = 10;
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocated[MAX_PROCESSES][MAX_RESOURCES]; 
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];
    int np, nr;

    void input()
    {
        cout<<"\nEnter the no of processes and resources: ";
        cin>>np>>nr;

        cout<<"\nEnter the allocation matrix:";
        for (int i = 0; i < np; i++)
        {
            for (int j = 0; j < nr; j++)
            {
                cin>>allocated[i][j];                
            }
        }

        cout<<"\nEnter the max matrix:";
        for (int i = 0; i < np; i++)
        {
            for (int j = 0; j< nr; j++)
            {
                cin>>max[i][j];                
            }
        }
        cout<<"\nEnter the available vector:";
        for (int j = 0; j < nr; j++)
        {
            cin>>available[j];
        }
    }

    void cal_need()
    {
        for (int i = 0; i < np; i++)
        {
            for (int j = 0; j < nr; j++)
            {
                need[i][j] = max[i][j] - allocated[i][j];
            }
        }
    }

    bool can_allocate(int i)
    {
        for (int j = 0; j < nr; j++)
        {
            if(available[j] < need[i][j])
            {
                return false;
            }
        }
        return true;        
    } 

    void isSafe()
    {
        input();
        cal_need();

        bool done[MAX_PROCESSES] ={false};
        int cp = 0;

        while (cp < np)
        {
            bool allocate = false;
            for (int i = 0; i < np; i++)
            {
                if(!done[i] && can_allocate(i))
                {
                    for (int j = 0; j < nr; j++)
                    {
                        available[j] += allocated[i][j];
                    }
                    cout<<"\nAllocated process "<<i+1;
                    allocate = true;
                    done[i] = true;
                    cp++;
                }
            }
            if(!allocate)
            {
                break;
            }
        }

        (cp == np) ? "\nSafely allocated" : "\nCannot be safely allocated";        
    }

};

int main()
{
    Bankers b;
    b.isSafe();
    return 0;
}
