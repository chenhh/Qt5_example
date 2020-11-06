#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex g_display_mutex;

void show()
{
    thread::id this_id = this_thread::get_id();

    g_display_mutex.lock();
    cout<<"hello wolrd "<<this_id<<endl;
    g_display_mutex.unlock();
}


int main()
{
    thread t1(show);
    thread t2(show);

    t1.join();
    t2.join();
    return 0;
}
