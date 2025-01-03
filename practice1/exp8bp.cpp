#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void SSTF(int req[], int head, int n)
{
    bool accessed[n] = {};
    int seekcount = 0, seq[n+1], sidx = 0;
    seq[sidx++] = head;
    for (int count = 0; count < n; count++)
    {
        int idx = -1, minDist = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if(!accessed[i] && abs(req[i]-head) < minDist)
            {
                minDist = abs(req[i]- head);
                idx = i;
            }
        }
        seekcount += minDist;
        head = req[idx];
        seq[sidx++] = head;
        accessed[idx] = true;
    }
    cout<<"\nSeek count: "<<seekcount;
    cout<<"\nseek sequence: ";
    for (int i = 0; i < sidx; i++)
    {
        cout<<seq[i]<<endl;
    }
    
}
int main(){
    int n;
    cout<<endl<<"Enter number of requests: ";
    cin>>n;
    int req[n], head;
    cout<<"\nEnter the reqquests array: ";
    for (int i = 0; i < n; i++)
    {
        cin>>req[i];
    }
    
    cout<<"\nEnter the initial head position: ";
    cin>>head;
    SSTF(req, head, n);
}