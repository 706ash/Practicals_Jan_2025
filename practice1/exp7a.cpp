#include <iostream>
#include <vector>
using namespace std;

int r_size, f_size, hit = 0, miss = 0;
vector<int>frame;
vector<int>references;

int main(){
    cout<<endl<<"Enter the no of referneces and frame size: ";
    cin>>r_size>>f_size;

    references.resize(r_size);
    for (int i = 0; i < r_size; i++)
    {
        cout<<"\nEnter the reference "<<i+1<<": ";
        cin>>references[i];
    }

    for (int i = 0; i < r_size; i++)
    {
        bool found = false;
        int current = references[i];
        for (int j = 0; j < frame.size(); j++)
        {
            if(frame[j] == current)
            {
                found = true;
                break;
            }
        }
        
        if(found){
            hit++;
        }
        else{
            miss++;
            if(frame.size() == f_size)
            {
                frame.erase(frame.begin());
            }
            frame.push_back(current);
        }
    }

    cout<<endl<<"Total hits: "<<hit;
    cout<<endl<<"Total faults: "<<miss;
    
    return 0;   
}