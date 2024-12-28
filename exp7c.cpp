#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    cout << "Enter Number of References: ";
    cin >> r_size;

    references.resize(r_size);

    for (int i = 0; i < r_size; i++) {
        cout << "Enter Reference " << i + 1 << ": ";
        cin >> references[i];
    }

    cout << "Optimal Page Replacement\n";

    for (int i = 0; i < r_size; i++) {
        int current = references[i];

        // Check if the current page is already in the frame
        auto it = find(frame.begin(), frame.end(), current);
        if (it != frame.end()) {
            hit++;
        } else {
            miss++;

            // If the frame is full, find a page to replace
            if (frame.size() == frame_size) {
                int index_to_replace = -1;
                int farthest = -1;

                for (int j = 0; j < frame.size(); j++) {
                    int next_use = INT_MAX;

                    // Find the next use of the current frame page
                    for (int k = i + 1; k < r_size; k++) {
                        if (frame[j] == references[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    // Update the page to replace if this page is used farther in the future
                    if (next_use > farthest) {
                        farthest = next_use;
                        index_to_replace = j;
                    }
                }

                // Replace the page
                frame[index_to_replace] = current;
            } else {
                // Add the current page if there's space in the frame
                frame.push_back(current);
            }
        }
    }

    cout << "Total Hits: " << hit << "\n";
    cout << "Total Faults: " << miss << "\n";

    return 0;
}
