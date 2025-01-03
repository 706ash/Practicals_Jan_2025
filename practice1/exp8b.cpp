#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

void SSTF(int req[], int head, int n) {
    bool accessed[n] = {};
    int seekCount = 0, seq[n + 1], seqIdx = 0;

    seq[seqIdx++] = head;
    for (int count = 0; count < n; count++) {
        int minDist = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++) {
            if (!accessed[i] && abs(req[i] - head) < minDist) {
                minDist = abs(req[i] - head);
                idx = i;
            }
        }
        seekCount += minDist;
        head = req[idx];
        accessed[idx] = true;
        seq[seqIdx++] = head;
    }

    cout << "Total seek operations: " << seekCount << "\nSeek sequence: ";
    for (int i = 0; i < seqIdx; i++) cout << seq[i] << " ";
    cout << endl;
}

int main() {
    int n, head;
    cout << "Enter the number of requests: ";
    cin >> n;
    int req[n];
    cout << "Enter the request array: ";
    for (int i = 0; i < n; i++) cin >> req[i];
    cout << "Enter the initial head position: ";
    cin >> head;
    SSTF(req, head, n);
    return 0;
}
