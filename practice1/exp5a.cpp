#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
class MyRunnableThread{
    public:
        static int myCount;
    
    void operator()(){
        while(MyRunnableThread::myCount <= 10)
        {
            cout<<endl<<"Other Thread: "<<++MyRunnableThread::myCount;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }
};

int MyRunnableThread::myCount = 0;

int main()
{
    cout<<endl<<"Starting Main thread...";
    MyRunnableThread mrt;
    thread t(mrt);

    while(MyRunnableThread::myCount <= 10)
    {
        cout<<endl<<"Main Thread: "<<++MyRunnableThread::myCount;
        this_thread::sleep_for(chrono::milliseconds(100));
    }

    t.join();
    cout<<"\nEnd of Main Thread...";
}