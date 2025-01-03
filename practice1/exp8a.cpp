#include <iostream>
using namespace std;

int main(){
    int hs, flag, n, total = 0;
    cout<<"\nEnter the number of cylinders: ";
    cin>>n;

    int c[n], hm[n];
    cout<<"\nEnter the cylinder numbers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    cout<<"\nEnter the head start pos: ";
    cin>>hs;

    flag = hs;

    for (int i = 0; i < n; i++)
    {
        if(c[i] > flag)
        {
            hm[i] = c[i] - flag;
        }
        else{
            hm[i] = flag - c[i];
        }
        flag = c[i];

        cout<<"\nPosition: "<<hm[i];
    }

    for (int i = 0; i < n; i++)
    {
        total+=hm[i];
    }
    
    cout<<"\nTotal head movement: "<<total;

    return 0;   
}