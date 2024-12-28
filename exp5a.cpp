#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class MyRunnableThread {
public:
    static int myCount;
    void operator()() {
        while (MyRunnableThread::myCount <= 10) {
            cout << "\nOther Thread: " << ++MyRunnableThread::myCount << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
    }
};

int MyRunnableThread::myCount = 0;

int main() {
    cout << "Starting Main Thread..." << endl;
    
    MyRunnableThread mrt;
    thread t(mrt);
    
    while (MyRunnableThread::myCount <= 10) {
        cout << "\nMain Thread: " << ++MyRunnableThread::myCount << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }
    
    t.join(); // Wait for the secondary thread to finish
    cout << "End of Main Thread..." << endl;
    
    return 0;
}
