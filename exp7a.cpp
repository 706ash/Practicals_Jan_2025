#include <iostream>
#include <vector>
using namespace std;

int r_size;
int frame_size;
vector<int> frame;
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

    cout << "First Come First Serve\n";
    for (int i = 0; i < r_size; i++) {
        int current = references[i];
        bool found = false;

        // Check if the current page is already in the frame
        for (int j = 0; j < frame.size(); j++) {
            if (frame[j] == current) {
                found = true;
                break;
            }
        }

        if (found) {
            hit++;
        } else {
            miss++;
            if (frame.size() == frame_size) {
                // Remove the oldest page (first in the frame)
                frame.erase(frame.begin());
            }
            // Add the current page to the frame
            frame.push_back(current);
        }
    }

    cout << "Total Hits: " << hit << "\n";
    cout << "Total Faults: " << miss << "\n";

    return 0;
}
