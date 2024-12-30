#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int findClosest(int req[], bool accessed[], int head, int n) {
	int minDist = INT_MAX, idx = -1;
	for (int i = 0; i < n; i++)
    	if (!accessed[i] && abs(req[i] - head) < minDist)
        	minDist = abs(req[i] - head), idx = i;
	return idx;
}

void SSTF(int req[], int head, int n) {
	bool accessed[n] = {false};
	int seekCount = 0, seq[n + 1];
	seq[0] = head;

	for (int i = 0; i < n; i++) {
    	int idx = findClosest(req, accessed, head, n);
    	seekCount += abs(req[idx] - head);
    	head = req[idx], accessed[idx] = true;
    	seq[i + 1] = head;
	}

	cout << "Total seek operations: " << seekCount << "\nSeek sequence: ";
	for (int i = 0; i <= n; i++) cout << seq[i] << " ";
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
