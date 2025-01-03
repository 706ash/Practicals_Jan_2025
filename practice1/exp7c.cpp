#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int r_size, f_size, hit = 0, miss = 0;
vector<int> frame;
vector<int> references;

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
        int current = references[i];
        auto it = find(frame.begin(), frame.end(), current);
        
        if(it != frame.end()){
            hit++;
        }
        else{
            miss++;
            if(frame.size() == f_size)
            {
                int index_to_replace = -1, farthest = -1;
                for (int j = 0; j < frame.size(); j++)
                {
                    int next_use = INT_MAX;
                    for (int k = i+1; k < r_size; k++)
                    {
                        if(frame[j] == references[k])
                        {
                            next_use = k;
                            break;
                        }
                    }
                    if(next_use > farthest)
                    {
                        farthest = next_use;
                        index_to_replace = j;
                    }
                }
                frame[index_to_replace] = current;
            }
            else{
            frame.push_back(current);
            }
        }
    }

    cout<<endl<<"Total hits: "<<hit;
    cout<<endl<<"Total faults: "<<miss;
    
    return 0;   
}