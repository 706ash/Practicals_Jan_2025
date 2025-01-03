#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class MySmpThread : public thread{
    public:
        static int myCount;
    
    void run(){
        while(MySmpThread::myCount <= 10)
        {
            cout<<endl<<"Other Thread: "<<++MySmpThread::myCount;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    void start()
    {
        thread t(&MySmpThread::run, this);
        t.detach();
    }
};

int MySmpThread::myCount = 0;

int main(){
    cout<<endl<<"Starting main Thread...";
    MySmpThread mrt;
    mrt.start();

    while(MySmpThread::myCount <= 10)
    {
        cout<<endl<<"Main Thread: "<<++MySmpThread::myCount;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    cout<<endl<<"End of Main Thread...";
    this_thread::sleep_for(chrono::milliseconds(500));

    return 0;
}