#include <iostream>
using namespace std;

struct BankersAlgo {
    static const int MAX_PROCESSES = 10;
    static const int MAX_RESOURCES = 10;

    int need[MAX_PROCESSES][MAX_RESOURCES];
    int allocate[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int avail[MAX_RESOURCES];
    int np, nr;

    void input() {
        cout << "Enter no. of processes and resources: ";
        cin >> np >> nr;

        cout << "Enter allocation matrix:\n";
        for (int i = 0; i < np; i++)
            for (int j = 0; j < nr; j++)
                cin >> allocate[i][j];

        cout << "Enter max matrix:\n";
        for (int i = 0; i < np; i++)
            for (int j = 0; j < nr; j++)
                cin >> max[i][j];

        cout << "Enter available resources:\n";
        for (int j = 0; j < nr; j++)
            cin >> avail[j];
    }

    void calc_need() {
        for (int i = 0; i < np; i++)
            for (int j = 0; j < nr; j++)
                need[i][j] = max[i][j] - allocate[i][j];
    }

    bool can_allocate(int i) {
        for (int j = 0; j < nr; j++)
            if (avail[j] < need[i][j])
                return false;
        return true;
    }

    void isSafe() {
        input();
        calc_need();

        bool done[MAX_PROCESSES] = {false};
        int count = 0;

        while (count < np) {
            bool allocated = false;
            for (int i = 0; i < np; i++) {
                if (!done[i] && can_allocate(i)) {
                    for (int j = 0; j < nr; j++)
                        avail[j] += allocate[i][j];
                    cout << "Allocated process: " << i << endl;
                    done[i] = true;
                    allocated = true;
                    count++;
                }
            }
            if (!allocated) break;
        }

        cout << (count == np ? "\nSafely allocated" : "All processes can't be allocated safely") << endl;
    }
};

int main() {
    BankersAlgo b;
    b.isSafe();
    return 0;
}
