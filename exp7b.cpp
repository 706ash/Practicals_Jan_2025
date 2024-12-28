#include <iostream>
#include <deque>
#include <vector> // Use deque for better performance with front removals
using namespace std;

int r_size;
int frame_size;
deque<int> frame;
vector<int> references;
int hit = 0;
int miss = 0;

int main() {
    cout << "Enter Number of Frame Size: ";
    cin >> frame_size;

    cout << "Enter Number of references: ";
    cin >> r_size;

    references.resize(r_size);
    for (int i = 0; i < r_size; i++) {
        cout << "Enter Reference " << i + 1 << ": ";
        cin >> references[i];
    }

    cout << "Least Recently Used (LRU) Page Replacement\n";
    for (int i = 0; i < r_size; i++) {
        int current = references[i];
        bool found = false;

        // Check if the current page is already in the frame
        for (int j = 0; j < frame.size(); j++) {
            if (frame[j] == current) {
                found = true;

                // Move the current page to the most recently used position
                frame.erase(frame.begin() + j);
                frame.push_back(current);
                break;
            }
        }

        if (found) {
            hit++;
        } else {
            miss++;

            // If the frame is full, remove the least recently used page
            if (frame.size() == frame_size) {
                frame.pop_front();
            }

            // Add the new page to the frame
            frame.push_back(current);
        }
    }

    cout << "Total Hits: " << hit << "\n";
    cout << "Total Faults: " << miss << "\n";
    return 0;
}
