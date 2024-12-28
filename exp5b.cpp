#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class MySmpThread : public thread {
public:
    static int myCount;

    void run() {
        while (MySmpThread::myCount <= 10) {
            cout << "Expt Thread: " << ++MySmpThread::myCount << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    void start() {
        thread t(&MySmpThread::run, this);
        t.detach();
    }
};

int MySmpThread::myCount = 0;

int main() {
    cout << "Starting Main Thread..." << endl;
    
    MySmpThread mst;
    mst.start();
    
    while (MySmpThread::myCount <= 10) {
        cout << "Main Thread: " << ++MySmpThread::myCount << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout << "End of Main Thread..." << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    
    return 0;
}
