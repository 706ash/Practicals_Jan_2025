#include <iostream>
using namespace std;

int main() {
	int n, hs, flag, total = 0;

	// Input: Number of cylinders
	cout << "Enter the number of cylinders: ";
	cin >> n;

	int c[n], hm[n];  // Arrays to store cylinder numbers and head movements

	// Input: Cylinder numbers
	cout << "Enter the cylinder numbers: ";
	for (int i = 0; i < n; i++) {
    	cin >> c[i];
	}

	// Input: Head start position
	cout << "Enter the head start: ";
	cin >> hs;

	flag = hs;  // Initialize flag with head start position

	// Calculate head movements for each cylinder
	for (int i = 0; i < n; i++) {
    	if (c[i] > flag) {
        	hm[i] = c[i] - flag;
    	} else {
        	hm[i] = flag - c[i];
    	}
    	flag = c[i];  // Update flag to the current cylinder

    	cout << "Position: " << hm[i] << endl;
	}

	// Calculate the total head movement
	for (int i = 0; i < n; i++) {
    	total += hm[i];
	}

	// Output: Total cylinders traversed during disk movement
	cout << "The total number of cylinders traversed during disk movement is: " << total << endl;

	return 0;
}
